#include <bits/stdc++.h>
using namespace std;


int sqdist(int x1, int y1, int x2, int y2)
{
	int dx = x1 - x2, dy = y1 - y2;
	return (dx * dx) + (dy * dy);
}

void solve()
{
	int x1, y1, x2, y2, n, cx, cy, r;
	int ans = 0;
	cin >> x1 >> y1 >> x2 >> y2;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> cx >> cy >> r;
		bool includeStart = sqdist(cx, cy, x1, y1) < (r * r);
		bool includeEnd = sqdist(cx, cy, x2, y2) < (r * r);
		if (includeStart ^ includeEnd)
			ans++;
	}
	cout << ans << '\n';
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	int T;
	cin >> T;
	while (T--)
		solve();

	return 0;
}