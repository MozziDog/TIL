// 백준 10026번 : 적록색약
// 1트 성공. 근데 이거보다 코드를 더 깔끔하게는 안될까?
// 아! 알고리즘을 수정할 생각을 하지 말고 데이터를 전처리해주면 되는구나!

#include <bits/stdc++.h>

using namespace std;

int n;
vector<string> grid;
bool vis_normal[100][100];
bool vis_colorweak[100][100];

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

void bfs_normal (int row, int column)
{
	queue<pair<int, int>> que;
	que.push({ row, column });
	while (!que.empty())
	{
		int cx = que.front().first, cy = que.front().second;
		que.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cx + dx[dir], ny = cy + dy[dir];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n)
			{
				if (grid[cx][cy] == grid[nx][ny] && vis_normal[nx][ny] == false)
				{
					que.push({ nx,ny });
					vis_normal[nx][ny] = true;
				}
			}
		}
	}
}

void bfs_colorweak(int row, int column)
{
	queue<pair<int, int>> que;
	que.push({ row, column });
	while (!que.empty())
	{
		int cx = que.front().first, cy = que.front().second;
		que.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cx + dx[dir], ny = cy + dy[dir];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n)
			{
				if ((grid[cx][cy] == grid[nx][ny] || (grid[cx][cy] != 'B' && grid[nx][ny] != 'B')) && vis_colorweak[nx][ny] == false)
				{
					que.push({ nx,ny });
					vis_colorweak[nx][ny] = true;
				}
			}
		}
	}
}

int main()
{
	int ans_normal=0, ans_colorweak=0;
	cin >> n; cin.ignore();
	for (int i = 0; i < n; i++)
	{
		string str;
		getline(cin, str);
		grid.push_back(str);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (vis_normal[i][j] == false)
			{
				bfs_normal(i, j);
				ans_normal++;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (vis_colorweak[i][j] == false)
			{
				bfs_colorweak(i, j);
				ans_colorweak++;
			}
		}
	}

	cout << ans_normal << " " << ans_colorweak;
	return 0;
}