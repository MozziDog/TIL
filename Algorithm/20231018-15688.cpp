// 백준 15688번: 수 정렬하기 6
// 카운팅 정렬 연습

#include <bits/stdc++.h>

using namespace std;

int freq[2000001];

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	int N, num;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		cin >> num;
		freq[num + 1000000]++;
	}

	for (int i = 0; i < 2000001; i++)
	{
		if (freq[i] != 0)
		{
			for (int j = 0; j < freq[i]; j++)
			{
				cout << i - 1000000 << '\n';
			}
		}
	}
	return 0;
}