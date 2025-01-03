// 백준 11724번: 연결 요소의 개수
// 로직은 비슷하게 인접리스트로 풀었는데도 시간초과가 나서 결국 답안을 살짝 힌트로 봤다.
// 연결 요소로 묶여있는 노드를 모두 탐색했을 때 다음 시작 노드를 탐색하기 위해서 여태까지 살펴본 노드의 인덱스를 보관해야하나? 싶었다가
// N이 1000까지밖에 안되서 대충 해도 되겠지 싶었는데 그거가 문제였던 듯?

#include <bits/stdc++.h>
using namespace std;

int N, M, answer = 0;
vector<int> adj[1001];
bool visited[1001];
queue<int> q;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	for (int i = 1; i <= N; i++)
	{
		if (visited[i]) continue;

		q.push(i);
		visited[i] = true;
		while (!q.empty())
		{
			int cur = q.front();
			q.pop();
			for (int other : adj[cur])
				if (!visited[other])
				{
					// cout << "push " << adj[q.front()][i] << '\n';
					q.push(other);
					visited[other] = true;
				}
		}
		answer++;
	}
	cout << answer;
	return 0;
}