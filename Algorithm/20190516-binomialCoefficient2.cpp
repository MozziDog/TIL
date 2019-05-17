//백준 11051번 문제
//이항 계수 2

//C(N, K)를 10007로 나눈 나머지를 구하기
//https://jaimemin.tistory.com/441 를 참고하여 얻은 아이디어
//파스칼의 삼각형을 활용!!!

//정답 ^^

#include<iostream>

#define mod 10007

int cache[1001][1001];

int main()
{
    int N, K;
    scanf("%d", &N);
    scanf("%d", &K);
    for(int i=1; i<= N; i++)
    {
        cache[i][1] = i;
        cache[i][i] = cache[i][0] = 1;
    }
    for(int i=3; i<=N; i++)
    {
        for(int j=2; j<i; j++)
        {
            cache[i][j] = (cache[i-1][j-1]+cache[i-1][j])%mod;
        }
    }
    std::cout<<cache[N][K];
    return 0;
}