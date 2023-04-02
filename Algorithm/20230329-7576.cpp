// 백준 7576번: 토마토

#include <iostream>
#include <vector>
#include <queue>

#define X first
#define Y second

using namespace std;

const int dx[] = { 1,0,-1, 0 };
const int dy[] = { 0, 1, 0, -1 };

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int m, n;
	cin >> m >> n;

	vector<vector<int>> farm;

	for (int i = 0; i < n; i++)
	{
		vector<int> row;
		int tmp;
		for (int j = 0; j < m; j++)
		{
			cin >> tmp;
			row.push_back(tmp);
		}
		farm.push_back(row);
	}

	queue<pair<int, int>> tomato;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (farm[i][j] == 1)
				tomato.push({ i,j });
		}
	}

	while (!tomato.empty())
	{
		int x = tomato.front().X, y = tomato.front().Y;
		tomato.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = x + dx[dir], ny = y + dy[dir];
			if (nx >= 0 && nx <= n - 1 && ny >= 0 && ny <= m - 1)
			{
				if (farm[nx][ny] == 0)
				{
					farm[nx][ny] = farm[x][y] + 1;
					tomato.push({ nx, ny });
				}
			}
		}
	}

	int maxTomato = 1;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (farm[i][j] == 0)
			{
				cout << -1;
				return 0; 
			}
			if (maxTomato < farm[i][j])
				maxTomato = farm[i][j];
		}
	}
	cout << maxTomato - 1;
	return 0;
}