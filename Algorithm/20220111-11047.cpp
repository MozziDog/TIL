// https://www.acmicpc.net/problem/11047

#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, K;
	int answer = 0;

	cin >> N;
	cin >> K;

	int coinValue[11];

	for (int i = 0; i < N; i++)
	{
		cin >> coinValue[i];
	}

	for (int i = N - 1; i >= 0; i--)
	{
		answer += K / coinValue[i]; // int 나누기
		K %= coinValue[i];
	}

	cout << answer;

	return 0;
}