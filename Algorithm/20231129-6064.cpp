// 백준 6064번: 카잉 달력
// 확실히 수학 문제는 깊게 생각하지 않으면 어렵다;;
#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
	if (a == 0) return b;
	return gcd(b%a, a);
}

int lcm(int a, int b)
{
	return a * b / gcd(a, b);
}


int main()
{
	int T, M, N, x, y;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		cin >> M >> N >> x >> y;

		int answer = -1;
		int end = lcm(M, N);

		while (x <= end) // 종말의 해는 최소공배수
		{
			if (x % N == y % N)	// y == N일 경우를 고려
			{
				answer = x;
				break;
			}
			else
			{
				x += M;
			}
		}
		cout << answer << '\n';
	}
	return 0;
}