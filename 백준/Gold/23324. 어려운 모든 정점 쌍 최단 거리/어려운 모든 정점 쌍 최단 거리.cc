#include <bits/stdc++.h>
using namespace std;

int N, M, K;
set<int> adj[100'001];

int p[100'001];
long long s[100'001];

int find(int a)
{
	if (p[a] < 0) return a;
	int cur = a;
	while (p[cur] > 0)
		cur = p[cur];
	return p[a] = cur;
}

bool merge(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a == b) return false;
	if (-p[a] < -p[b])
		swap(a, b);
	if (a == b)
		p[a]--;
	p[b] = a;
	s[a] += s[b];
	return true;
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> M >> K;
	fill(p, p + N + 1, -1);
	fill(s, s + N + 1, 1);

	for (int i = 1; i < K; i++)
	{
		int a, b;
		cin >> a >> b;
		merge(a, b);
	}
	// k번째 간선 입력 버림
	int k1, k2;
	cin >> k1 >> k2;
	for (int i = K + 1; i <= M; i++)
	{
		int a, b;
		cin >> a >> b;
		merge(a, b);
	}

	int first = find(1);
	int second = 0;
	for (int i = 2; i <= N; i++)
	{
		if (find(i) != first)
		{
			second = find(i);
			break;
		}
	}
	if (second == 0)		// k번째 간선 제외하고도 한뭉탱이로 merge될 때
		cout << 0;
	else					// 두 뭉탱이로 merge될 떄
		cout << s[first] * s[second];
	return 0;
}