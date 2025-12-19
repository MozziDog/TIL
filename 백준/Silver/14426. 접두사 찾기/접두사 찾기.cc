#include <bits/stdc++.h>
using namespace std;

int N, M, ans;
const int root = 1;
int trieSize = 1;
const int MAX = 10000 * 500 + 5;
bool chk[MAX];
int nxt[MAX][26];

bool insert(string str)
{
	int cur = 1;
	for (char c : str)
	{
		int ci = c - 'a';
		if (nxt[cur][ci] == 0)
		{
			nxt[cur][ci] = ++trieSize;
		}
		cur = nxt[cur][ci];
	}
	if(chk[cur])
		return false;
	chk[cur] = true;
	return true;
}

bool fetch(string str)
{
	int cur = 1;
	for (char c : str)
	{
		int ci = c - 'a';
		if (nxt[cur][ci] == 0)
			return false;
		cur = nxt[cur][ci];
	}
	return true;
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> M;
	string str;
	for (int i = 0; i < N; i++)
	{
		cin >> str;
		insert(str);
	}
	for (int i = 0; i < M; i++)
	{
		cin >> str;
		ans += fetch(str) ? 1 : 0;
	}
	cout << ans;
	return 0;
}