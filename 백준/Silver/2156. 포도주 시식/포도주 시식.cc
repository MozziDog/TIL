#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10'001;

int N, A[MAXN];
int dp[MAXN][3]; // 최근에 연속으로 몇개를 마셨는지

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	if (N == 1)
	{
		cout << A[0];
		return 0;
	}

	dp[0][1] = A[0];
	for (int i = 1; i < N; i++)
	{
		dp[i][0] = max({ dp[i-1][0], dp[i-1][1], dp[i-1][2] });
		dp[i][1] = dp[i-1][0] + A[i];
		dp[i][2] = dp[i-1][1] + A[i];
	}
	cout << max({ dp[N-1][0], dp[N-1][1], dp[N-1][2] });
	return 0;
}