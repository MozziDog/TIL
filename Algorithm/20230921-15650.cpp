// 백준 15650번: N과 M (2)
#include <bits/stdc++.h>
using namespace std;

int N, M;

vector<int> seq;

void bt(int start)
{
	if (seq.size() == M)
	{
		for (int i = 0; i < M; i++)
		{
			cout << seq[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = start; i <= N; i++)
	{
		seq.push_back(i);
		bt(i + 1);
		seq.pop_back();
	}
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> N >> M;

	seq.reserve(M);

	bt(1);
	return 0;
}