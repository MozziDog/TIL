#include <bits/stdc++.h>
using namespace std;

const int MAXLEN = 1'000'001;

int N, ans, A[MAXLEN], Dp[MAXLEN], Index[MAXLEN];

int findIndex(int num)
{
	int start = 0, end = N;
	while (start <= end)
	{
		int mid = (start + end) / 2;
		if (Index[mid] >= num)
			end = mid - 1;
		else
			start = mid + 1;
	}
	return start;
}	

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	Index[0] = INT_MIN;
	fill(Index+1, Index + MAXLEN, INT_MAX);

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> A[i];
	
	for (int i = 1; i <= N; i++)
	{
		Dp[i] = findIndex(A[i]);
		Index[Dp[i]] = min(Index[Dp[i]], A[i]);
		ans = max(ans, Dp[i]);
	}
	cout << ans;
	return 0;
}