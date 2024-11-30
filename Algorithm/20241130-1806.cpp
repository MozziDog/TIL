// 백준 1806번: 부분합
// 투포인터를 쓰면 2중 루프문으로 구현되어있어도 실제 작업은 최대 2n회이기 때문에 O(n)에 속한다는 것.
// 시간복잡도 계산을 할 때 투포인터를 사용하였는지 고려를 해봐야 하겠네요.

#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int n, s, answer = INT_MAX;
	vector<int> a;
	cin >> n >> s;
	a.reserve(n);
	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		a.push_back(t);
	}

	int top = 0, bot = 0, sum= a[0];
	while (top < n)
	{
		while (sum >= s)
		{
			answer = min(answer, top - bot + 1);
			sum -= a[bot];
			bot++;
		}
		top++;
		if (top >= n) break;
		sum += a[top];
	}
	if (answer == INT_MAX) answer = 0;
	cout << answer;
	return 0;
}