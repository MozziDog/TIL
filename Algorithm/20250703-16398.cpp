// 백준 16398번: 행성 연결
// 전형적인 최소신장트리 문제
// ans가 가질 수 있는 값의 범위에 항상 주의하도록 하자. int로 했다가 틀렸었음

#include <bits/stdc++.h>
using namespace std;

int N, cost[1001][1001];
long long ans;
bool chk[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> cost[i][j];
		}
	}

	pq.push({ 0, 0 });
	while (!pq.empty())
	{
		int nextcost = pq.top().first, nextnode = pq.top().second;
		pq.pop();
		if (chk[nextnode] == true) continue;
		chk[nextnode] = true;
		ans += nextcost;
		for (int i = 0; i < N; i++)
		{
			if (chk[i]) continue;
			pq.push({ cost[nextnode][i], i });
		}
	}
	cout << ans;

	return 0;
}