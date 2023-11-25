// 백준 11501번: 주식
// 거꾸로 순회하는 거 적극적으로 사용하기. 거꾸로 순회하는 거 안하고 고점 인덱싱하면서 해보려다가 틀림.
// 그나저나 고점 인덱싱하는 거 맞는 풀이였던 것 같은데 어디서 틀린거지 반례를 모르겠네

#include <bits/stdc++.h>
using namespace std;

short stockPrice[1000001];

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int T;

	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int N;
		long long answer = 0;
		int stockHigh;
		
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			cin >> stockPrice[i];
		}

		stockHigh = stockPrice[N - 1];
		for (int i = N - 2; i >= 0; i--)
		{
			if (stockPrice[i] > stockHigh)
			{
				stockHigh = stockPrice[i];
			}
			else if (stockPrice[i] < stockHigh)
			{
				answer += stockHigh - stockPrice[i];
			}
		}

		cout << answer << '\n';
	}
	return 0;
}