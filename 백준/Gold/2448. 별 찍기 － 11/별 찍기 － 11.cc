#include <bits/stdc++.h>
using namespace std;

string ans[1024 * 3];
string stars[3] = {
	"  *  ",
	" * * ",
	"*****",
};

void rec(int startX, int startY, int endX, int endY)
{
	if (endY - startY == 3)
	{
		for(int i=0; i<3; i++)
			for (int j = 0; j < 5; j++)
			{
				ans[startY + i][startX + j] = stars[i][j];
			}
		return;
	}

	int dx = ((endX - startX) - 1) / 2;
	int dy = (endY - startY) / 2;

	rec(startX + (dx + 1) / 2, startY, endX - (dx+1)/2, startY + dy);
	rec(startX, endY - dy, startX + dx, endY);
	rec(startX + dx + 1, endY - dy, endX, endY);
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		ans[i].resize(2 * N - 1, ' ');
	}
	rec(0, 0, 2 * N - 1, N);
	for (int i = 0; i < N; i++)
	{
		cout << ans[i] << '\n';
	}
	return 0;
}