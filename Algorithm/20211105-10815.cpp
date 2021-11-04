// https://www.acmicpc.net/problem/10815
// 어제 푼 문제랑 똑같은 문제인데...?

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int N, M;
	scanf_s("%d", &N);
	int* A = new int[N];
	for (int i = 0; i < N; i++)
	{
		scanf_s("%d", &A[i]);
	}
	std::sort(A, A + N);

	scanf_s("%d", &M);
	for (int i = 0; i < M; i++)
	{
		int target;
		scanf_s("%d", &target);

		int rangeStart = 0, rangeEnd = N - 1;
		int halfPoint;

		while (true)
		{
			halfPoint = (rangeStart + rangeEnd) / 2;
			if (A[halfPoint] == target)
			{
				printf("1 ");
				break;
			}
			else if (rangeStart >= rangeEnd)
			{
				printf("0 ");
				break;
			}
			else if (A[halfPoint] > target)
			{
				rangeEnd = halfPoint - 1;
			}
			else if (A[halfPoint] < target)
			{
				rangeStart = halfPoint + 1;
			}
		}
	}

	return 0;
}