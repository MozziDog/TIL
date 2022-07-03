// 백준 18115번 : 카드 놓기
// https://www.acmicpc.net/problem/18115

# include <iostream>
# include <deque>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	std::cin >> N;
	int* A = new int[N];
	for (int i = 0; i < N; i++)
	{
		std::cin >> A[i];
	}
	std::deque<int> dq;
	int tmp;
	for (int i = N-1; i >= 0; i--)
	{
		switch(A[i])
		{
		case 1:
			dq.push_front(N - i);
			break;
		case 2:
			tmp = dq.front();
			dq.pop_front();
			dq.push_front(N - i);
			dq.push_front(tmp);
			break;
		case 3:
			dq.push_back(N - i);
		}
	}
	for (std::deque<int>::iterator i = dq.begin(); i < dq.end(); i++)
	{
		std::cout << *i << " ";
	}
	
	return 0;
}