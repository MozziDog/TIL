#include <bits/stdc++.h>
using namespace std;

#define index second
#define value first

const int MAX = 500'001;
int N;
int A[MAX], segtree[4 * MAX];

priority_queue<pair<int, int>> pq;

// 세그트리는 범위 내에 '버블을 타고 제 위치로 이동해버린' 것의 개수를 저장
void update(int node, int left, int right, int at)
{
	if (left == right)
	{
		segtree[node] = 1;
		return;
	}
	int mid = (left + right) / 2;
	if (at <= mid)
		update(node * 2, left, mid, at);
	else
		update(node * 2 + 1, mid + 1, right, at);

	segtree[node] = segtree[node * 2] + segtree[node * 2 + 1];
}

int getSegtree(int node, int left, int right, int start, int end)
{
	if (right < start || end < left)
		return 0;
	if (start <= left && right <= end)
		return segtree[node];
	int mid = (left + right) / 2;
	int l = getSegtree(node * 2, left, mid, start, end);
	int r = getSegtree(node * 2 + 1, mid + 1, right, start, end);
	
	return l + r;
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	long long ans = 0;

	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> A[i];
	
	for (int i = 1; i <= N; i++)
		pq.push({ A[i], i });

	for (int i = N; i > 0; i--)
	{
		auto top = pq.top(); pq.pop();
		int skipCount = getSegtree(1, 1, N, top.index, N);
		ans += N - top.index - skipCount;
		update(1, 1, N, top.index);
	}
	cout << ans;
	return 0;
}