#include <bits/stdc++.h>
using namespace std;

int N, Q;
vector<int> a;
vector<long long> s, p;

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> Q;
	a.push_back(0);
	s.push_back(0);
	p.push_back(0);

	int in; cin >> in;
	a.push_back(in);
	s.push_back(in);
	p.push_back(in * in);
	for (int i = 2; i <= N; i++)
	{
		int in;
		cin >> in;
		a.push_back(in);
		s.push_back(s[i - 1] + in);
		p.push_back(p[i - 1] + in * in);
	}

	while (Q--)
	{
		int l, r;
		cin >> l >> r;

		long long sum = s[r] - s[l-1];
		sum = sum * sum;
		sum -= p[r] - p[l-1];
		cout << sum / 2 << '\n';
	}

	return 0;
}
