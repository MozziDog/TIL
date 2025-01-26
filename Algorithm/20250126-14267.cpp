// 백준 14267번: 회사 문화 1
// dfs 한번만 하면 되는 것을 입력 한 번 받을 때마다 하게 해서 쓸데없이 제출 횟수 1만 늘어났네 ㄲㅂ

#include <bits/stdc++.h>
using namespace std;

int n, m, p, w;
vector<int> child[100'001];
int sum[100'001];

void dfs(int cur, int addWeight)
{
	sum[cur] += addWeight;
	for (int next : child[cur])
		dfs(next, sum[cur]);
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> p;
		if (p == -1) continue;
		child[p].push_back(i);
	}
	for (int i = 0; i < m; i++)
	{
		cin >> p >> w;
		sum[p] += w;
	}
	dfs(1, 0);
	for (int i = 1; i <= n; i++)
	{
		cout << sum[i] << ' ';
	}
	return 0;
}