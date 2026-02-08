#include <bits/stdc++.h>
using namespace std;

const int MAXLEN = 1'000'001;

int N, ans, A[MAXLEN], Index[MAXLEN];

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
		int pos = lower_bound(Index, Index + N, A[i]) - Index;
		Index[pos] = min(Index[pos], A[i]);
		ans = max(ans, pos);
	}
	cout << ans;
	return 0;
}