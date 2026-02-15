/*
피사노 주기의 성질에 따라
피보나치 수열을 1'000'000( = 1.0e6)으로 나눈 나머지는 1'500'000(= 1.5e6)의 주기를 갖는다.
*/
#include <bits/stdc++.h>
using namespace std;
#define llong long long

const llong MAX = 1'000'000'000'000'000'000;
const llong DIVIDER = 1'000'000;
const llong PERIOD = DIVIDER * 3 / 2;

llong n;

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	cin >> n;
	n %= PERIOD;

	if (n == 1)
		cout << 1;
	else if (n == 2)
		cout << 1;
	else
	{
		int bbefore = 1, before = 1;
		for (int i = 3; i <= n; i++)
		{
			swap(before, bbefore);
			before = (before + bbefore) % DIVIDER;
		}
		cout << before;
	}

	return 0;
}