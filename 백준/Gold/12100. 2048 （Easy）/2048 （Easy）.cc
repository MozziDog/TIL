#include <bits/stdc++.h>
using namespace std;

int n;
typedef vector<vector<int>> board;

board move(board in, int dx, int dy)
{
	board newb;
	vector<int> r(n, 0);
	newb.resize(n, r);
	// 좌우로 밀기
	if (dx != 0)
	{
		for (int r = 0; r < in.size(); r++)
		{
			int curNew = dx > 0 ? 0 : in.size() - 1, curOld = curNew;
			while (curNew >= 0 && curNew < in.size())
			{
				while (curOld < in.size() && curOld >= 0 && in[r][curOld] == 0)
					curOld += dx;
				if (curOld < 0 || curOld >= in.size())
					break;

				int curNum = in[r][curOld];

				do {
					curOld += dx;
				} while (curOld < in.size() && curOld >= 0 && in[r][curOld] == 0);

				if (curOld >= in.size() || curOld < 0)
				{
					newb[r][curNew] = curNum;
					break;
				}
				if (in[r][curOld] == curNum)
				{
					newb[r][curNew] = curNum * 2;
					curNew += dx;
					curOld += dx;
				}
				else
				{
					newb[r][curNew] = curNum;
					curNew += dx;
				}
			}
		}
	}
	// 상하로 밀기
	else
	{
		for (int c = 0; c < in.size(); c++)
		{
			int curNew = dy > 0 ? 0 : in.size() - 1, curOld = curNew;
			while (curNew >= 0 && curNew < in.size())
			{
				while (curOld < in.size() && curOld >= 0 && in[curOld][c] == 0)
					curOld += dy;
				if (curOld < 0 || curOld >= in.size())
					break;

				int curNum = in[curOld][c];

				do {
					curOld += dy;
				} while (curOld < in.size() && curOld >= 0 && in[curOld][c] == 0);

				if (curOld >= in.size() || curOld < 0)
				{
					newb[curNew][c] = curNum;
					break;
				}
				if (in[curOld][c] == curNum)
				{
					newb[curNew][c] = curNum * 2;
					curNew += dy;
					curOld += dy;
				}
				else
				{
					newb[curNew][c] = curNum;
					curNew += dy;
				}
			}
		}
	}
	return newb;
}

int dfs(board b, int dx, int dy, int depth)
{
	if (depth == 5)
	{
		int ans = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				ans = max(ans, b[i][j]);
		return ans;
	}
	
	return max({ dfs(move(b, 1, 0), -1, 0, depth + 1),
				dfs(move(b, -1, 0), 1, 0, depth + 1),
				dfs(move(b, 0, 1), 0, -1, depth + 1),
				dfs(move(b, 0, -1), 0, 1, depth + 1) });
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> n;
	board b;
	vector<int> r(n, 0);
	b.resize(n, r);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> b[i][j];

	cout << dfs(b, 0, 0, 0);
	return 0;
}