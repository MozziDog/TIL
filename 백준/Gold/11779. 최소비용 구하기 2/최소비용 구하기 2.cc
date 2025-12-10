#include <bits/stdc++.h>
using namespace std;

#define cost first
#define city second

const int INF = 2'000'000'000;

int n, m, src, dst;
vector<pair<int, int>> adj[1001];
int c[1001], bfr[1001];

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	cin >> n >> m;
	while (m--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ c, b });
	}
	cin >> src >> dst;

	fill(&c[0], &c[1001], INF);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<void>> pq;
	pq.push({0, src});
	c[src] = 0;
	while (!pq.empty())
	{
		int curCity, curCost;
		tie(curCost, curCity) = pq.top(); pq.pop();
		if (c[curCity] != curCost) continue;		// 가지치기

		for (auto nxt : adj[curCity])
		{
			if (c[nxt.city] <= c[curCity] + nxt.cost) continue;
			
			c[nxt.city] = c[curCity] + nxt.cost;
			bfr[nxt.city] = curCity;
			pq.push({ c[nxt.city], nxt.city });
		}
	}

	cout << c[dst] << '\n';
	vector<int> ans;
	int cur = dst;
	ans.push_back(cur);
	while (cur != src)
	{
		cur = bfr[cur];
		ans.push_back(cur);
	}
	cout << ans.size() << '\n';
	for (auto it = ans.rbegin(); it != ans.rend(); it++)
		cout << *it << ' ';

	return 0;
}