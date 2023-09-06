// 백준 5427번: 불
// 로직이 바뀌지 않았는데 함수를 분리했더니 성공한 걸로 봐서 다음 테스트케이스로 넘어갈 때의 초기화 따위가 문제였나 봄.

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef struct { int y, x, moveCount; } COORDMOVE;
const int dx[] = { 1, 0, -1, 0 };
const int dy[] = { 0, -1, 0, 1 };

void solve();

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	int testCase;
	cin >> testCase;

	for (int t = 0; t < testCase; t++)
	{
		solve();
	}
	return 0;
}

void solve()
{
	int w, h;
	// input
	cin >> w >> h;
	queue<COORDMOVE> sanggun;
	queue<COORDMOVE> fire;
	vector<vector<char>> map;

	for (int y = 0; y < h; y++)
	{
		vector<char> row;
		char tmp;
		for (int x = 0; x < w; x++)
		{
			cin >> tmp;
			row.push_back(tmp);

			if (tmp == '@')
			{
				sanggun.push({ y, x, 0 });
			}
			if (tmp == '*')
			{
				fire.push({ y, x, 0 });
			}
		}
		map.push_back(row);
	}

	// solve
	while (!sanggun.empty())
	{
		// fire moves first
		while (!fire.empty() && fire.front().moveCount <= sanggun.front().moveCount)
		{
			for (int i = 0; i < 4; i++)
			{
				int tx = fire.front().x + dx[i], ty = fire.front().y + dy[i];
				if (tx < 0 || tx >= w || ty < 0 || ty >= h)
					continue;
				if (map[ty][tx] == '#' || map[ty][tx] == '*')
					continue;
				map[ty][tx] = '*';
				fire.push({ ty, tx, fire.front().moveCount + 1 });
			}
			fire.pop();
		}
		
		// sanggun moves next
		int curMoveCount = sanggun.front().moveCount;
		while (!sanggun.empty() && sanggun.front().moveCount <= curMoveCount)
		{
			for (int i = 0; i < 4; i++)
			{
				int tx = sanggun.front().x + dx[i], ty = sanggun.front().y + dy[i];
				if (tx < 0 || tx >= w || ty < 0 || ty >= h)
				{
					std::cout << curMoveCount + 1 << '\n';
					return;
				}
				if (map[ty][tx] == '#' || map[ty][tx] == '*' || map[ty][tx] == '@')
					continue;
				map[ty][tx] = '@';
				sanggun.push({ ty, tx, curMoveCount + 1 });
			}
			sanggun.pop();
		}
	}
	std::cout << "IMPOSSIBLE\n";
}