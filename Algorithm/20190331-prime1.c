//백준 1978번 문제
//주어진 수 중 소수의 개수 구하기

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isPrime(int);

int main(void)
{
    int size;
    scanf("%d", &size);
    int* num = malloc(size*sizeof(int));
    for(int i=0; i<size; i++)
    {
        scanf("%d", &num[i]);
    }
    int answer = 0;
    for(int i=0; i<size; i++)
    {
        if(isPrime(num[i])==1)
        {
            answer++;
        }
    }
    printf("%d", answer);
}

//소수면 1을, 아니면 0을 리턴하는 함수
int isPrime(int num)
{
    if(num <= 1)
    {
        return 0;
    }
    int limit=(int)sqrt(num);
    for(int i=2; i<=limit; i++)
    {
        if(num%i == 0)
        {
            return 0;
        }
    }
    return 1;
}