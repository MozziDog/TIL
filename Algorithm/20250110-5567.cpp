// 백준 5567번: 결혼식
// 기본적인 flood fill 문제였다.

#include <bits/stdc++.h>
using namespace std;

int n, m, ans = 0;
vector<int> adj[501];
bool visited[501];

void dfs(int cur, int depth)
{
	if (depth > 2) return;
	if (!visited[cur])
	{
		ans++;
		visited[cur] = true;
	}
	for (auto next : adj[cur])
		dfs(next, depth + 1);
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(1, 0);

	cout << ans - 1;
	return 0;
}