// 백준 1780번: 종이의 개수
// 재귀라 그런지 확실히 코스트가 높네요

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> matrix;
int answer_n1 = 0, answer_0 = 0, answer_p1 = 0;

void rec(int, int, int);
void addResult(int);

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);

	int N;

	cin >> N;

	matrix.reserve(N);
	for (int i = 0; i < N; i++)
	{
		int tmp;
		vector<int> row;
		row.reserve(N);
		for (int j = 0; j < N; j++)
		{
			cin >> tmp;
			row.push_back(tmp);
		}
		matrix.push_back(row);
	}

	rec(0, 0, N);

	cout << answer_n1 << '\n' << answer_0 << '\n' << answer_p1;
	return 0;
}

void rec(int startR, int startC, int size)
{
	int expectedUnify = matrix[startR][startC];
	for (int i = startR; i < startR + size; i++)
	{
		for (int j = startC; j < startC + size; j++)
		{
			if (matrix[i][j] != expectedUnify)
			{
				int newSize = size / 3;
				for (int k = 0; k < 3; k++)
				{
					for (int l = 0; l < 3; l++)
					{
						rec(startR + newSize * k, startC + newSize * l, newSize);
					}
				}
				return;
			}
		}
	}
	addResult(matrix[startR][startC]);
}

void addResult(int value)
{
	switch (value)
	{
	case -1:
		answer_n1++;
		break;
	case 0:
		answer_0++;
		break;
	case 1:
		answer_p1++;
		break;
	}
}