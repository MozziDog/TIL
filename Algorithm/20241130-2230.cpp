// 백준 2230번: 수 고르기
// 일단 이분탐색 버전으로 풀어보자. 시간복잡도는 O(nlogn)

#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int n, m, t, answer = INT_MAX;
	vector<int> a;

	cin >> n >> m;
	a.reserve(n);
	for (int i = 0; i < n; i++)
	{
		cin >> t;
		a.push_back(t);
	}
	sort(a.begin(), a.end());

	for (int i = 0; i < n-1; i++ )
	{
		int bot = i + 1, top = n - 1;
		auto found = lower_bound(a.begin() + bot, a.begin() + top, a[i] + m);
		if (found != a.end() && *found - a[i] >= m)
			answer = min(answer, *found - a[i]);
	}
	cout << answer;
	return 0;
}