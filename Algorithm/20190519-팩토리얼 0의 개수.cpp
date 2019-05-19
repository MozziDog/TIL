//백준 1676번 문제
//N!의 뒤에서 0이 아닌 숫자가 나올때까지의 0의 개수
//N! = (자연수)* 10^k 라고 할 때 k의 최대값

//정답


#include<iostream>

int main()
{
    int N, tmp;
    int x2=0, x5=0;
    scanf("%d", &N);
    for(int i=1; i<=N; i++)
    {
        tmp=i;
        while(true)
        {
            if(tmp%2==0)
            {
                tmp = tmp/=2;
                x2++;
            }
            else
            {
                break;
            }
        }
        tmp=i;
        while(true)
        {
            if(tmp%5==0)
            {
                tmp = tmp/=5;
                x5++;
            }
            else
            {
                break;
            }
        }
    }
    int answer = x2<x5? x2: x5;
    printf("%d", answer);
    return 0;
}