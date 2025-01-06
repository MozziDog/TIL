// 백준 1260번: DFS와 BFS
// 재귀 안쓰고 스택으로 풀어본 버전

#include <bits/stdc++.h>
using namespace std;

int N, M, V;
vector<int> adj[1001];
bool visitedD[1001];
bool visitedB[1001];

void DFS(int start)
{
	stack<int> s;
	s.push(start);
	while (!s.empty())
	{
		int cur = s.top();
		s.pop();
		if (visitedD[cur]) continue;
		visitedD[cur] = true;
		cout << cur << ' ';
		
		for (auto i = adj[cur].rbegin(); i != adj[cur].rend(); i++)
		{
			if (visitedD[*i]) continue;
			s.push(*i);
		}
	}
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
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for (int i = 0; i <= N; i++)
		sort(adj[i].begin(), adj[i].end());

	DFS(V);
	cout << '\n';
	BFS(V);

	return 0;
}