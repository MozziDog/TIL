//백준 2747번 문제
//피보나치 수

//너무 간단

//백준 2748번 문제
//90번째 피보나치 수까지 구하기 위해선 int의 범위로는 부족함.
//화끈하게 long long형으로 변경

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
    }
    printf("%lld\n", now);
    return 0;
}