// 백준 15655번: N과 M (6)
#include <bits/stdc++.h>

using namespace std;

int N, M;
int numbers[10];
int seq[10];

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

	for (int i = 0; i < N; i++)
	{
		if (length == 0 || seq[length - 1] < numbers[i])
		{
			seq[length] = numbers[i];
			bt(length + 1);
		}
	}
}

int main()
{
	int tmp;

	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		numbers[i] = tmp;
	}
	sort(&numbers[0], &numbers[N]);
	
	bt(0);

	return 0;
}