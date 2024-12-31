// 백준 2075번: N번째 큰 수
// 모든 수는 자신의 한 칸 위에 있는 수보다 크다... 는 조건은 딱히 쓸모 없었던 것 같은데
// priority_queue는 원소에 임의 접근이 안되어서 어차피 내부는 힙으로 구현되어있는 거, 그냥 heap으로 풀어버렸다. priority_queue에 원소 임의 접근이 필요하다면 나쁘지 않은 대안인 듯.

#include <bits/stdc++.h>
using namespace std;

bool cmp(const int& a, const int& b)
{
	return a > b;
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int N, t;
	vector<int> pq;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> t;
		pq.push_back(t);
	}
	make_heap(pq.begin(), pq.end(), cmp);
	for (int i = N; i < N * N; i++)
	{
		cin >> t;
		if (t > pq[0])		// pq[0] == pq.top()
		{
			pop_heap(pq.begin(), pq.end(), cmp);
			pq[N - 1] = t;
			push_heap(pq.begin(), pq.end(), cmp);
		}
	}
	sort(pq.begin(), pq.end());
	cout << pq[0];
	return 0;
}