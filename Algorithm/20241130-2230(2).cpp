// 백준 2230번: 수 고르기
// 이제 투포인터 버전으로 풀어보자.
// 핵심 로직의 시간복잡도는 O(n)이지만 어차피 정렬때문에 전체 시간복잡도는 O(nlogn)임

#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int n, m, t, answer = INT_MAX;
	int p1 = 0, p2 = 0;
	vector<int> a;
	cin >> n >> m;
	a.reserve(n);
	for (int i = 0; i < n; i++)
	{
		cin >> t;
		a.push_back(t);
	}
	sort(a.begin(), a.end());

	while (p1 < n && p2 < n)
	{
		if (a[p2] - a[p1] >= m)
		{
			answer = min(answer, a[p2] - a[p1]);
			p1++;
		}
		else
			p2++;
	}
	cout << answer;
	return 0;
}