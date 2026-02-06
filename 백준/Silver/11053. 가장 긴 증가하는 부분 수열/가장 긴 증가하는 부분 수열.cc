#include <bits/stdc++.h>
using namespace std;

int n, a[1001], answer = 0;
int dp[1001];

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	dp[0] = 1;
	for (int i = 0; i < n; i++)
	{
		dp[i] = 1;
		for (int j = 0; j < i; j++)
		{
			if (a[i] > a[j])
				dp[i] = max(dp[i], dp[j] + 1);
		}
		answer = max(answer, dp[i]);
	}
	cout << answer;

	return 0;
}