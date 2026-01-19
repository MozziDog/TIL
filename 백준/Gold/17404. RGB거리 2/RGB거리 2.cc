#include <bits/stdc++.h>
using namespace std;

const int R = 0;
const int G = 1;
const int B = 2;
const int INF = 1'000'001;

int N, ans = INF;
int cost[1001][3];
int dp[1001][3][3];		// 인덱스, 해당 집의 색상, 첫번째 집의 색상

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < 3; j++)
			cin >> cost[i][j];

	fill(&dp[0][0][0], &dp[0][2][2], INF);
	dp[0][R][R] = cost[0][R];
	dp[0][G][G] = cost[0][G];
	dp[0][B][B] = cost[0][B];
	for (int i = 1; i < N; i++)
	{
		for (int s = 0; s < 3; s++)
		{
			for (int j = 0; j < 3; j++)
			{
				dp[i][R][s] = min(dp[i - 1][G][s], dp[i - 1][B][s]) + cost[i][R];
				dp[i][G][s] = min(dp[i - 1][R][s], dp[i - 1][B][s]) + cost[i][G];
				dp[i][B][s] = min(dp[i - 1][R][s], dp[i - 1][G][s]) + cost[i][B];
			}
		}
	}
	
	ans = min({
		dp[N - 1][R][B],
		dp[N - 1][R][G],
		dp[N - 1][G][R],
		dp[N - 1][G][B],
		dp[N - 1][B][R],
		dp[N - 1][B][G]
		});
	cout << ans;
	return 0;
}