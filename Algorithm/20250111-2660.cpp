// 백준 2660번: 회장뽑기
// 트리가 아닌 그래프를 탐색할 때에는 반드시 자기 자신을 포함해야할지 말아야 할지 잘 생각해야 하겠다.

#include <bits/stdc++.h>
using namespace std;

int n, minScore = 99, ansCount = 0;
vector<int> adj[51];
int depth[51][51];
int score[51];
int ansList[51];

void calcScore(int start)
{
	queue<int> q;
	int maxDepth = 0;
	q.push(start);
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int next : adj[cur])
		{
			if (depth[start][next] != 0) continue;
			if (next == start) continue;
			depth[start][next] = depth[start][cur] + 1;
			maxDepth = depth[start][next];
			q.push(next);
		}
	}
	score[start] = maxDepth;
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> n;
	while (true)
	{
		int a, b;
		cin >> a >> b;
		if (a == -1) break;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	for (int i = 1; i <= n; i++)
	{
		calcScore(i);
		minScore = min(minScore, score[i]);
	}

	for (int i = 1; i <= n; i++)
	{
		if (score[i] == minScore)
		{
			ansList[ansCount] = i;
			ansCount++;
		}
	}

	cout << minScore << ' ' << ansCount << '\n';
	for (int i = 0; i < ansCount; i++)
	{
		cout << ansList[i] << ' ';
	}

	return 0;
}