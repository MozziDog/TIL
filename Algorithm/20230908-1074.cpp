// 백준 1074번: Z
#include <bits/stdc++.h>
using namespace std;

int solve(int, int, int);

int main()
{
	int N, r, c;
	cin >> N >> r >> c;

	cout << solve(N, r, c);
	return 0;
}

int solve(int n, int r, int c)
{
	int countOfQuater = 1 << (2 * (n - 1));
	int passedQuaters = 0;

	if (n == 0) return 0;

	if (1 << (n - 1) <= r)
	{ 
		passedQuaters += 2;
		r -= 1 << (n - 1);
	}
	if (1 << (n - 1) <= c)
	{
		passedQuaters += 1;
		c -= 1 << (n - 1);
	}
	return passedQuaters * countOfQuater + solve(n-1, r, c);
}