// 백준 20166번: 문자열 지옥에 빠진 호석
// 기본적으로 그래프 탐색 문제이지만 일반적으로 풀었다간 시간초과 나기 십상
// 가장 큰 파라미터가 문제의 갯수 K이므로, 오히려 미리 다 구해놓고 K가 들어올 때마다 미리 구해놓은 답을 리턴하면 되는 문제였다.
// 개별 문제의 사이즈는 아주 작으니까 가능했던 문제

#include <bits/stdc++.h>
using namespace std;

int n, m, k;
char matrix[10][10];
unordered_map<string, int> answers;

void dfs(int row, int col, string curStr)
{
	curStr.push_back(matrix[row][col]);
	answers[curStr]++;
	
	if (curStr.size() == 5)
		return;

	for(int dy = -1; dy <= 1; dy++)
		for (int dx = -1; dx <= 1; dx++)
		{
			if (dy == 0 && dx == 0) continue;
			int y = (row + dy + n) % n, x = (col + dx + m) % m;
			dfs(y, x, curStr);
		}
	return;
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> matrix[i][j];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			dfs(i, j, "");

	while (k--)
	{
		string toFind;
		cin >> toFind;
		cout << answers[toFind] << '\n';
	}
	return 0;
}