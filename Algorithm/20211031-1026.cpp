// https://www.acmicpc.net/problem/1026

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	vector<int> A, B;
	int answer = 0;
	int tmp;
	scanf_s("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf_s("%d", &tmp);
		A.push_back(tmp);
	}
	for (int i = 0; i < N; i++)
	{
		scanf_s("%d", &tmp);
		B.push_back(tmp);
	}
	sort(A.begin(), A.end()); // 오름차순 정렬	
	for (int i = 0; i < N; i++)
	{
		int indexOfMax = 0;
		for (int j = 0; j < B.size(); j++)
		{
			if (B[j] > B[indexOfMax])
			{
				indexOfMax = j;
			}
		}
		answer += B[indexOfMax] * A[0];
		B.erase(B.begin() + indexOfMax);
		A.erase(A.begin());
	}
	printf("%d", answer);
	return 0;
}
