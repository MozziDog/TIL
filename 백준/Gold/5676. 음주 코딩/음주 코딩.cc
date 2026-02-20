#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100001;

int N, K;
int X[MAXN], segtree[4 * MAXN];

int getsign(int value)
{
	if (value < 0) 
		return -1;
	return (value > 0);
}

int buildtree(int node, int left, int right)
{
	if (left == right)
	{
		segtree[node] = getsign(X[left]);
		return segtree[node];
	}

	int mid = (left + right) / 2;
	int lresult = buildtree(node * 2, left, mid);
	int rresult = buildtree(node * 2 + 1, mid + 1, right);
	segtree[node] = lresult * rresult;
	return segtree[node];
}

void update(int node, int left, int right, int at, int value)
{
	// 1. 범위에 포함 안되는 경우
	if (right < at || at < left)
		return;
	// 2. leaf 노드에 도달한 경우
	if (left == right && left == at)
	{
		segtree[node] = getsign(value);
		return;
	}
	// 3. 범위에 포함되는 경우
	int mid = (left + right) / 2;
	update(node * 2, left, mid, at, value);
	update(node * 2 + 1, mid + 1, right, at, value);
	segtree[node] = segtree[node * 2] * segtree[node * 2 + 1];
}

int getresult(int node, int left, int right, int begin, int end)
{
	// 1. 범위에 포함 안되는 경우
	if (right < begin || end < left)
		return 1;
	// 2. 범위에 완전히 포함되는 경우
	if (begin <= left && right <= end)
		return segtree[node];
	// 3. 범위에 걸쳐있는 경우
	int mid = (left + right) / 2;
	int lresult = getresult(node * 2, left, mid, begin, end);
	int rresult = getresult(node * 2 + 1, mid + 1, right, begin, end);
	return lresult * rresult;
}

void solve()
{
	for (int i = 1; i <= N; i++)
		cin >> X[i];
	buildtree(1, 1, N);

	for (int i = 0; i < K; i++)
	{
		char op;
		int a, b;
		cin >> op >> a >> b;
		if (op == 'C')
		{
			update(1, 1, N, a, b);
		}
		else
		{
			int res = getresult(1, 1, N, a, b);
			cout << (res > 0 ? '+' : res == 0 ? '0' : '-');
		}
	}
	cout << '\n';
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	while (cin >> N >> K)
	{
		solve();
	}

	return 0;
}


