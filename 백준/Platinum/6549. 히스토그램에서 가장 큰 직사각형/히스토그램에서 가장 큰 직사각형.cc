// 백준 6549번: 히스토그램에서 가장 큰 직사각형
#include <bits/stdc++.h>
using namespace std;

#define index first
#define height second

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	while (true)
	{
		int n;
		long long ans = 0;
		stack<pair<int, long long>> stk;

		cin >> n;
		if (n == 0) return 0;

		for (int i = 0; i < n; i++)
		{
			int h;
			cin >> h;

			while (!stk.empty() && stk.top().height > h)
			{
				int topIndex = stk.top().index;
				int topHeight = stk.top().height;
				stk.pop();
				int width = stk.empty() ? i : i - stk.top().index - 1;
				ans = max(ans, (long long)width * topHeight);
			}
			stk.push({ i, h });
		}
		while (!stk.empty())
		{
			long long topIndex = stk.top().index;
			long long topHeight = stk.top().height;
			stk.pop();
			if (stk.empty())
				ans = max(ans, n * topHeight);
			else
				ans = max(ans, (n - stk.top().index - 1)* topHeight);
		}
		cout << ans << '\n';
	}
}