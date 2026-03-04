#include <bits/stdc++.h>
using namespace std;

const int MAXN = 16;

int N, T[MAXN], P[MAXN];
int DP[MAXN];

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> T[i] >> P[i];
	}

	for (int i = 1; i <= N; i++)
	{
		int endDay = i + T[i] - 1;
		if (endDay > N)
			continue;
		
		for (int j = endDay + 1; j <= N+1; j++)
		{
			DP[j] = max(DP[j], DP[i] + P[i]);
		}
	}

	cout << DP[N + 1];
	return 0;
}