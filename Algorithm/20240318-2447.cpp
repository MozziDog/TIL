// 백준 2447번: 별 찍기 - 10
#include <bits/stdc++.h>
using namespace std;

int N;
bool star[6561][6561];

void rec(int n, int startR, int startC)
{
	int nThird = n / 3;

	for(int i = startR; i < startR + n; i += nThird)
		for (int j = startC; j < startC + n; j += nThird)
		{
			if (i == startR + nThird && j == startC + nThird)
				continue;
			if (n == 3)
				star[i][j] = true;
			else
				rec(nThird, i, j);
		}
	return;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	rec(N, 0, 0);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << (star[i][j] ? '*' : ' ');
		}
		cout << '\n';
	}

	return 0;
}