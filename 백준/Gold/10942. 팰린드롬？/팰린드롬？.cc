#include <bits/stdc++.h>
using namespace std;

int N, M;
int S[4001];
int manacher[4001];

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> S[2 * i + 1];
	}
	
	int i, j, p, l, r = -1;
	int len = 2 * N + 1;
	
	for (int i = 0; i < len; i++)
	{
		if (i > r) {
			p = r = i;
			while (r < len && r <= 2 * p && S[r] == S[2 * p - r])
				r++;
			r--;
			manacher[i] = r - p;
		}
		else
		{
			j = 2 * p - i;
			if (manacher[j] < r - i)
				manacher[i] = manacher[j];
			else if (manacher[j] > r - i)
				manacher[i] = r - i;
			else
			{
				p = i;
				while (r < len && r <= 2 * p && S[r] == S[2 * p - r])
					r++;
				r--;
				manacher[i] = r - p;
			}
		}
	}

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int S, E;
		cin >> S >> E;
		cout << (manacher[S + E - 1] > (E - S)) << '\n';
	}
	return 0;
}