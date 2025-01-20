// 백준 4803번: 트리
// 왜 답이 이상하게 자꾸 나오나 했더니 테스트 케이스 넘어가면서 초기화를 안해줬었네... 머쓱;;

#include <bits/stdc++.h>
using namespace std;

int N, M, trees = 0;
vector<int> adj[501];
bool visited[501];

bool dfs(int cur, int parent)
{
	bool isTree = true;
	visited[cur] = true;
	for (int next : adj[cur])
	{
		if (next == parent) continue;
		if (visited[next]) return false;
		isTree &= dfs(next, cur);
	}
	return isTree;
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int testCase = 0;
	while (true)
	{
		testCase++;
		trees = 0;
		cin >> N >> M;
		if (N == 0) break;
		for (int i = 0; i <= N; i++) 
			adj[i].clear();
		fill(visited, visited + 501, false);

		for (int i = 0; i < M; i++)
		{
			int a, b;
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		for (int i = 1; i <= N; i++)
		{
			if (!visited[i])
				if (dfs(i, 0)) 
					trees += 1;
		}
		cout << "Case " << testCase << ": ";
		switch (trees)
		{
		case 0:
			cout << "No trees.\n";
			break;
		case 1:
			cout << "There is one tree.\n";
			break;
		default:
			cout << "A forest of " << trees << " trees.\n";
		}
	}
	return 0;
}