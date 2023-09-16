// 백준 9663번: N-Queen

#include <bits/stdc++.h>
using namespace std;

int N;
int answer = 0;
bool isUsedRow[15] = { false, };
bool isUsedUpwardD[30] = { false, };
bool isUsedDownwardD[30] = { false, };

void solve(int column)
{
	for (int r = 0; r < N; r++)
	{
		if (isUsedRow[r] || isUsedUpwardD[r - column + 15] || isUsedDownwardD[r + column])
			continue;
		if (column == N - 1)
		{
			answer++;
			return;
		}
		// (i, column)
		isUsedRow[r] = true;
		// r = c + k, k = r - c
		isUsedUpwardD[r - column + 15] = true;
		// r = -c + k, k = r + c
		isUsedDownwardD[r + column] = true;

		solve(column + 1);

		isUsedRow[r] = false;
		isUsedUpwardD[r - column + 15] = false;
		isUsedDownwardD[r + column] = false;
	}
	
}

int main()
{
	cin >> N;
	solve(0);
	cout << answer;
	return 0;
}