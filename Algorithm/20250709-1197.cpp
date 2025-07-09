// 백준 1197번: 최소 스패닝 트리
// 지난번에는 프림 알고리즘으로 풀어봤으니 오늘은 크루스칼 알고리즘으로 풀어보자

#include <bits/stdc++.h>
using namespace std;

vector<int> p(10001, -1);

int find(int x)
{
	if (p[x] < 0) return x;
	else return p[x] = find(p[x]);
}

bool uni(int u, int v)
{
	u = find(u);
	v = find(v);
	if (u == v) return false;
	if ((-p[u]) < (-p[v]))	// v의 랭크가 더 큰 경우
	{
		swap(u, v);
	}
	if (p[u] == p[v])		// 랭크가 같다면 트리를 합쳤을 때 랭크 1 증가
		p[u]--;
	p[v] = u;
	return true;
}

int V, E, nodeCount = 0;
long long ans;
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> V >> E;
	for (int i = 0; i < E; i++)
	{
		int A, B, C;
		cin >> A >> B >> C;
		pq.push({C, A, B});
	}

	while (!pq.empty())
	{
		int A, B, C;
		tie(C, A, B) = pq.top();
		pq.pop();
		if (find(A) == find(B)) continue;
		ans += C;
		uni(A, B);
		if (++nodeCount == V) break;
	}
	cout << ans;
	return 0;
}