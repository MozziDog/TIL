// 백준 11053번 가장 긴 증가하는 부분 수열
// https://velog.io/@junttang/BOJ-12015-%EA%B0%80%EC%9E%A5-%EA%B8%B4-%EC%A6%9D%EA%B0%80%ED%95%98%EB%8A%94-%EB%B6%80%EB%B6%84-%EC%88%98%EC%97%B4-2-%ED%95%B4%EA%B2%B0-%EC%A0%84%EB%9E%B5-C
// ~를 참고해서 풀었다. 나중에 까먹었을 때 쯤 다시 도전해서 직접 생각하여 풀어보자.

#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int n;
	vector<int> a, dp;
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		a[i] = t;
	}
	dp.push_back(a[0]);
	for (int i = 1; i < n; i++)
	{
		if (a[i] > dp[dp.size() - 1])
			dp.push_back(a[i]);
		else
		{
			int bot = 0, top = dp.size() - 1;
			while (top >= bot)
			{
				int mid = (top + bot) / 2;
				if (dp[mid] < a[i])
					bot = mid + 1;
				else
					top = mid - 1;
			}
			dp[bot] = a[i];
		}
	}

	cout << dp.size();
	return 0;
}