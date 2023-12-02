// 백준 1920번: 수 찾기
// 이분 탐색할 때에는 정수 나누기에서 나머지 버림되는 특성으로 인해 (begin + end)/2 < begin이 될 수 있음에 주의할 것

#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int N, M;
	int* A;

	cin >> N;
	A = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	sort(A, A + N);

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int start = 0, end = N-1, half;
		int target;
		cin >> target;
		while (true)
		{
			half = (start + end) / 2;
			if (A[half] == target)
			{
				cout << "1\n";
				break;
			}
			if (start >= end)
			{
				cout << "0\n";
				break;
			}
			if (target > A[half])
			{
				start = half + 1;
			}
			else
			{
				end = half - 1;
			}
		}
	}

	return 0;
}