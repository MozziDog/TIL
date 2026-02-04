#include <bits/stdc++.h>
using namespace std;

#define y first
#define x second

const int RED_ESCAPED = 0b10;
const int BLUE_ESCAPED = 0b01;

int N, M;
vector<string> board;

typedef struct s
{
	pair<int, int> red;
	pair<int, int> blue;
} state;

// 0b00: 아무 공도 안들어감
// 0b01: 파란 공만 들어감
// 0b10: 빨간 공만 들어감
// 0b11: 둘 다 들어감
int push(state in, state& out, pair<int,int> delta)
{
	int result = 0;

	bool redMoving = true, blueMoving = true;

	auto redCur = in.red, blueCur = in.blue;
	while (redCur.y >= 0 && redCur.y < N && redCur.x >= 0 && redCur.x < M && (redMoving || blueMoving))
	{
		switch (board[redCur.y][redCur.x])
		{
		case 'O':
			redMoving = false;
			result |= RED_ESCAPED;
			break;
		case '#':
			redMoving = false;
			redCur.x -= delta.x;
			redCur.y -= delta.y;
			break;
		}
		
		switch (board[blueCur.y][blueCur.x])
		{
		case 'O':
			blueMoving = false;
			result |= BLUE_ESCAPED;
			break;
		case '#':
			blueMoving = false;
			blueCur.x -= delta.x;
			blueCur.y -= delta.y;
			break;
		}

		if (redCur.x == blueCur.x && redCur.y == blueCur.y)
		{
			redMoving = false;
			blueMoving = false;
			break;
		}

		if (redMoving)
		{
			out.red = redCur;
			redCur.x += delta.x;
			redCur.y += delta.y;
		}
		if (blueMoving)
		{
			out.blue = blueCur;
			blueCur.x += delta.x;
			blueCur.y += delta.y;
		}
	}
	
	return result;
}

int bfs(state startState)
{
	queue<pair<state, int>> que;	// 빨강 좌표, 파랑 좌표, depth

	que.push({ startState, 0 });
	while (!que.empty())
	{
		state s;
		int depth;
		tie(s, depth) = que.front(); que.pop();
		if (depth >= 10)
			break;

		const pair<int, int> delta[] = { {1, 0}, {-1, 0}, {0,1}, {0,-1} };
		for (int i = 0; i < 4; i++)
		{
			state out;
			int result = push(s, out, delta[i]);
			if (result & BLUE_ESCAPED)
				continue;
			else if (result & RED_ESCAPED)
				return depth + 1;
			else
				que.push({ out, depth + 1 });
		}
	}
	return -1;
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> M;
	
	pair<int, int> redCoord, blueCoord;

	for (int i = 0; i < N; i++)
	{
		string row;
		cin >> row;
		for (int j = 0; j < M; j++)
		{
			if (row[j] == 'R')
			{
				redCoord = { i, j };
				row[j] = '.';
			}
			if (row[j] == 'B')
			{
				blueCoord = { i, j };
				row[j] = '.';
			}
		}
		board.push_back(row);
	}

	cout << bfs({ redCoord, blueCoord });
	return 0;
}