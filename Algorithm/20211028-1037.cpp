// https://www.acmicpc.net/problem/1037
// 정렬은 귀찮아서 제공해주는 거 썼음

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int numOfDivisor;
	scanf("%d", &numOfDivisor);
	std::vector<int> divisors;
	int tmp;
	for (int i = 0; i < numOfDivisor; i++)
	{
		scanf("%d", &tmp);
		divisors.push_back(tmp);
	}
	std::sort(divisors.begin(), divisors.end());
	int answer;
	if (numOfDivisor % 2 == 0) // 약수 갯수가 짝수
	{
		answer = divisors[numOfDivisor/2 - 1] * divisors[numOfDivisor/2];
	}
	else  // 약수 갯수가 홀수 = 어떤 수의 제곱.
	{
		answer = divisors[numOfDivisor / 2] * divisors[numOfDivisor / 2];
	}
	printf("%d", answer);
	return 0;
}
