// 백준 1707번: 이분 그래프
// 그래프가 분리되어있을 경우 (임의의 정점 a,b 사이의 경로가 존재하지 않을 수 있는 경우)를 고려해서
// 루프문을 돌렸는데 굳이 했어야 하나? 약간 그런 느낌
// 짖는개 해답 보니까 필요한 접근이었던 듯. 좋았다.
// 두개의 그룹으로 나누어서, 각 노드마다 색을 칠하는? 느낌으로 접근하는 것도 완전 정답이었던 것 같다.

#include <bits/stdc++.h>
using namespace std;

int K, V, E;
bool ans = true;
vector<int> adj[200001];
int visited[200001];

void bfs(int start)
{
	queue<int> q;
	q.push(start);
	visited[start] = 1;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int next : adj[cur])
		{
			if (visited[next] == visited[cur])
			{
				ans = false;
				return;
			}
			if (visited[next] == 0)
			{
				visited[next] = visited[cur] == 1 ? 2 : 1;
				q.push(next);
			}
		}
	}
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> K;
	while (K--)
	{
		cin >> V >> E;
		for (int i = 0; i < E; i++)
		{
			int a, b;
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		for(int i=0; i<=V; i++)
		{
			if (visited[i] != 0) continue;
			if (ans == false) break;
			bfs(i);
		}
		cout << (ans ? "YES\n" : "NO\n");

		for (int i = 0; i <= V; i++)
			adj[i].clear();
		fill(visited, visited + 200001, 0);
		ans = true;
	}
	return 0;
}