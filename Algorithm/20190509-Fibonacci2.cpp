//백준 2794번 문제
//피보나치 수 3

//n번째 피보나치 수를 1000000으로 나눈 나머지를 계산
//행렬 곱셈을 사용?

/*1차 시도
#include <iostream>

int main()
{
    int n;
    unsigned long long now=1, before=0, temp;
    scanf("%d", &n);
    if(n==0)
    {
        printf("0\n");
        return 0;
    }
    for(int i=0; i<n-1; i++)
    {
        temp = now+before;
        before=now;
        now = temp;
        if(now>=1000000)
        {
            now-=1000000;
        }
    }
    printf("%lld\n", now);
    return 0;
}
*/ 틀림
