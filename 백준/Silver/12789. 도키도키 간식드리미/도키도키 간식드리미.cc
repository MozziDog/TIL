#include <bits/stdc++.h>
using namespace std;

int n, cur = 1;
vector<int> row;
stack<int> tmp;

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	cin >> n;
	for (int i= 0; i < n; i++)
	{
		int in;
		cin >> in;
		row.push_back(in);
	}
	for (int a : row)
	{
		if (a == cur)
		{
			cur++;
			continue;
		}
		while (!tmp.empty() && tmp.top() == cur)
		{
			tmp.pop();
			cur++;
		}
		tmp.push(a);
	}
	while (!tmp.empty())
	{
		if (tmp.top() == cur)
		{
			tmp.pop();
			cur++;
		}
		else
		{
			cout << "Sad";
			return 0;
		}
	}
	cout << "Nice";
	return 0;
}