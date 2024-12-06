// 백준 2531번: 회전 초밥
// 투포인터 컨셉 알고 보니 이-지한 문제였다.

#include <bits/stdc++.h>
using namespace std;

int sushiCount[3001];

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int n, d, k, c, answer = 0;
	cin >> n >> d >> k >> c;
	sushiCount[c]++;
	vector<int> sushi(n);
	for (int i = 0; i < n; i++)
	{
		cin >> sushi[i];
	}

	int bot = 0, top = bot + k, manifold = 1;
	for (int i = 0; i < top; i++)
	{
		if (sushiCount[sushi[i]] == 0)
			manifold++;
		sushiCount[sushi[i]]++;
	}
	answer = manifold;
	while (bot < n)
	{
		if (sushiCount[sushi[top]] == 0)
			manifold++;
		sushiCount[sushi[top]]++;
		top = (top + 1) % n;

		if (sushiCount[sushi[bot]] <= 1)
			manifold--;
		sushiCount[sushi[bot]]--;
		bot++;

		answer = max(answer, manifold);
	}
	cout << answer;
	return 0;
}
