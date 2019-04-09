//백준 1929번 문제
//소수구하기-에라토스테네스의 체

//실수: 0과 1이 소수가 아님을 체크하지 않음

//성공

#include <stdio.h>

int list[1000001]= {1, 1};

int main()
{
    int min, max;
    scanf("%d %d", &min, &max);
    for(int i=2; i<=1000001; i++)
    {
        if(list[i]==0)
        {
            for(int j=2*i; j<=1000001; j+=i)
            {
                list[j]=1;
            }
        }
    }
    for(int i=min; i<=max; i++)
    {
        if(list[i]==0)
        {
            printf("%d\n", i);
        }
    }

    return 0;
}