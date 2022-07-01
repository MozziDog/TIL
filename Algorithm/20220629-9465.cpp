// 백준 9465번 : 스티커
// https://www.acmicpc.net/problem/9465
// 간단한 DP 문제

#include <iostream>

int max(int a, int b) { return a < b ? b : a; }

int main()
{
	std::ios_base::sync_with_stdio(false);

	int T; // testcase
	std::cin >> T;
	int** stickers = new int*[2];
	int** maxValue = new int*[2];
	for (int testCase = 0; testCase < T; testCase++)
	{
		int n;
		std::cin >> n;
		stickers[0] = new int[n];
		stickers[1] = new int[n];
		maxValue[0] = new int[n];
		maxValue[1] = new int[n];
		for (int row = 0; row < 2; row++)
			for (int column = 0; column < n; column++)
				std::cin >> stickers[row][column];
		maxValue[0][0] = stickers[0][0];
		maxValue[1][0] = stickers[1][0];
		if (n > 1)
		{
			maxValue[0][1] = maxValue[1][0] + stickers[0][1];
			maxValue[1][1] = maxValue[0][0] + stickers[1][1];
		}
		for (int i = 2; i < n; i++)
		{
			maxValue[0][i] = max(maxValue[1][i - 2] + stickers[0][i], maxValue[1][i - 1]+stickers[0][i]);
			maxValue[1][i] = max(maxValue[0][i - 2] + stickers[1][i], maxValue[0][i - 1]+stickers[1][i]);
		}
		std::cout << max(maxValue[0][n - 1], maxValue[1][n - 1]) << "\n";
		delete[] stickers[0];
		delete[] stickers[1];
		delete[] maxValue[0];
		delete[] maxValue[1];
	}
	return 0;
}