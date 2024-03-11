// 백준 11055번: 가장 큰 증가하는 부분 수열
#include <bits/stdc++.h>
using namespace std;

int N;
int A[1001];	// 순서대로 i번째 원소
int sum[1001]; // i번째 원소를 포함하는 부분 수열중 합이 가장 큰 것의 합.

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	sum[0] = A[0];
	for (int i = 0; i < N; i++)
	{
		sum[i] = A[i];
		for (int j = 0; j < i; j++)
		{
			if (A[j] < A[i] && sum[i] < (sum[j] + A[i]))
				sum[i] = sum[j] + A[i];
		}
	}

	int max = 0;
	for (int i = 0; i < N; i++)
	{
		if (sum[i] > max)
			max = sum[i];
	}
	cout << max;

	return 0;
}