#include <bits/stdc++.h>
using namespace std;

const int MAX = 501;
int N;
vector<int> r, c;

int dp[MAX][MAX];

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	r.resize(N); c.resize(N);
	fill(&dp[0][0], &dp[MAX - 1][MAX - 1] + 1, INT_MAX);
	for (int i = 0; i < N; i++)
	{
		cin >> r[i] >> c[i];
		dp[i][i] = 0;
	}
	for (int k = 1; k < N; k++)
	{
		int minI;
		for (int i = 0; i < N - k; i++)
		{
			
			for (int j = i; j < i + k; j++)
			{
				dp[i][i + k] = min(dp[i][i + k],
					dp[i][j] + dp[j + 1][i + k] + r[i] * c[j] * c[i + k]);
			}
		}

	}
	cout << dp[0][N-1];
	return 0;
}