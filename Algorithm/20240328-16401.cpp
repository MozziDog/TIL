// 백준 16401번: 과자 나눠주기
// 왜 자꾸 틀리나 했더니 정렬을 까먹었었음 ㅋㅋㅋ
// 로직 자체는 맞았다

#include <bits/stdc++.h>
using namespace std;

int M, N;
vector<int> L;
int result = 0;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> M >> N;

	L.resize(N);
	for (int i = 0; i < N; i++)
	{
		int t;
		cin >> t;
		L[i] = t;
	}
	std::sort(L.begin(), L.end());

	int up = L[N - 1], down = 1;
	int mid;

	// 찾으려는 건 fn(i) = true인 최대의 i
	while (up >= down)
	{
		mid = (up + down) / 2;

		// 나눠줄 수 있는 개수 파악
		int count = 0;
		for (int i = 0; i < N; i++)
		{
			count += L[i] / mid;
		}

		if (count >= M)
		{
			result = mid;
			down = mid + 1;
		}
		
		else
		{
			up = mid - 1;
		}
	}

	cout << result;

	return 0;
}