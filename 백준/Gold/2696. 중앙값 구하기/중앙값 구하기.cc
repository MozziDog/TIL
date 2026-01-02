#include <bits/stdc++.h>
using namespace std;

int T, M, A;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> T;
	while (T--)
	{
		priority_queue<int> smaller;
		priority_queue<int, vector<int>, greater<void>> greater;
		vector<int> ans;

		cin >> M;
		for (int i = 0; i < M; i++)
		{
			cin >> A;
			if (smaller.empty() || smaller.top() > A)
				smaller.push(A);
			else
				greater.push(A);

			if (i % 2 == 0)
			{
				while (smaller.size() > greater.size() + 1)
				{
					greater.push(smaller.top());
					smaller.pop();
				}
				while (greater.size() > smaller.size() - 1)
				{
					smaller.push(greater.top());
					greater.pop();
				}
				ans.push_back((smaller.size() > greater.size()) ? smaller.top() : greater.top());
			}
		}
		cout << ans.size() << '\n';
		for (int i = 0; i < ans.size(); i++)
		{
			cout << ans[i] << ' ';
			if (i % 10 == 9)
				cout << '\n';
		}
	}

	return 0;
}