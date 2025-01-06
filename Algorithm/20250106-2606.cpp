#include <bits/stdc++.h>
using namespace std;

int N, M, V, ans = 0;;
vector<int> adj[101];
bool infected[101];

void dfs(int cur)
{
	if (infected[cur]) return;
	infected[cur] = true;
	ans++;
	for (int next : adj[cur])
	{
		if (infected[next]) continue;
		dfs(next);
	}
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1);
	cout << ans - 1;
	return 0;
}