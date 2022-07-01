// 백준 1024번 : 수열의 합
// https://www.acmicpc.net/problem/1024
// 참고한 페이지 : https://sexycoder.tistory.com/97

# include <iostream>

int main()
{
	int N, L, begin = -1;	// 합이 N, 길이가 L ~ 100
	std::cin >> N >> L;

	while (L <= 100)
	{
		int t = N - (L - 1)*L/2;
		if (t % L == 0 && t / L >= 0)
		{
			begin = t/L;
			break;
		}
		else
			L++;
	}
	if(begin == -1)
		std::cout << "-1";
	else
		for (int i = begin; i < begin + L; i++)
			std::cout << i << " ";
	return 0;
}