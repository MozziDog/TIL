// 백준 18808번: 스티커 붙이기
// windows에서만 그런 건지는 모르겠는데 return type이 non-void인 함수가 return문을 만나지 못하고 함수 몸체 끝에 다다르게 되면 숫자 1을 리턴하고 종료되는 것 같다.
// 채점 시스템(linux)에서는 얄짤없이 WithoutReturning 런타임 에러 발생함.

#include <bits/stdc++.h>
using namespace std;

typedef struct s
{
	int row, col, area;
	bool shape[10][10];
} Sticker;

int N, M, K;
int stickerCount = 0;
Sticker stickers[100];
bool isSticked[40][40];
int stickedArea = 0;

bool trySticker(int stickerIndex, int startRow, int startCol)
{
	// 테스트
	for (int cy = 0; cy < stickers[stickerIndex].row; cy++)
	{
		for (int cx = 0; cx < stickers[stickerIndex].col; cx++)
		{
			if (stickers[stickerIndex].shape[cy][cx] && isSticked[startRow + cy][startCol + cx])
				return false;
		}
	}
	// 테스트 통과
	for (int cy = 0; cy < stickers[stickerIndex].row; cy++)
	{
		for (int cx = 0; cx < stickers[stickerIndex].col; cx++)
		{
			if (stickers[stickerIndex].shape[cy][cx])
				isSticked[startRow + cy][startCol + cx] = true;
		}
	}
	stickedArea += stickers[stickerIndex].area;
	return true;
}

void rotateClockwise(int index)
{
	bool cp[10][10];
	int exRow = stickers[index].row;
	int exCol = stickers[index].col;
	for (int newRow = 0; newRow < stickers[index].col; newRow++)
	{
		for (int newCol = 0; newCol < stickers[index].row; newCol++)
		{
			cp[newRow][newCol] = stickers[index].shape[exRow - newCol - 1][newRow];
		}
	}
	int tmp = stickers[index].row;
	stickers[index].row = stickers[index].col;
	stickers[index].col = tmp;
	for (int i = 0; i < stickers[index].row; i++)
		memcpy(&stickers[index].shape[i], &cp[i], sizeof(bool) * stickers[index].col);
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> N >> M >> K;
	for (int stk = 0; stk < K; stk++)
	{
		int area = 0;
		Sticker newSticker;
		cin >> newSticker.row >> newSticker.col;
		for(int r = 0; r< newSticker.row; r++)
			for (int c = 0; c < newSticker.col; c++)
			{
				bool b;
				cin >> b;
				newSticker.shape[r][c] = b;
				if (b == true) area++;
			}
		newSticker.area = area;
		stickers[stk] = newSticker;
		stickerCount++;
	}

	for (int stk = 0; stk < stickerCount; stk++)
	{
		bool isSuccess = false;
		// 회전 4방향
		for (int rot = 0; rot < 4; rot++)
		{
			// 세로
			for (int r = 0; r <= (N - stickers[stk].row); r++)
			{
				// 가로
				for (int c = 0; c <= (M - stickers[stk].col); c++)
				{
					if(isSuccess = trySticker(stk, r, c))
						break;
				}
				if (isSuccess)
					break;
			}
			if (isSuccess)
				break;

			// 회전시키기
			rotateClockwise(stk);
		}
	}

	cout << stickedArea;
	return 0;
}