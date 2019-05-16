//백준 11051번 문제
//이항 계수 2

//C(N, K)를 10007로 나눈 나머지를 구하기


#include<iostream>

int main()
{
    int N, K;
    scanf("%d", &N);
    scanf("%d", &K);
    long answer = 1;
    for(int i=N; i>N-K; i--)
    {
        answer *= i;
        answer /= N-i+1;
        answer %= 10007;
    }
    printf("%d", answer);
    return 0;
}