// 백준 1654번: 랜선 자르기 (재도전)
// 아.... 로직의 문제가 아니라 자료형의 문제였다. maxLen이 최대 2^31 -1까지 가질 수 있다고 해서 안심했는데
// 거기에 1만 더해도 2^31이라서 int 범위를 벗어나기 때문.
// 그냥 왠만해서는 인덱스는 long long으로 써야겠네. 

#include "bits/stdc++.h"
using namespace std;

int K, N;
vector<int> len;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int maxLen = 0;

	cin >> K >> N;
	for (int i = 0; i < K; i++)
	{
		int t;
		cin >> t;
		len.push_back(t);
		maxLen = max(maxLen, t);
	}
	
	long long top = maxLen, bot = 1;
	long long mid;
	while (top >= bot)
	{
		mid = (top + bot) / 2;
		long long count = 0;
		for (int i = 0; i < K; i++)
		{
			count += len[i] / mid;
		}
		if (count >= N)
		{
			bot = mid + 1;
		}
		else
		{
			top = mid - 1;
		}
	}
	cout << top;

	return 0;
}