// 백준 12852번: 1로 만들기 2
// 제출해서 맞긴 했는데 dp용 배열을 2개 사용하는 방법이 맞았을까? 더 깔끔한 방법은 없을까?
// 짖는개도 dp용 배열을 2개 사용하네 출력하는 부분이 좀 더 깔끔하긴 해도...
// dp용 배열을 2개 쓰는 게 맞는 문제인 듯

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	vector<int> dp;
	vector<int> from;

	cin >> N;

	// dp.reserve(N + 1);
	dp.resize(N + 1);
	from.resize(N + 1);
	fill(dp.begin(), dp.end(), INT_MAX);
	dp[N] = 0;
	for (int i=N; i>1; i--)
	{
		if (i % 3 == 0 && dp[i/3] > (dp[i] + 1))
		{
			dp[i / 3] = dp[i] + 1;
			from[i / 3] = i;
		}
		if (i % 2 == 0 && dp[i / 2] > (dp[i] + 1))
		{
			dp[i / 2] = dp[i] + 1;
			from[i / 2] = i;
		}
		if (dp[i - 1] > dp[i] + 1)
		{
			dp[i - 1] = dp[i] + 1;
			from[i - 1] = i;
		}
	}

	cout << dp[1] << '\n';

	int backtrace = 1;
	vector<int> out;
	out.push_back(1);
	while (backtrace != N)
	{
		out.push_back(from[backtrace]);
		backtrace = from[backtrace];
	} 
	for (auto i = out.rbegin(); i < out.rend(); i++)
	{
		cout << *i << ' ';
	}
}