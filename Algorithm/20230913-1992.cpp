// 백준 1992번: 쿼드트리
#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<char>> image;

string rec(int, int, int);

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> N;
	image.reserve(N);
	for (int r = 0; r < N; r++)
	{
		vector<char> row;
		row.reserve(N);
		for (int c = 0; c < N; c++)
		{
			char pixel;
			cin >> pixel;
			row.push_back(pixel);
		}
		image.push_back(row);
	}

	cout << rec(0, 0, N);
	
	return 0;
}

string rec(int startR, int startC, int size)
{
	string ret;
	char quadColor = image[startR][startC];
	for (int i = startR; i < startR + size; i++)
	{
		for (int j = startC; j < startC + size; j++)
		{
			if (image[i][j] != quadColor)
			{
				int newSize = size / 2;
				ret += '(';
				ret += rec(startR, startC, newSize);
				ret += rec(startR, startC + newSize, newSize);
				ret += rec(startR + newSize, startC, newSize);
				ret += rec(startR + newSize, startC + newSize, newSize);
				ret += ')';
				return ret;
			}
		}
	}
	ret.push_back(quadColor);
	return ret;
}