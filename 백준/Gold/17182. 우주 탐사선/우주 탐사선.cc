#include <bits/stdc++.h>
using namespace std;

int N, K, ans = INT_MAX;
int T[12][12];

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> T[i][j];
		}
	}
	for (int m = 0; m < N; m++)
	{
		for (int s = 0; s < N; s++)
		{
			for (int d = 0; d < N; d++)
			{
				T[s][d] = min(T[s][d], T[s][m] + T[m][d]);
			}
		}
	}
	
	queue<tuple<int, int, int>> q;	// 현재 행성, cost, visited 비트맵
	q.push({ K, 0, 1 << K });
	while (!q.empty())
	{
		int cur, cost, visited;
		tie(cur, cost, visited) = q.front();
		q.pop();
		for (int nxt = 0; nxt < N; nxt++)
		{
			if (visited == (1 << N) - 1)
			{
				ans = min(ans, cost);
				continue;
			}
			if (cur == nxt) continue;
			if (visited & (1 << nxt)) continue;
			else
				q.push({ nxt, cost + T[cur][nxt], visited | (1 << nxt) });
		}
	}
	cout << ans;
	return 0;
}