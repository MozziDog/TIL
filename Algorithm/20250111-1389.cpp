// 백준 1389번: 케빈 베이컨의 6단계 법칙
// 슬슬 그래프 문제에 익숙해지기 시작하는 것 같기도 하고

#include <bits/stdc++.h>
using namespace std;

int N, M, tAns = 1;
vector<int> adj[101];
int depth[101][101];
int bacon[101];

void bfs(int start)
{
	int b = 999;
	queue<int> q;
	q.push(start);
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int next : adj[cur])
		{
			if (depth[start][next] || start == next) continue;
			depth[start][next] = depth[start][cur] + 1;
			b = min(b, depth[start][next]);
			q.push(next);
		}
	}
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> N >> M;
	while (M--)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	for (int i = 1; i <= N; i++)
	{
		bfs(i);
		for (int j = 1; j <= N; j++)
		{
			if (i == j) continue;
			bacon[i] += depth[i][j];
		}
		if (bacon[i] < bacon[tAns])
			tAns = i;
	}

	cout << tAns;
	return 0;
}