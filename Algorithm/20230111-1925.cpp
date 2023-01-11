// 백준 1926번 : 그림
#include <iostream>
#include <queue>

using namespace std;

int n, m;
int** grid;

int findDrawing(int start_x, int start_y)
{
	int size = 0;
	queue<pair<int, int>> que;
	int row = start_x, column = start_y;

	grid[row][column] = 0;
	que.push({ row, column });
	while (que.size() > 0) {
		row = que.front().first;
		column = que.front().second;
		if (row > 0 && grid[row - 1][column]==1)
		{
			grid[row - 1][column] = 0;
			que.push({ row - 1, column });
		}
		if (row < n-1 && grid[row + 1][column] == 1)
		{
			grid[row + 1][column] = 0;
			que.push({ row + 1, column });
		}
		if (column > 0 && grid[row][column-1] == 1)
		{
			grid[row][column-1] = 0;
			que.push({ row, column -1 });
		}
		if (column < m - 1 && grid[row][column+1] == 1)
		{
			grid[row][column+1] = 0;
			que.push({ row, column +1});
		}
		que.pop();
		size++;
	}
	return size;
}

int main()
{
	int maxImageSize = 0, imageCount = 0;
	cin >> n >> m;

	grid = new int* [n];
	for (int i = 0; i < n; i++)
	{
		grid[i] = new int[m];
		for (int j = 0; j < m; j++)
		{
			cin >> grid[i][j];
		}
	}

	for(int i=0; i<n; i++)
		for (int j = 0; j < m; j++)
		{
			if (grid[i][j] == 1)
			{
				int imageSize = findDrawing(i, j);
				imageCount++;
				if ( imageSize > maxImageSize)
				{
					maxImageSize = imageSize;
				}
			}
		}

	cout << imageCount << '\n' << maxImageSize;
	return 0;
}