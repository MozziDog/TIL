#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3F3F3F3F;

int n, m, r;
int t[101];
int cost[101][101];
int sum[101];

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	fill(&cost[0][0], &cost[100][100], INF);

	cin >> n >> m >> r;
	for (int i = 1; i <= n; i++)
		cin >> t[i];

	for (int i = 0; i < r; i++)
	{
		int a, b, l;
		cin >> a >> b >> l;
		cost[a][b] = l;
		cost[b][a] = l;
	}

	for (int i = 0; i < n; i++)
		cost[i][i] = 0;

	for (int m = 1; m <= n; m++)
		for (int s = 1; s <= n; s++)
			for (int d = 1; d <= n; d++)
			{
				if (cost[s][d] < cost[s][m] + cost[m][d]) continue;
				cost[s][d] = cost[s][m] + cost[m][d];
			}


	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (cost[i][j] <= m)
				sum[i] += t[j];
		}
	}
	cout << *max_element(&sum[1], &sum[n]);
	return 0;
}