#include <bits/stdc++.h>
using namespace std;

int N, M;
int num[2001];
bool isPalin[2001][2001];

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> num[i];
	}
	// 길이 홀수인 수열
	int left, right;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j < i && j <= N - i; j++)
		{
			left = i - j;
			right = i + j;
			if (num[left] == num[right])
				isPalin[left][right] = true;
			else
				break;
		}
	}
	// 길이 짝수인 수열
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < i && j < N - i; j++)
		{
			left = i - j;
			right = i + j + 1;
			if (num[left] == num[right])
				isPalin[left][right] = true;
			else
				break;
		}
	}
	
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int S, E;
		cin >> S >> E;
		cout << (isPalin[S][E] ? 1 : 0) << '\n';
	}

	return 0;
}