#include <bits/stdc++.h>
using namespace std;

const int MAX_COUNT = 500'000;

int p[MAX_COUNT];
int n, m;

int find(int a)
{
	if (p[a] < 0)
		return a;
	else
		return p[a] = find(p[a]);
}

bool merge(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a == b) return false;

	if (a > b)
		swap(a, b);
	if (a == b)
		a--;
	p[b] = a;
	return true;
}


int main()
{
	cin.tie(0)->sync_with_stdio(0);

	cin >> n >> m;

	fill(p, p + n, -1);

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		if (!merge(a, b))
		{
			cout << i + 1;
			return 0;
		}
	}
	cout << 0;
	return 0;
}