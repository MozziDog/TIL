// 백준 7569번: 토마토

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef struct { int h, r, c; int day; } coordAndDays;
const int dh[] = { 1, -1, 0, 0, 0, 0 };	// 상 하 좌 우 전 후
const int dr[] = { 0, 0, 1, -1, 0, 0 };
const int dc[] = { 0, 0, 0, 0, 1, -1 };

int main()
{
	int M, N, H;
	int unripenCount = 0;
	vector<vector<vector<int>>> tomatoes;
	queue<coordAndDays> que;

	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin >> M >> N >> H;

	// 입력 받기
	int tmt;
	for (int height = 0; height < H; height++)
	{
		vector<vector<int>> t1;
		for (int row = 0; row < N; row++)
		{
			vector<int> t2;
			for (int column = 0; column < M; column++)
			{
				cin >> tmt;
				t2.push_back(tmt);
				if (tmt == 1)
				{
					que.push({ height, row, column, 0 });
				}
				if (tmt == 0)
				{
					unripenCount++;
				}
			}
			t1.push_back(t2);
		}
		tomatoes.push_back(t1);
	}

	// 문제풀이
	while (!que.empty())
	{
		coordAndDays front = que.front();
		int hc, rc, cc;
		for (int i = 0; i < 6; i++)
		{
			hc = front.h + dh[i];
			rc = front.r + dr[i];
			cc = front.c + dc[i];
			if (hc < 0 || hc >= H) continue;
			if (rc < 0 || rc >= N) continue;
			if (cc < 0 || cc >= M) continue;
					
			if (tomatoes[hc][rc][cc] == 0)
			{
				tomatoes[hc][rc][cc] = 1;
				unripenCount--;
				que.push({ hc, rc, cc, front.day + 1 });
			}
		}
		if (que.size() == 1)
			break;
		que.pop();
	}
	if (unripenCount == 0)
	{
		if (que.empty())
			cout << 0;
		else
			cout << que.front().day;	
	}
	else
		cout << -1;
	return 0;
}