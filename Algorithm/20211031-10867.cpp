// https://www.acmicpc.net/problem/10867

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	// 1. 입력받기
	int N;
	scanf_s("%d", &N);
	vector<int> numbers;
	for (int i = 0; i < N; i++)
	{
		int tmp;
		scanf_s("%d", &tmp);
		numbers.push_back(tmp);
	}
	// 2. 정렬하기
	sort(numbers.begin(), numbers.end());
	// 3. 중복 제거
	int beforeNumber = numbers[0];
	int j = 0;
	for (int i = 1; i < N; i++)
	{
		j++;
		if (numbers[j] == beforeNumber)
		{
			numbers.erase(numbers.begin() + j);
			j--;
		}
		else
		{
			beforeNumber = numbers[j];
		}
	}
	// 4. 출력
	for (int i = 0; i < (int)numbers.size(); i++)
	{
		printf("%d ", numbers[i]);
	}
	return 0;

}