// https://www.acmicpc.net/problem/9663
// 브루트포스 & 백트래킹

#include <iostream>

using namespace std;

int N;
int answers = 0;

void solve();
void solve(int[], int);
bool isPromising(int[], int);

int main()
{
	scanf_s("%d", &N);
	solve();
	printf("%d", answers);
	return 0;
}

void solve()
{
	int chessBoard[15];
	solve(chessBoard, 0);
}

void solve(int chessBoard[], int row)
{
	if (row == N)
	{
		// 마지막까지 돌았을 경우
		answers++;
	}
	else
	{
		for (int i = 0; i < N; i++)
		{
			chessBoard[row] = i;
			if (isPromising(chessBoard, row))
			{
				solve(chessBoard, row + 1);
			}
		}
	}
}

bool isPromising(int chessBoard[], int lastRow)
{
	for (int i = 0; i < lastRow; i++)
	{
		// 가로방향은 검사 안해도 됨
		// 세로방향 검사
		if (chessBoard[i] == chessBoard[lastRow])
			return false;
		// 우상향 대각선방향 검사
		if (chessBoard[i] - chessBoard[lastRow] == (lastRow - i)) // 열 차이 == 행 차이
			return false;
		// 우하향 대각선방향 검사
		if (chessBoard[lastRow] - chessBoard[i] == (lastRow - i))
			return false;
	}
	return true;
}