// 백준 11725번: 트리의 부모 찾기

#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> adj[100001];
int parent[100001];

void dfs(int node)
{
	for (int ch : adj[node])
	{
		if (ch == parent[node]) continue;
		parent[ch] = node;
		dfs(ch);
	}
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> N;
	for (int i = 0; i < N-1; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(1);
	for (int i = 2; i <= N; i++)
	{
		cout << parent[i] << '\n';
	}

	return 0;
}