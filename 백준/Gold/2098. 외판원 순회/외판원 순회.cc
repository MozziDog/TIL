#include <bits/stdc++.h>
using namespace std;

const int MAX = 20'000'000;
int N;
int cost[16][16];
int dp[16][1 << 16]; // 현재 지점, 방문 비트마스크

int dfs(int cur, int visited)
{
	visited |= (1 << cur);
	if (visited == ((1 << N) - 1))
	{
		if (cost[cur][0] == 0)
			return MAX;
		else
		{
			dp[cur][visited] = cost[cur][0];
			return cost[cur][0];
		}
	}

	if (dp[cur][visited] == -1)	// 이미 탐색해봤는데 답이 없는 경로인 경우
		return MAX;
	if (dp[cur][visited] != MAX)
		return dp[cur][visited];

	int left = MAX;
	for (int i = 0; i < N; i++)
	{
		if (visited & (1 << i)) continue;
		if (cost[cur][i] == 0) continue;
		left = min(left, dfs(i, visited) + cost[cur][i]);
	}
	if (left != MAX)
	{
		dp[cur][visited] = left;
		return dp[cur][visited];
	}
	else
	{
		dp[cur][visited] = -1;
		return MAX;
	}
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> cost[i][j];
	for (int i = 0; i < N; i++)
			fill(dp[i], dp[i] + (1 << 16), MAX);

	// 어차피 순환경로를 찾는 것이니 아무 점에서 시작해도 됨
	cout << dfs(0, 0);
	return 0;
}