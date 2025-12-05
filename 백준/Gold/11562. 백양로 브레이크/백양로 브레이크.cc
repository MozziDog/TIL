#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int n, m, k;
int cost[251][251];

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	fill(&cost[0][0], &cost[250][250], INF);

	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int u, v, b;
		cin >> u >> v >> b;
		cost[u][v] = 0;
		cost[v][u] = 1- b;
	}
	for (int i = 0; i < n; i++)
		cost[i][i] = 0;

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);

	cin >> k;
	for (int i = 0; i < k; i++)
	{
		int s, e;
		cin >> s >> e;
		cout << cost[s][e] << '\n';
	}
	return 0;
}