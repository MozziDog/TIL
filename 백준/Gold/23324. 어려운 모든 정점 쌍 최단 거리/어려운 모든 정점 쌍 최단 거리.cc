#include <bits/stdc++.h>
using namespace std;

int N, M, K;
vector<int> adj[100'001];
bool visited[100'001];

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> M >> K;
	int a, b;
	for (int i = 1; i < K; i++)
	{
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	cin >> a >> b;		// K번째 입력 버림
	for (int i = K + 1; i <= M; i++)
	{
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	long long s[2] = { 0, 0 };
	int g = 0;
	for (int i = 1; i <= N; i++)
	{
		if (visited[i]) continue;
		queue<int> q;
		q.push(i);
		while (!q.empty())
		{
			int cur = q.front(); q.pop();
			if (visited[cur]) continue;
			visited[cur] = true;
			s[g]++;
			for (int nxt : adj[cur])
			{
				if (!visited[nxt])
					q.push(nxt);
			}
		}
		g++;
	}
	cout << s[0] * s[1];
	return 0;
}