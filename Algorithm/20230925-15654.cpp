// 백준 15654번: N과 M (5)
#include <bits/stdc++.h>

using namespace std;

int N, M;
int numbers[10];
bool used[10];
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
		if (used[i] == false)
		{
			seq[length] = numbers[i];
			used[i] = true;
			bt(length + 1);
			used[i] = false;
		}
	}
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> numbers[i];
	}
	sort(&numbers[0], &numbers[N]);

	bt(0);

	return 0;
}