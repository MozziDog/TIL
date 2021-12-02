// https://www.acmicpc.net/problem/1644
// 오늘의 교훈 : 분기 제어가 이상하다면 if문 뒤에 세미콜론 붙었나 잘 살펴보기

#include <iostream>
#include <vector>

using namespace std;

const int MAX_NUM = 4000001;

void FindPrime(vector<int>& primes)
{
	bool* isNotPrime = new bool[MAX_NUM]();
	for (int i = 2; i < MAX_NUM; i++)
	{
		if (isNotPrime[i] == true)
			continue;
		for (int j = 2; i * j < MAX_NUM; j++)
		{
			isNotPrime[i * j] = true;
		}
	}
	for (int i = 2; i < MAX_NUM; i++)
	{
		if (isNotPrime[i] == false)
		{
			primes.push_back(i);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; vector<int> primes; int answer = 0;
	cin >> N;

	FindPrime(primes);

	auto begin = primes.begin();
	auto end = begin;
	int sum = *begin;

	while (true)
	{
		if (sum <= N)
		{
			if (sum == N)
			{
				answer++;
			}
			end++;
			if (end == primes.end())
				break;
			sum += *end;
		}
		else if (sum > N)
		{
			sum -= *begin;
			if (*begin > N)
				break;
			begin++;
		}
	}

	cout << answer;
	return 0;
}