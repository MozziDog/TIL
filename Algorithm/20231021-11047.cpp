// 백준 11047번: 동전 0

#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int N, K, answer = 0;
	vector<int> faceValue;
	
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		int c;
		cin >> c;
		faceValue.push_back(c);
	}

	for (auto i = faceValue.rbegin(); i < faceValue.rend(); i++)
	{
		int curCoinCount = (K / *i);
		answer += curCoinCount;
		K -= (*i) * curCoinCount;
	}

	cout << answer;
	return 0;
}