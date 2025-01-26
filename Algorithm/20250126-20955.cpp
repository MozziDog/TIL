// 백준 20955번: 민서의 응급 수술
// 트리/그래프 쪽에서는 사이클 탐지가 많이 나오네
// 그나저나 민서는 컴공과 신임 교수가 왜 뉴런 수술을 하려는거야

#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> adj[100'001];
bool visited[100'001];
int cycle, disconnected;

void dfs(int cur, int parent)
{
	visited[cur] = true;
	for (int next : adj[cur])
	{
		if (next == parent) continue;
		if (visited[next])
		{
			cycle++;
			continue;
		}
		dfs(next, cur);
	}
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 1; i <= N; i++)
	{
		if (visited[i]) continue;
		dfs(i, 0);
		disconnected++;
	}
	cout << cycle / 2 + disconnected - 1; 	// 사이클은 a->b, b->a로 두번 세어짐
	return 0;
}