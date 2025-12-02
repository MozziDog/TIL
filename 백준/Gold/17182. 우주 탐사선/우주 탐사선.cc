#include <bits/stdc++.h>
using namespace std;

int N, K;
int T[12][12];
int DP[10][1 << 10];

int dfs(int cur, int visited)
{
	if (visited == (1 << N) - 1) return 0;
	if (DP[cur][visited] >= 0) return DP[cur][visited];
	int ret = INT_MAX;
	for (int i = 0; i < N; i++)
	{
		if (visited & 1 << i) continue;
		ret = min(ret, dfs(i, visited | 1 << i) + T[cur][i]);
	}
	return DP[cur][visited] = ret;
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> N >> K;
	fill(&DP[0][0], &DP[9][(1 << 10) - 1], -1);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> T[i][j];
		
	for (int m = 0; m < N; m++)
		for (int s = 0; s < N; s++)
			for (int d = 0; d < N; d++)
				T[s][d] = min(T[s][d], T[s][m] + T[m][d]);
	
	cout << dfs(K, 1<<K);
	return 0;
}