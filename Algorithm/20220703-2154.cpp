// 백준 2164번 : 카드2
// https://www.acmicpc.net/problem/2164

#include <iostream>
#include <deque>

int main()
{
	int N;
	std::cin >> N;

	std::deque<int> dq;
	for (int i = 1; i <= N; i++)
	{
		dq.push_back(i);
	}
	for (int i = 0; i < N-1; i++)
	{
		dq.pop_front();
		int tmp = dq.front();
		dq.pop_front();
		dq.push_back(tmp);
	}
	std::cout << dq.front();
	return 0;
}