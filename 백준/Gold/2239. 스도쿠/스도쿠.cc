#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> S;
vector<pair<int, int>> toFill;

bool IsGood(int r, int c, int n)
{
	int y1 = r / 3 * 3, y2 = y1 + 3;
	int x1 = c / 3 * 3, x2 = x1 + 3;
	for (int i = y1; i < y2; i++)
	{
		for (int j = x1; j < x2; j++)
		{
			if (S[i][j] == n) return false;
		}
	}
	for(int i=0; i<9; i++)
		if (S[i][c] == n) return false;
	for (int j = 0; j < 9; j++)
		if (S[r][j] == n) return false;
	return true;
}

void PrintAnswer(vector<vector<int>> S)
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
			cout << S[i][j];
		cout << '\n';
	}
}

void solve(int toFillidx)
{
	if (toFillidx == toFill.size())
	{
		PrintAnswer(S);
		exit(0);
	}

	int r, c;
	tie(r, c)  = toFill[toFillidx];

	for (int i = 1; i <= 9; i++)
	{
		if(IsGood(r, c, i))
		{
			S[r][c] = i;
			solve(toFillidx + 1);
			S[r][c] = 0;
		}
	}
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	for (int i = 0; i < 9; i++)
	{
		vector<int> row;
		for (int j = 0; j < 9; j++)
		{
			char c;
			cin >> c;
			row.push_back(c - '0');
		}
		S.push_back(row);
	}

	// 0 찾기
	int r, c;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (S[i][j] == 0)
			{
				toFill.push_back({ i, j });
			}
		}
	}

	solve(0);
	return 0;
}