#include <bits/stdc++.h>
using namespace std;

#define llong long long

const int MAX = 1'000'002;

llong N, M, K, a, b, c;
llong num[MAX];
llong segtree[2 * MAX];

llong buildSegtree(int node, int start, int end)
{
	if (start == end)
	{
		segtree[node] = num[start];
		return segtree[node];
	}
	int mid = (start + end) / 2;
	segtree[node] = buildSegtree(node * 2, start, mid)
		+ buildSegtree(node * 2 + 1, mid + 1, end);
	return segtree[node];
}

void update(int node, int start, int end, int pos, llong value)
{
	if (start == end && start == pos)
	{
		segtree[node] = value;
		return;
	}

	int mid = (start + end) / 2;
	if (pos <= mid)
		update(node * 2, start, mid, pos, value);
	else
		update(node * 2 + 1, mid + 1, end, pos, value);
	segtree[node] = segtree[node * 2] + segtree[node * 2 + 1];
}

// start ~ end : 탐색중인 노드가 표현하는 구간 (min/max include)
// left ~ right: 구하고자 하는 범위 (min/max include)
llong sum(int node, int start, int end, int left, int right)
{
	// 구하고자 하는 범위에 세그먼트가 아예 포함되지 않는 경우
	if (left > end || right < start) return 0;

	// 구하고자 하는 범위에 세그먼트가 온전히 포함되는 경우
	if (left <= start && end <= right) return segtree[node];
	
	// 구하고자 하는 범위에 세그먼트의 일부만 포함되는 경우
	int mid = (start + end) / 2;
	llong leftSum = sum(node * 2, start, mid, left, right);
	llong rightSum = sum(node * 2 + 1, mid + 1, end, left, right);
	return leftSum + rightSum;
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++)
	{
		cin >> num[i];
	}

	// 세그트리 구축
	buildSegtree(1, 1, N);
	
	for (int i = 0; i < M + K; i++)
	{
		cin >> a >> b >> c;
		// 숫자 바꾸기
		if (a == 1)
		{
			update(1, 1, N, b, c);
		}
		// 부분합 구하기
		else
		{
			cout << sum(1, 1, N, b, c) << '\n';
		}
	}
	return 0;
}