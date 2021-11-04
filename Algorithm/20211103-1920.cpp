// https://www.acmicpc.net/problem/1920
// 시간 초과
// DP랑 재귀랑 시간복잡도에 차이가 있나ㅏ? 공간복잡도 차이만 있는 줄 알았는데


#include <iostream>
#include <algorithm>

#define index int*

using namespace std;
int* A;

bool Search(int, int, int);

int main()
{
	int N, M;
	scanf_s("%d", &N);
	A = new int[N];
	for (int i = 0; i < N; i++)
	{
		scanf_s("%d", &A[i]);
	}
	std::sort(A, A + N);
	
	scanf_s("%d", &M);
	for(int i=0; i<M; i++)
	{
		int target;
		scanf_s("%d", &target);
		printf("%d\n", Search(target, 0, N - 1));
	}

	return 0;
}

bool Search(int target, int SearchRangeBegin, int SearchRangeEnd)
{
	int halfPoint = (SearchRangeBegin + SearchRangeEnd) / 2;
	if (A[halfPoint] == target)
	{
		return true;
	}
	if (SearchRangeBegin == SearchRangeEnd)
	{
		return false;
	}
	if (A[halfPoint] > target)
	{
		return Search(target, SearchRangeBegin, halfPoint - 1);
	}
	if (A[halfPoint] < target)
	{
		return Search(target, halfPoint + 1, SearchRangeEnd);
	}
}