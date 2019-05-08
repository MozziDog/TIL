//백준 2747번 문제
//피보나치 수

//너무 간단

#include <iostream>

int main()
{
    int n;
    int now=1, before=0, temp;
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
    printf("%d\n", now);
    return 0;
}