// 백준 9372번: 상근이의 여행
// 아니 문제가 너무 허접한 것 같아서 이게 맞나? 싶었는데 이게 맞았다니
// 굉장히 허무하다

#include <bits/stdc++.h>
using namespace std;

int T, N, M, A, B;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> T;
	while (T--)
	{
		cin >> N >> M;
		while (M--)
		{
			cin >> A >> B;
		}
		cout << N - 1 << '\n';
	}

	return 0;
}