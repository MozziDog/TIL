// 백준 15683번: 감시
// '카메라는 카메라를 통과할 수 있다'를 빼먹어서 한 번 틀림
#include <bits/stdc++.h>
using namespace std;

const int tdir[] = {0, 1, 0, 0, 
					0, 1, 0, 1, 
					1, 1, 0, 0,
					1, 1, 0, 1,
					1, 1, 1, 1};

typedef struct s {
	int row, col;
	int type;
	int dir;
} S1;

int N, M;
int room[8][8];
S1 cctv[8];
int cctvCount = 0;
int minBlindSpot = 999;


void paintVisibleSpot()
{
	int cx, cy;
	for (int i = 0; i < cctvCount; i++)
	{
		// 상
		if (tdir[4 * (cctv[i].type -1) + (4 - cctv[i].dir) % 4] == 1)
		{
			int cy = cctv[i].row - 1, cx = cctv[i].col;
			while (cy >= 0 && cy < N && room[cy][cx] != 6)
			{
				if(room[cy][cx] == 0)
					room[cy][cx] = '#'; 
				cy--;
			}
		}
		// 우
		if (tdir[4 * (cctv[i].type - 1) + (5 - cctv[i].dir) % 4] == 1)
		{
			int cy = cctv[i].row, cx = cctv[i].col + 1;
			while (cx >= 0 && cx < M && room[cy][cx] != 6)
			{
				if (room[cy][cx] == 0)
					room[cy][cx] = '#';
				cx++;
			}
		}
		// 하
		if (tdir[4 * (cctv[i].type - 1) + (6 - cctv[i].dir) % 4] == 1)
		{
			int cy = cctv[i].row + 1, cx = cctv[i].col;
			while (cy >= 0 && cy < N && room[cy][cx] != 6)
			{
				if (room[cy][cx] == 0)
					room[cy][cx] = '#';
				cy++;
			}
		}
		// 좌
		if (tdir[4 * (cctv[i].type - 1) + (7 - cctv[i].dir) % 4] == 1)
		{
			int cy = cctv[i].row, cx = cctv[i].col - 1;
			while (cx >= 0 && cx < M && room[cy][cx] != 6)
			{
				if (room[cy][cx] == 0)
					room[cy][cx] = '#';
				cx--;
			}
		}
	}
}

void UnpaintVisibleSpot()
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (room[i][j] == '#')
				room[i][j] = 0;
}

int countBlindSpot()
{
	int result = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (room[i][j] == 0) result++;
	return result;
}

void solve(int camIdx)
{
	if (camIdx == cctvCount)
	{
		paintVisibleSpot();
		if (countBlindSpot() < minBlindSpot)
		{
			minBlindSpot = countBlindSpot();
		}
		UnpaintVisibleSpot();
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		cctv[camIdx].dir = i;
		solve(camIdx + 1);
	}
}


int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int tmp;

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> tmp;
			room[i][j] = tmp;
			if (tmp >= 1 && tmp <= 5)
			{

				cctv[cctvCount++] = { i, j, tmp, 0 };
			}
		}
	}

	solve(0);

	cout << minBlindSpot;

	return 0;
}