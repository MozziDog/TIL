#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	int t, a, b;
	cin >> t;
	while (t--)
	{
		cin >> a >> b;
		int n = a % 10;
		b--;
		while (b--)
		{
			n = (n * a) % 10;
		}
		if (n == 0)
			n = 10;
		cout << n << '\n';
	}
}