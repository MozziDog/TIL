#include <bits/stdc++.h>
using namespace std;

const int INF = 10'000'001;

int n, m;
int cost[101][101];
int nxt[101][101];

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> n >> m;
	fill(&cost[0][0], &cost[100][100], INF);
	for (int i = 0; i < m; i++)
	{
		int s, d, c;
		cin >> s >> d >> c;
		cost[s][d] = min(cost[s][d], c);
		nxt[s][d] = d;
	}
	for (int i = 1; i <= n; i++)
		cost[i][i] = 0;

	for (int m = 1; m <= n; m++)
	{
		for (int s = 1; s <= n; s++)
		{
			for (int d = 1; d <= n; d++)
			{
				if (cost[s][d] > cost[s][m] + cost[m][d])
				{
					cost[s][d] = cost[s][m] + cost[m][d];
					nxt[s][d] = nxt[s][m];
				}
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << ((cost[i][j] != INF) ? cost[i][j] : 0) << ' ';
		}
		cout << '\n';
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (cost[i][j] == INF || cost[i][j] == 0)
			{
				cout << "0\n";
				continue;
			}
			int c = i;
			vector<int> route;
			route.push_back(c);
			while (c != j)
			{
				c = nxt[c][j];
				route.push_back(c);
			}
			cout << route.size();
			for (auto r : route)
				cout << ' ' << r;
			cout << '\n';
		}
	}
	return 0;
}