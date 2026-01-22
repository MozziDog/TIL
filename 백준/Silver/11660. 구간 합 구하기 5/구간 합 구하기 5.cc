#include <bits/stdc++.h>
#define llong long long
using namespace std;

int N, M;
int num[1024][1024];
llong sum[1024][1024];

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> M;
	for(int i=0; i<N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> num[i][j];
			sum[i][j] = (i - 1 >= 0 ? sum[i - 1][j] : 0)
				+ (j - 1 >= 0 ? sum[i][j - 1] : 0)
				- (i - 1 >= 0 && j - 1 >= 0 ? sum[i - 1][j - 1] : 0)
				+ num[i][j];
		}

	for (int i = 0; i < M; i++)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		x1--; y1--; x2--; y2--;
		llong ans = sum[x2][y2]
			- (x1 - 1 >= 0 ? sum[x1 - 1][y2] : 0)
			- (y1 - 1 >= 0 ? sum[x2][y1 - 1] : 0)
			+ (x1 - 1 >= 0 && y1 - 1 >= 0 ? sum[x1 - 1][y1 - 1] : 0);
		cout << ans << '\n';
	}
	return 0;
}