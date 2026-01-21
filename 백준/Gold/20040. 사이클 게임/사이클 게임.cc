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

	int result = 0;
	fill(p, p + MAX_COUNT, -1);

	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		if (!merge(a, b) && result == 0)
			result = i + 1;
	}
	cout << result;
	return 0;
}