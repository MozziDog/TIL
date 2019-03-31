//백준 2581번 문제
//주어진 범위 내 소수의 개수와 가장 작은 소수 구하기

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isPrime(int);

int main(void)
{
    int min, max;
    scanf("%d", &min);
    scanf("%d", &max);
    int sumPrime = 0;
    int minPrime = 0;
    for(int i=min; i<=max; i++)
    {
        if(isPrime(i)==1)
        {
            sumPrime+=i;
            if(minPrime == 0)
            {
                minPrime = i;
            }
        }
    }
    if(sumPrime == 0)
        printf("-1");
    else
    {
        printf("%d\n%d", sumPrime, minPrime);
    }
    return 0;
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