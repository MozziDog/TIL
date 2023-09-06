// 백준 1021번 : 유기농 배추
// 1트에 성공

#include <bits/stdc++.h>

using namespace std;

const int dx[] = { 1, 0, -1, 0 };
const int dy[] = { 0, 1, 0, -1 };

int farm[50][50];
int M, N;

void bfs(int startX, int startY)
{
	queue<pair<int, int>> que;
	farm[startY][startX] = 0;
	que.push({ startY, startX });
	while (!que.empty())
	{
		int cury = que.front().first;
		int curx = que.front().second;
		que.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int ny = cury + dy[dir];
			int nx = curx + dx[dir];
			if(nx >= 0 && nx < M && ny >=0 && ny < N)
			{
				if (farm[ny][nx] == 1)
				{
					farm[ny][nx] = 0;
					que.push({ ny, nx });
				}
			}
		}
	}
}

int fill(int width, int height)
{
	int ans = 0;
	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{
			if (farm[y][x] == 1)
			{
				bfs(x, y);
				ans++;
			}
		}
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int T, K, X, Y;

	cin >> T;
	for (int testCase = 0; testCase < T; testCase++)
	{
		cin >> M >> N >> K;
		// 배열 초기화는 필요 없음.
		for (int worm = 0; worm < K; worm++)
		{
			cin >> X >> Y;
			farm[Y][X] = 1;
		}
		// bfs
		cout << fill(M, N) << "\n";
	}
	return 0;
}