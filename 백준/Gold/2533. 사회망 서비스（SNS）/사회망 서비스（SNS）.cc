#include <bits/stdc++.h>
using namespace std;

const int MAX = 1'000'000;

int N, ans;
vector<int> adj[MAX];
bool visited[MAX];

bool dfs(int node)
{
	visited[node] = true;
	bool isEarlyAdaptor = false;
	// 얼리 어답터가 아닌 자식 노드를 가졌다 -> 얼리 어답터
	// 아니라면 리프 노드거나 자식이 모두 얼리 어답터 -> 일반인
	for (int nxt : adj[node])
	{
		if (visited[nxt]) continue;
		if (dfs(nxt) == false)
			isEarlyAdaptor = true;
	}
	if (isEarlyAdaptor)
	{
		ans++;
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;

	for (int i = 0; i < N - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	dfs(1);
	cout << ans;

	return 0;
}