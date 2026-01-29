#include <bits/stdc++.h>
using namespace std;

const int divider = 1'000'000'000;

int N;
int dp[101][10][1024]; // 숫자열 길이, 마지막 숫자, 비트마스크

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;

	for (int i = 1; i < 10; i++)
	{
		dp[1][i][1 << i] = 1;
	}

	for (int i = 2; i <= N; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k < (1 << 10); k++)
			{
				int newBitmask = k | (1 << j);
				if (j > 0)
					dp[i][j][newBitmask] = (dp[i][j][newBitmask] + dp[i-1][j - 1][k]) % divider;
				if (j < 9)
					dp[i][j][newBitmask] = (dp[i][j][newBitmask] + dp[i-1][j + 1][k]) % divider;
			}
		}
	}
	
	int ans = 0;
	for (int i = 0; i < 10; i++)
	{
		ans = (ans + dp[N][i][(1 << 10) - 1]) % divider;
	}
	cout << ans;
	return 0;
}