// https://www.acmicpc.net/problem/13458
// int 형의 범위에 주의
// float 형의 정밀도에 주의. (유효 숫자는 6자리) {ceil((float) A[i]/C)} 하려다가 float 정밀도 때문에 오차 발생함.

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, * A, B, C;

	cin >> N;
	A = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	cin >> B >> C;

	long long answer = 0;	
	for (int i = 0; i < N; i++)
	{
		A[i] -= B; answer++;
		if (A[i] > 0)
		{
			answer += A[i] / C;
			if (A[i] % C != 0)
				answer++;
		}
	}

	cout << answer;
	return 0;
}