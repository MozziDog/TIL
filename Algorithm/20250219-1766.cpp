// 백준 1766번: 문제집
// 아주 깔끔하게 풀은 것 같다. 굿
#include <bits/stdc++.h>
using namespace std;

int N, M;
set<int> adj[32001];
int indegree[32001];

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int A, B;
	priority_queue<int, vector<int>, greater<>> q;

	cin >> N >> M;
	while (M--)
	{
		cin >> A >> B;
		adj[A].insert(B);
		indegree[B]++;
	}
	// 루트 찾기
	for (int i = 1; i <= N; i++)
	{
		if (indegree[i] == 0)
			q.push(i);
	}
	while (!q.empty())
	{
		int cur = q.top(); q.pop();
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