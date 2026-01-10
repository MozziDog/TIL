#include <bits/stdc++.h>
using namespace std;

#define COST first
#define CUSTOMER second
const int INF = 1000 * 1000;

int N, C;
vector<pair<int, int>> city;
int dp[1101];

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	fill(dp, dp + 1101, INF);

	cin >> C >> N;
	for (int i = 0; i < N; i++)
	{
		int cost, customer;
		cin >> cost >> customer;
		city.push_back({ cost, customer });
	}

	for (int i = 1; i <= C + 100; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (i - city[j].CUSTOMER <= 0)
				dp[i] = min(dp[i], city[j].COST);
			else
				dp[i] = min(dp[i], dp[i - city[j].CUSTOMER] + city[j].COST);
		}
	}

	int ans = INF;
	for (int i = C; i < C + 100; i++)
	{
		ans = min(ans, dp[i]);
	}
	cout << ans;
	return 0;
}
