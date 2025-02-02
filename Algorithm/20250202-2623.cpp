// 백준 2623번: 음악프로그램
// 위상정렬을 응용하여 그래프 내에 사이클이 있는지 판단해야하는 문제

#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> adj[1001];
int indegree[1001];
queue<int> q;
vector<int> ans;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> N >> M;
	while (M--)
	{
		int s, f, b = 0;
		cin >> s;
		while (s--)
		{
			f = b;
			cin >> b;
			if (f == 0) continue;
			adj[f].push_back(b);
			indegree[b]++;
		}
	}
	for (int i = 1; i <= N; i++)
	{
		if (indegree[i] == 0)
			q.push(i);
	}
	while (!q.empty())
	{
		int cur = q.front(); q.pop();
		ans.push_back(cur);
		for (int next : adj[cur])
		{
			indegree[next]--;
			if (indegree[next] == 0)
				q.push(next);
		}
	}
	if (ans.size() != N)
		cout << 0;
	else
		for (int i : ans)
			cout << i << '\n';
	return 0;
}