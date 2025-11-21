#include <bits/stdc++.h>
using namespace std;

int N, h;
long long ans;
stack<int> stk;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> h;
		while (!stk.empty() && stk.top() <= h)
			stk.pop();
		ans += stk.size();
		stk.push(h);
	}
	cout << ans;
	return 0;
}