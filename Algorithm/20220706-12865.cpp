// 백준 12865번 : 평범한 배낭
// https://www.acmicpc.net/problem/12865
// 0-1 배낭 문제

#include <iostream>

int main()
{
	int N, K, w, v;

	std::cin >> N >> K;
	int* dp = new int[K + 1];

	for (int i = 0; i < N; i++)
	{
		std::cin >> w >> v;
		for (int j = K; j >= w ; j--)	// 루프를 거꾸로 돌아야 물건이 중복해서 들어가지 않음.
			if (dp[j - w] + v > dp[j])
				dp[j] = dp[j - w] + v;
	}
	std::cout << dp[K];
}