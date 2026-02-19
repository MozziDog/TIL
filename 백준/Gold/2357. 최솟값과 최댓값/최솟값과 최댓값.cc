#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100'001;
const int INF = 1'000'000'005;

int N, M; 
int arr[MAXN], segTreeMin[5 * MAXN], segTreeMax[5 * MAXN];

int build(int cur, int left, int right, int* outArr, bool maxTree)
{
	if (left == right)
	{
		outArr[cur] = arr[left];
		return outArr[cur];
	}
	int mid = (left + right) / 2;
	int l = build(cur * 2, left, mid, outArr, maxTree);
	int r = build(cur * 2 + 1, mid + 1, right, outArr, maxTree);
	if (maxTree)
		outArr[cur] = max(l, r);
	else
		outArr[cur] = min(l, r);
	return outArr[cur];
}

// left, right : 현재 노드가 표현하는 범위 (minmax include)
// start, end : 최대/최솟값을 찾아야하는 영역 (minmax include)
bool searchMax(int cur, int left, int right, int start, int end, int &out)
{
	out = 0;

	// 1. 아예 포함 안되는 경우
	if (right < start || left > end)
		return false;
	// 2. 완전히 포함되는 경우
	if (start <= left && right <= end)
	{
		out = segTreeMax[cur];
		return true;
	}
	// 3. 일부만 포함되는 경우
	int mid = (left + right) / 2;
	int tmp = 0;
	if (searchMax(cur * 2, left, mid, start, end, tmp))
		out = max(out, tmp);
	if (searchMax(cur * 2 + 1, mid + 1, right, start, end, tmp))
		out = max(out, tmp);
	return true;
}

bool searchMin(int cur, int left, int right, int start, int end, int& out)
{
	out = INF;

	// 1. 아예 포함 안되는 경우
	if (right < start || left > end)
		return false;
	// 2. 완전히 포함되는 경우
	if (start <= left && right <= end)
	{
		out = segTreeMin[cur];
		return true;
	}
	// 3. 일부만 포함되는 경우
	int mid = (left + right) / 2;
	int tmp = INF;
	if (searchMin(cur * 2, left, mid, start, end, tmp))
		out = min(out, tmp);
	if (searchMin(cur * 2 + 1, mid + 1, right, start, end, tmp))
		out = min(out, tmp);
	return true;
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		cin >> arr[i];
	}
	build(1, 1, N, segTreeMax, true);
	build(1, 1, N, segTreeMin, false);

	for (int i = 0; i < M; i++)
	{
		int a, b, resMin, resMax;
		cin >> a >> b;
		searchMin(1, 1, N, a, b, resMin);
		searchMax(1, 1, N, a, b, resMax);
		cout << resMin << ' ' << resMax << '\n';
	}
	return 0;
}