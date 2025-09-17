#include <bits/stdc++.h>
using namespace std;

const int INF = 99'999'999;

int n, m;
int cost[102][102];

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	fill(&cost[1][1], &cost[100][100], INF);

	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		cost[a][b] = min(cost[a][b], c);
	}
	
	for (int s = 1; s <= n; s++)
		for (int o = 1; o <= n; o++)
			for (int d = 1; d <= n; d++)
			{
				if (s == o || s == d || o == d) continue;
				cost[o][d] = min(cost[o][d], cost[o][s] + cost[s][d]);
			}
		
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cout << (cost[i][j] != INF ? cost[i][j] : 0) << ' ';
		cout << '\n';
	}

	return 0;
}