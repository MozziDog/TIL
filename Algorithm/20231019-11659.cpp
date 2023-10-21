// 백준 11659번: 구간 합 구하기 4

#include<bits/stdc++.h>
using namespace std;

int dp[100001];

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int N, M;
	int input, tmpsum = 0;
	int I, J;

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		cin >> input;
		tmpsum += input;
		dp[i] = tmpsum;
	}

	for (int i = 0; i < M; i++)
	{
		cin >> I >> J;
		cout << dp[J] - dp[I - 1] << '\n';
	}
	return 0;
}