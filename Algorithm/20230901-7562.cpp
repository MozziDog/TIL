// 백준 7562번: 나이트의 이동
#include <iostream>
#include <queue>
using namespace std;

typedef struct s1{ int x, y, moveCount; } COORDMOVE;

const int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
const int dy[] = {2, 1, -1, -2, -2, -1, 1, 2};
bool visited[300][300];

int main()
{
	int testcase, I, srcx, srcy, dstx, dsty;
	queue<COORDMOVE> que;

	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> testcase;
	for (int t = 0; t < testcase; t++)
	{
		cin >> I >> srcx >> srcy >> dstx >> dsty;

		for (int i = 0; i < I; i++)
			for (int j = 0; j < I; j++)
				visited[i][j] = false;

		que.push({ srcx, srcy, 0 });
		while (!que.empty())
		{
			COORDMOVE tmp = que.front();
			que.pop();
			if (tmp.x == dstx && tmp.y == dsty)
			{
				cout << tmp.moveCount << "\n";
				break;
			}
			for (int i = 0; i < 8; i++)
			{
				int tx = tmp.x + dx[i], ty = tmp.y + dy[i];
				if (tx < 0 || tx >= I || ty < 0 || ty >= I)
					continue;
				if (visited[tx][ty] == false)
				{
					que.push({ tx, ty, tmp.moveCount + 1 });
					visited[tx][ty] = true;
				}
			}
		}

		// clear the queue
		queue<COORDMOVE> emptyque;
		que.swap(emptyque);
	}
	return 0;
}