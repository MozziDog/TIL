// 백준 2468번: 안전 영역
#include <bits/stdc++.h>
using namespace std;

int N;
int arr[100][100];
bool visited[100][100];

static int dx[] = { 1, 0, -1, 0 };
static int dy[] = { 0, -1, 0, 1 };

void bfs(int startY, int startX, int height)
{
	if (visited[startY][startX] == true || arr[startY][startX] <= height)
		return;
	visited[startY][startX] = true;
	for (int dir = 0; dir < 4; dir++)
	{
		int cy = startY + dy[dir];
		int cx = startX + dx[dir];
		if (cy < 0 || cy >= N || cx < 0 || cx >= N)
			continue;
		bfs(cy, cx, height);
	}
}

int main()
{
	int answer = 1;
	int maxHeight = 0;

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
			maxHeight = max(maxHeight, arr[i][j]);
		}
	}

	for (int height = 1; height <= maxHeight; height++)
	{
		int curAnswer = 0;
		fill(&visited[0][0], &visited[99][99], false);
		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < N; x++)
			{
				if (visited[y][x] == false && arr[y][x] > height)
				{
					bfs(y, x, height);
					curAnswer++;
				}
			}
		}
		answer = max(answer, curAnswer);
	}

	cout << answer;
	return 0;
}