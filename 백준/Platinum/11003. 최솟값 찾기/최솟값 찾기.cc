#include <bits/stdc++.h>
using namespace std;

int N, L;
vector<int> A;
deque<int> dq;

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> L;
	for (int i = 0; i < N; i++)
	{
		int in;
		cin >> in;
		A.push_back(in);

		while (!dq.empty() && dq.back() > in)
			dq.pop_back();
		dq.push_back(in);

		if (i - L >= 0 && A[i - L] == dq.front())
			dq.pop_front();

		cout << dq.front() << ' ';
	}
	return 0;
}
