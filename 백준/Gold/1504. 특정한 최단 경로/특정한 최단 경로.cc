#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX;
int N, E, V1, V2;
vector<pair<int, int>> adj[801];

vector<int> daik(int start)
{
	vector<int> ret(N + 1);
	fill(ret.begin(), ret.end(), INF);
	ret[start] = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<void>> pq;
	pq.push({ 0, start });
	while (!pq.empty())
	{
		int curCity, curCost;
		tie(curCost, curCity) = pq.top(); pq.pop();
		if (curCost != ret[curCity]) continue;
		for (auto n : adj[curCity])
		{
			if (ret[n.second] <= ret[curCity] + n.first) continue;
			ret[n.second] = ret[curCity] + n.first;
			pq.push({ ret[n.second], n.second });
		}
	}
	return ret;
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> N >> E;
	for (int i = 0; i < E; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		adj[a].push_back({ c, b });
		adj[b].push_back({ c, a });
	}
	cin >> V1 >> V2;

	vector<int> fromStart, fromV1, fromV2;
	fromStart = daik(1);
	fromV1 = daik(V1);
	fromV2 = daik(V2);

	long long ans = min({ (long)fromStart[V1] + (long)fromV1[V2] + (long)fromV2[N],
					(long)fromStart[V2] + (long)fromV2[V1] + (long)fromV1[N] });
	cout << (ans >= INF ? -1 : ans);
	return 0;
}