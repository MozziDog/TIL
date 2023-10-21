// 백준 11726번: 2×n 타일링

#include <bits/stdc++.h>
using namespace std;

int dp[1001];

int main()
{
	int N;
	cin >> N;

	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= N; i++)
	{
		dp[i] = (dp[i - 2] + dp[i - 1]) % 10007;
	}

	cout << dp[N];
	return 0;
}