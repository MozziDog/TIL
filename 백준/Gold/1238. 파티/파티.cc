#include <bits/stdc++.h>
using namespace std;

#define city second
#define cost first

const int INF = INT_MAX;
int N, M, X;
vector<pair<int, int>> T[1001];
vector<pair<int, int>> R[1001];
int costA[1001], costB[1001];

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> M >> X;
	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		T[a].push_back({ c, b });
		R[b].push_back({ c, a });
	}
	fill(costA, costA + 1001, INF);
	fill(costB, costB + 1001, INF);

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<void>> pq;
	pq.push({ 0, X });
	costA[X] = 0;
	while (!pq.empty())
	{
		int curCity, curCost;
		tie(curCost, curCity) = pq.top(); pq.pop();
		if (costA[curCity] != curCost) continue;

		for (auto e : T[curCity])
		{
			if (curCost + e.cost >= costA[e.city]) continue;
			costA[e.city] = min(costA[e.city], curCost + e.cost);
			pq.push({ curCost + e.cost, e.city });
		}
	}

	pq.push({ 0, X });
	costB[X] = 0;
	while (!pq.empty())
	{
		int curCity, curCost;
		tie(curCost, curCity) = pq.top(); pq.pop();
		if (costB[curCity] != curCost) continue;

		for (auto e : R[curCity])
		{
			if (curCost + e.cost >= costB[e.city]) continue;
			costB[e.city] = min(costB[e.city], curCost + e.cost);
			pq.push({ curCost + e.cost, e.city });
		}
	}

	int ans = 0;
	for (int i = 1; i <= N; i++)
	{
		if (i == X) continue;
		ans = max(ans, costA[i] + costB[i]);
	}
	cout << ans;
	return 0;
}