// https://www.acmicpc.net/problem/9095
// 아니 이것도 맞는 것 같은데 왜 백준은 틀렸다고 하지?????????
// 시발 줄바꿈 안해서였음;;;;

#include <iostream>

using namespace std;

#define MAX_N 11
int main()
{
	int T, N;
	scanf_s("%d", &T);
	int dp[MAX_N] = { 0, 1, 2, 4,  };
	for (int i = 4; i < MAX_N; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	}
	for (int i = 0; i < T; i++)
	{
		scanf_s("%d", &N);
		printf("%d\n", dp[N]);
	}
	return 0;
}
