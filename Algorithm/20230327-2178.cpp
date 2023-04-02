// 백준 2178번: 미로 탐색

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define X first
#define Y second

int dx[] = { 0, 1, 0, -1 }, dy[] = { 1, 0, -1, 0 };

int main()
{
	int n, m;
	vector<vector<int>> map;
	queue<pair<int, int>> que;

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		vector<int> tmp;
		getchar();  // ignore \n
		for (int j = 0; j < m; j++)
		{
			tmp.push_back(getchar() == '1' ? 99999 : -1);	// 지나갈 수 없으면 -1, 있으면 시작점으로부터의 거리
		}
		map.push_back(tmp);
	}
	
	que.push({ 0,0 });
	map[0][0] = 1;

	while (!que.empty())
	{
		pair<int, int> cell = que.front(); que.pop();
		if (cell.first == n - 1 && cell.second == m - 1) break;
		for (int i = 0; i < 4; i++)
		{
			int nx = cell.X + dx[i];
			int ny = cell.Y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
			if (map[nx][ny] != -1 && map[nx][ny] > map[cell.X][cell.Y] + 1)
			{		// visit
				map[nx][ny] = map[cell.X][cell.Y] + 1;
				que.push({nx, ny});
			}
		}
	}

	cout << map[n - 1][m - 1];
	
	return 0;
}