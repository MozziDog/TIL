// 백준 11399번: ATM
// 그냥 정렬해버리면 깔끔하게 해결되긴 하는데 이걸 그리디 알고리즘이라고 부를 수 있나?

#include <bits/stdc++.h>
using namespace std;

int P[1001];

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int N;
	int sum = 0, answer = 0;
	
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> P[i];
	}

	sort(&P[0], &P[N]);

	for (int i = 0; i < N; i++)
	{
		sum += P[i];
		answer += sum;
	}

	cout << answer;

	return 0;
}