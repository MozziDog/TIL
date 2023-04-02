// 백준 4179번: 불!
// 오늘의 교훈: 조건문에 조건 추가할 때 주의하자

#include <bits/stdc++.h>

#define X first
#define Y second

using namespace std;

const int dx[] = { 1, 0, -1, 0 }, dy[] = { 0, 1, 0, -1 };
vector<vector<char>> maze;
bool vis_jihoon[1000][1000], vis_fire[1000][1000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int r, c;
	
	cin >> r >> c;

	queue<pair<int, int>> jihoon, fire;

	for (int i = 0; i < r; i++)
	{
		vector<char> row;
		char tmp;
		for (int j = 0; j < c; j++)
		{
			cin >> tmp;
			row.push_back(tmp);
			if (tmp == 'J')
			{
				jihoon.push({ i, j });
				vis_jihoon[i][j] = true;
			}
			if (tmp == 'F')
			{
				fire.push({ i,j });
				vis_fire[i][j] = true;
			}
		}
		maze.push_back(row);
	}

	int minute = 0;

	while (!jihoon.empty())
	{
		// 불이랑 지훈이가 동시에 같은 타일에 있으면 안되므로 불이 먼저 번짐
		int fireCount = fire.size();
		for (int i=0; i<fireCount; i++)
		{
			int fx = fire.front().X, fy = fire.front().Y;
			fire.pop();
			for (int dir = 0; dir < 4; dir++)
			{
				int nx = fx + dx[dir], ny = fy + dy[dir];
				if (nx >= 0 && nx < r && ny >= 0 && ny < c) // 맵 범위 내부
				{
					if (vis_fire[nx][ny] == false && ( maze[nx][ny] == '.' || maze[nx][ny] == 'J'))
					{
						vis_fire[nx][ny] = true;
						maze[nx][ny] = 'F';
						fire.push({ nx, ny });
					}
				}
			}
		}

		// 지훈이가 나중에 움직임
		int jihoonCount = jihoon.size();
		for(int i=0; i<jihoonCount; i++)
		{
			int jx = jihoon.front().X, jy = jihoon.front().Y;
			jihoon.pop();
			for (int dir = 0; dir < 4; dir++)
			{
				int nx = jx + dx[dir], ny = jy + dy[dir];
				if (nx >= 0 && nx < r && ny >= 0 && ny < c) // 맵 멈위 내부
				{
					if (vis_jihoon[nx][ny] == false && maze[nx][ny] == '.')
					{
						vis_jihoon[nx][ny] = true;
						maze[nx][ny] = 'J';	// 지나갔던 곳 체크
						jihoon.push({ nx, ny });
					}
				}
				else										// 탈출
				{
					cout << minute + 1;
					return 0;
				}
			}
		}

		// 시간 1분 경과
		minute++;
	}

	cout << "IMPOSSIBLE";
	return 0;
}