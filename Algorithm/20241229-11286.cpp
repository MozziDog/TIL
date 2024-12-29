// 백준 11286번: 절댓값 힙
#include <bits/stdc++.h>
using namespace std;

bool cmp(int a, int b)
{
	if (abs(a) == abs(b))
		return a > b;
	return abs(a) > abs(b);
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int N, x;
	priority_queue<int, vector<int>, function<bool(int, int)>> pq(cmp);

	cin >> N;
	while (N--)
	{
		cin >> x;
		if (x == 0)
		{
			if (pq.empty())
			{
				cout << "0\n";
			}
			else
			{
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		else
		{
			pq.push(x);
		}
	}
	return 0;
}