// 백준 15652번: N과 M (4)
#include <bits/stdc++.h>

using namespace std;

int N, M;
int seq[8];

void bt(int length)
{
	if (length == M)
	{
		for (int i = 0; i < M; i++)
		{
			cout << seq[i] << ' ';
		}
		cout << '\n';
		return;
	}
	int idx;
	if (length == 0)
		idx = 1;
	else
		idx = seq[length - 1];
	for (; idx <= N; idx++)
	{
		seq[length] = idx;
		bt(length + 1);
	}
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> N >> M;

	bt(0);
	return 0;
}