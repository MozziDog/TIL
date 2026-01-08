#include <bits/stdc++.h>
using namespace std;

int L, R, C;
char building[30][30][30];
bool visited[30][30][30];

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	while (true)
	{
		cin >> L >> R >> C;
		if (L == 0 && R == 0 && C == 0) break;

		fill(&visited[0][0][0], &visited[29][29][29], false);
		
		tuple<int, int, int, int> start;
		for (int i = 0; i < L; i++)
		{
			for (int j = 0; j < R; j++)
			{
				for (int k = 0; k < C; k++)
				{
					char in;
					cin >> in;
					building[i][j][k] = in;
					if (in == 'S')
						start = make_tuple(i, j, k, 0);
				}
			}
		}

		bool escaped = false;
		queue<tuple<int, int, int, int>> que;		// 층, 행, 열, 코스트 순
		que.push(start);
		while (!que.empty())
		{
			int i, j, k, cost;
			tie(i, j, k, cost) = que.front(); que.pop();

			if (building[i][j][k] == 'E')
			{
				escaped = true;
				cout << "Escaped in " << cost << " minute(s).\n";
				break;
			}
		
			const int D[6][3] = { {1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1} };
			for (auto d : D)
			{
				int ni = i + d[0];
				int nj = j + d[1];
				int nk = k + d[2];
				if ((ni < 0 || ni >= L) || (nj < 0 || nj >= R) || (nk < 0 || nk >= C))
					continue;
				if (building[ni][nj][nk] == '#')
					continue;
				if (visited[ni][nj][nk])
					continue;
				visited[ni][nj][nk] = true;
				que.push(make_tuple(ni, nj, nk, cost + 1));
			}
		}
		if (!escaped)
			cout << "Trapped!\n";
	}

	return 0;
}