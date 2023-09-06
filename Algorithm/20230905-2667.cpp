// 백준 2667번: 단지번호붙이기

#include <bits/stdc++.h>

using namespace std;

int N;
int imap[25][25];
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, -1, 0, 1};

int bfs(int, int);

int main()
{
	vector<int> answer;
	
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> N;
	for (int row = 0; row < N; row++)
	{
		string tmp;
		cin >> tmp;
		for (int col = 0; col < N; col++)
		{
			imap[row][col] = tmp[col] - '0';	// convert char to int
		}
	}

	for (int cr = 0; cr < N; cr++)
	{
		for (int cc = 0; cc < N; cc++)
		{
			if (imap[cr][cc] == 1)
			{
				answer.push_back(bfs(cr, cc));
			}
		}
	}
	sort(answer.begin(), answer.end());

	cout << answer.size() << '\n';
	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i] << '\n';
	}
	return 0;
}

int bfs(int startRow, int startCol)
{
	queue<pair<int, int>> que;
	int size = 0;

	que.push({ startRow, startCol });
	imap[startRow][startCol] = 2;
	while (!que.empty())
	{
		auto front = que.front();
		que.pop();
		size++;
		for (int dir = 0; dir < 4; dir++)
		{
			int tr = front.first + dx[dir], tc = front.second + dy[dir];
			if (tr < 0 || tr >= N || tc < 0 || tc >= N)
				continue;
			if (imap[tr][tc] != 1)
				continue;
			que.push({ tr, tc });
			imap[tr][tc] = 2;
		}
	}
	return size;
}