// 알고리즘 잘 짜놓고 pair의 앞에다가 노드 번호를 놓아서 pq 정렬이 이상하게 되어 틀렸었다.
// pq와 pair/tuple을 같이 쓸 때에는 제일 앞에 가중치가 올 수 있도록 주의하자.

#include <bits/stdc++.h>
using namespace std;

#define node int
#define weight int

int V, E, nodeCount = 0;
vector<pair<weight, node>> edge[10001];
bool visited[10001];
long long ans = 0;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

	cin >> V >> E;
	for (int i = 0; i < E; i++)
	{
		int A, B, C;
		cin >> A >> B >> C;
		edge[A].push_back({ C, B });
		edge[B].push_back({ C, A });
	}

	visited[1] = true;
	nodeCount++;
	for (auto e : edge[1])
	{
		pq.push(e);
	}
	while (nodeCount < V)
	{
		int nextnode = pq.top().second,
			nextweight = pq.top().first;
		pq.pop();
		if (visited[nextnode])
			continue;
		visited[nextnode] = true;
		nodeCount++;
		ans += nextweight;
		for (auto e : edge[nextnode])
		{
			pq.push(e);
		}
	}
	cout << ans;
	return 0;
}