// 백준 2056번: 작업
// 각 작업이 시작될 수 있는 가장 빠른 시각_starttime_을 기록해놓는 것이 핵심인 문제였다.

#include <bits/stdc++.h>
using namespace std;

int N, ans = 0;
vector<int> adj[10001];
int indegree[10001], worktime[10001], starttime[10001];
queue<int> q; // 작업, 시작시간 순

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		int fc;
		cin >> worktime[i] >> fc;
		while (fc--)
		{
			int f;
			cin >> f;
			adj[f].push_back(i);
			indegree[i]++;
		}
	}

	for (int i = 1; i <= N; i++)
	{
		if (indegree[i] == 0) q.push(i);
	}
	while (!q.empty())
	{
		int work = q.front(), endtime = starttime[work] + worktime[work];
		q.pop();
		ans = max(ans, endtime);
		for (int next : adj[work])
		{
			indegree[next]--;
			starttime[next] = max(starttime[next], endtime);
			if (indegree[next] == 0)
				q.push(next);
		}
	}
	cout << ans;
	return 0;
}