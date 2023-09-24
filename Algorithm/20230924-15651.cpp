// 백준 15651번: N과 M (3)
// 다른 문제들에 비해 시간이 높게 나왔는데 모범 답안을 보고 vector를 배열로 바꿔도 그대로인걸 보니 원래 그런 문제였나 봄.
#include <bits/stdc++.h>

using namespace std;

int N, M;
int seq[10];

void bt(int count)
{
	if (count == M)
	{
		for (int j = 0; j < M; j++)
		{
			cout << seq[j] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= N; i++)
	{
		seq[count] = i;
		bt(count + 1);
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