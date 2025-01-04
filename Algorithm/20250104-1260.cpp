// 백준 1260번: DFS와 BFS
// 짖는개 강의에서는 DFS를 재귀방식과 비-재귀 방식 2가지 다 구현해보라고 하는데
// DFS를 비-재귀 방식으로 다시 구현해봐야 하나?

#include <bits/stdc++.h>
using namespace std;

int N, M, V;
set<int> adj[1001];
bool visitedD[1001];
bool visitedB[1001];

void DFS(int cur)
{
	if (visitedD[cur] == true) return;
	cout << cur << ' ';
	visitedD[cur] = true;
	for (int next : adj[cur])
		DFS(next);
}

void BFS(int start)
{
	queue<int> q;
	q.push(start);
	visitedB[start] = true;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		cout << cur << ' ';
		for (int next : adj[cur])
			if (!visitedB[next])
			{
				q.push(next);
				visitedB[next] = true;
			}
	}
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> N >> M >> V;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].insert(b);
		adj[b].insert(a);
	}

	DFS(V);
	cout << '\n';
	BFS(V);

	return 0;
}