// 백준 1647번: 도시 분할 계획
// 최소 신장 트리를 구하고, 그 트리에 포함된 edge 중에 가장 weight가 큰 것을 빼면 되지 않을까?
// 정답!

#include <bits/stdc++.h>
using namespace std;

vector<int> p(1000001, -1);

int find(int u)
{
	if (p[u] < 0) return u;
	else return p[u] = find(p[u]);
}

bool uni(int u, int v)
{
	u = find(u);
	v = find(v);
	if (u == v) return false;

	if (-p[u] < -p[v])	// v의 깊이가 더 깊다면
		swap(u, v);
	if (p[u] == p[v])
		p[u]--;
	p[v] = u;
	return true;
}

int N, M, longestEdge = 0;
long long sum;
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int A, B, C;
		cin >> A >> B >> C;
		pq.push({ C, A, B });
	}

	while (!pq.empty())
	{
		int A, B, C;
		tie(C, A, B) = pq.top();
		pq.pop();
		if (find(A) == find(B)) continue;

		sum += C;
		longestEdge = max(longestEdge, C);

		uni(A, B);
	}

	cout << sum - longestEdge;

	return 0;
}