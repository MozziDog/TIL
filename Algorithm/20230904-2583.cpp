// 백준 2583번: 영역 구하기

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int bfs_fill(int, int);

const int dx[] = { 1, 0, -1, 0 }, dy[] = { 0, -1, 0, 1 };
int M, N, K;
bool map[100][100];

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	vector<int> area;

	cin >> M >> N >> K;

	// draw rectangle
	for (int i = 0; i < K; i++)
	{
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int tx = x1; tx < x2; tx++)
		{
			for (int ty = y1; ty < y2; ty++)
			{
				map[ty][tx] = true;
			}
		}
	}

	// check undrew area
	for (int cy = 0; cy < M; cy++)
	{
		for (int cx = 0; cx < N; cx++)
		{
			if (map[cy][cx] == false)	// found undrew area
			{
				area.push_back(bfs_fill(cy, cx));
			}
		}
	}

	// sort result
	sort(area.begin(), area.end());

	cout <<  area.size() << '\n';
	for (int i = 0; i < area.size(); i++)
	{
		cout << area[i] << ' ';
	}
	return 0;
}

int bfs_fill(int sy, int sx)
{
	int size = 0;
	queue<pair<int, int>> que;
	que.push({ sy, sx });
	map[sy][sx] = true;
	while (!que.empty())
	{
		auto front = que.front();
		que.pop();
		size++;
		for (int dir = 0; dir < 4; dir++)
		{
			int ty = front.first + dy[dir], tx = front.second + dx[dir];
			if (tx < 0 || tx >= N || ty < 0 || ty >= M)
				continue;
			if (map[ty][tx] == false)
			{
				que.push({ ty, tx });
				map[ty][tx] = true;
			}
		}
	}
	return size;
}