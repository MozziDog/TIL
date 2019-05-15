//백준 11050번 문제
//이항 계수 1

//정답

#include <iostream>
using namespace std;
int main()
{
    int N, K, answer=1;
    scanf("%d", &N);
    scanf("%d", &K);
    for(int i=N; i>N-K; i--)
        answer *= i;
    for(int i=1; i<=K; i++)
        answer /= i;
    printf("%d", answer);
    return 0;
}