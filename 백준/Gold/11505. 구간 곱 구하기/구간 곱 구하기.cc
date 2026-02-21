#include <bits/stdc++.h>
#define llong long long
using namespace std;

const int MAXN = 1'000'005;
const int DIVIDER = 1'000'000'007;

int N, M, K, a, b, c;
int num[MAXN], segtree[4 * MAXN];

int build(int node, int left, int right)
{
	if (left == right)
	{
		segtree[node] = num[left];
		return segtree[node];
	}
	int mid = (left + right) / 2;
	llong l = build(node * 2, left, mid);
	llong r = build(node * 2 + 1, mid + 1, right);
	segtree[node] = (l * r) % DIVIDER;
	return segtree[node];
}

void update(int node, int left, int right, int at, int value)
{
	if (left == right)
	{
		segtree[node] = value;
		return;
	}

	int mid = (left + right) / 2;
	if (at <= mid)
		update(node * 2, left, mid, at, value);
	else
		update(node * 2 + 1, mid + 1, right, at, value);
	llong l = segtree[node * 2];
	llong r = segtree[node * 2 + 1];
	segtree[node] = (l * r) % DIVIDER;
}

int getresult(int node, int left, int right, int start, int end)
{
	if (right < start || end < left)
		return 1;
	if (start <= left && right <= end)
		return segtree[node];
	int mid = (left + right) / 2;
	llong l = getresult(node * 2, left, mid, start, end);
	llong r = getresult(node * 2 + 1, mid + 1, right, start, end);
	return (l * r) % DIVIDER;
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++)
		cin >> num[i];
	
	build(1, 1, N);
	for (int i = 0; i < (M + K); i++)
	{
		cin >> a >> b >> c;
		if (a == 1)
		{
			update(1, 1, N, b, c);
		}
		else
		{
			cout << getresult(1, 1, N, b, c) << '\n';
		}
	}
	return 0;
}