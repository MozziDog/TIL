#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100'005;
const int INF = INT_MAX;

int N, M, a, b;
int num[MAXN], segtree[4 * MAXN];

int build(int node, int left, int right)
{
	if (left == right)
	{
		segtree[node] = num[left];
		return segtree[node];
	}
	int mid = (left + right) / 2;
	int l = build(node * 2, left, mid);
	int r = build(node * 2 + 1, mid + 1, right);
	segtree[node] = min(l, r);
	return segtree[node];
}

int getseg(int node, int left, int right, int start, int end)
{
	if (right < start || end < left)
		return INF;
	if (start <= left && right <= end)
		return segtree[node];
	int mid = (left + right) / 2;
	int l = getseg(node * 2, left, mid, start, end);
	int r = getseg(node * 2 + 1, mid + 1, right, start, end);
	return min(l, r);
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		cin >> num[i];
	
	build(1, 1, N);
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		cout << getseg(1, 1, N, a, b) << '\n';
	}
	return 0;
}