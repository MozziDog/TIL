// 백준 1912번: 연속합 
// 60퍼 부근에서 계속 틀리는데 뭐가 문제인거지? -> result를 dp[0]으로 초기화를 안해줘서였음;;
#include <bits/stdc++.h>
using namespace std;

int seq[100001];
long long dp[100001];		// i번째 원소로 끝나는 가장 큰 연속합


int main()
{
	int N;
	long long result = -1;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;
		seq[i] = tmp;
	}
	dp[0] = seq[0];
	result = dp[0];
	for (int i = 1; i < N; i++)
	{
		dp[i] = max(dp[i - 1] + seq[i], (long long)seq[i]);
		result = max(result, dp[i]);
	}

	cout << result;
	return 0;
}