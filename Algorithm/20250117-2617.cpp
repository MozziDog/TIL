// 백준 2617번: 구슬 찾기
// 자기보다 무거운/가벼운 구슬의 갯수를 세어서 그것이 N/2 (+1) 보다 큰 녀석들을 찾는 문제
// 기본적인 발상만 한다면 그리 어렵지는 않은 문제였다.

#include <bits/stdc++.h>
using namespace std;

int N, M, ans;
vector<int> inputH[100], inputL[100];
int heavier[100], lighter[100];

void bfs(int start, vector<int> input[], int output[])
{
	bool visited[100];
	fill(visited, visited + 100, false);
	queue<int> q;
	q.push(start);
	visited[start] = true;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int next : input[cur])
		{
			if (visited[next]) continue;
			q.push(next);
			visited[next] = true;
			output[start]++;
		}
	}
}


int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int h, l;
		cin >> h >> l;
		inputH[l].push_back(h);
		inputL[h].push_back(l);
	}
	
	for (int i = 1; i <= N; i++)
	{
		bfs(i, inputH, heavier);
		bfs(i, inputL, lighter);
	}

	int minHeavierCount = N / 2 + 1, minLighterCount = (N + 1) / 2;
	for (int i = 1; i <= N; i++)
	{
		if (heavier[i] >= minHeavierCount || lighter[i] >= minLighterCount)
			ans++;
	}
	cout << ans;
	return 0;
}