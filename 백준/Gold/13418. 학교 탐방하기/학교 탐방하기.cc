// 로직은 맞았는데 p의 크기를 1000으로 설정했던 것이 실수였다.
// 배열을 선언할 땐 꼭 문제를 잘 읽고 넉넉하게 크기를 설정하자.

#include <bits/stdc++.h>
using namespace std;

vector<int> p(1002, -1);

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

	if (-p[u] < -p[v])
		swap(u, v);
	if (p[u] == p[v])
		p[u]--;
	p[v] = u;
	return true;
}

int N, M;
// 0이 오르막길, 1이 내리막길이니까 작은게 앞으로 올수록 오르막길 우선하는 pq임
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>>  maxpq;
priority_queue<tuple<int, int, int>> minpq;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int maxUphill = 0, minUphill = 0;

	// 입력
	cin >> N >> M;
	for (int i = 0; i < M + 1; i++)
	{
		int A, B, C;
		cin >> A >> B >> C;
		minpq.push(make_tuple(C, A, B));
		maxpq.push(make_tuple(C, A, B));
	}

	// 최소 구하기
	while (!minpq.empty())
	{
		int A, B, C;
		tie(C, A, B) = minpq.top();
		minpq.pop();
		if (find(A) == find(B)) continue;

		if (C == 0) minUphill++;
		uni(A, B);
	}

	fill(p.begin(), p.end(), -1);
	// 최대 구하기
	while (!maxpq.empty())
	{
		int A, B, C;
		tie(C, A, B) = maxpq.top();
		maxpq.pop();
		if (find(A) == find(B)) continue;

		if (C == 0) maxUphill++;
		uni(A, B);
	}

	cout << maxUphill * maxUphill - minUphill * minUphill;

	return 0;
}