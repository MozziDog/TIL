// 백준 1197번: 최소 스패닝 트리
#include <bits/stdc++.h>
using namespace std;

int V, E, ans;
vector<pair<int, int>> adj[10001];		// 가중치, 연결된 다른 노드 순서
bool visited[10001];

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<> > pq;

	cin >> V >> E;
	while (E--)
	{
		int A, B, C;
		cin >> A >> B >> C;
		adj[A].push_back({ C, B });
		adj[B].push_back({ C, A });
	}

	pq.push({ 0, 1 });
	while (!pq.empty())
	{
		int weight = pq.top().first, next = pq.top().second;
		pq.pop();
		if (visited[next] == true)
			continue;
		visited[next] = true;
		ans += weight;
		for (auto edge : adj[next])
		{
			pq.push(edge);
		}
	}
	cout << ans;
	return 0;
}