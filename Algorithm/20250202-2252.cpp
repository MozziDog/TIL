// 백준 2252번: 줄 세우기
// 위상정렬 연습문제

#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> adj[32001];
int indegree[32001];
queue<int> q;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> N >> M;
	while (M--)
	{
		int f, b;
		cin >> f >> b;
		adj[f].push_back(b);
		indegree[b]++;
	}

	for (int i = 1; i <= N; i++)
	{
		if (indegree[i] == 0)
			q.push(i);
	}
	while (!q.empty())
	{
		int cur = q.front(); q.pop();
		cout << cur << ' ';
		for (int next : adj[cur])
		{
			indegree[next]--;
			if (indegree[next] == 0)
				q.push(next);
		}
	}
	return 0;
}