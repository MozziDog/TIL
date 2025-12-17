#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;
int N, M, S, D;
vector<pair<int, int>> adj[1001];
int ans[1001];

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ c,b });
	}
	cin >> S >> D;
	fill(ans, ans + 1001, INF);
	ans[S] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<void>> pq;
	pq.push({ 0, S });
	while (!pq.empty())
	{
		int curTotal, curCity;
		tie(curTotal, curCity) = pq.top(); pq.pop();
		if (curTotal != ans[curCity]) continue;
		for (auto n : adj[curCity])
		{
			int nxtCost, nxtCity;
			tie(nxtCost, nxtCity) = n;
			if (curTotal + nxtCost >= ans[nxtCity]) continue;
			ans[nxtCity] = curTotal + nxtCost;
			pq.push({ ans[nxtCity], nxtCity});
		}
	}
	cout << ans[D];
	return 0;
}