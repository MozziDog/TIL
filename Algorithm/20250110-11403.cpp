// 백준 11403번: 경로 찾기
// 대체로 flood fill에 관한 문제가 계속 나오는 듯

#include <bits/stdc++.h>
using namespace std;

int N;
int adj[100][100];
bool visited[100][100];
int result[100][100];

void bfs(int start)
{
	queue<int> q;
	q.push(start);
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int i = 0; i < N; i++)
		{
			if (adj[cur][i] && !visited[start][i])
			{
				q.push(i);
				result[start][i] = true;
				visited[start][i] = true;
			}
		}
	}
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int e;
			cin >> e;
			adj[i][j] = e;
		}
	}

	for (int i = 0; i < N; i++)
		bfs(i);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << result[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}