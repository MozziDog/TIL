// 백준 2003번: 수들의 합 2
#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int n, top = 1, bot = 0, answer = 0;
	vector<int> a;
	long long sum = 0, m = 0;

	cin >> n >> m;
	a.reserve(n);
	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		a.push_back(t);
	}

	sum = a[0];
	while (top <= n)
	{
		if (sum < m)
		{
			if (top == n) break;
			sum += a[top];
			top++;
		}
		else if (sum > m)
		{
			sum -= a[bot];
			bot++;
		}
		else
		{
			answer++;
			if (top == n) break;
			sum += a[top];
			top++;
		}
	}

	cout << answer;
	return 0;
}