// 백준 1715번: 카드 정렬하기
// 크기가 n인 것과 m인 것을 합치면 (m+n)이 되는데, 이게 이후에도 합쳐질 때마다 비교횟수에 가산되므로-
// 즉 ans = sum(n_i * k_i)이니까 (여기서 k는 해당 뭉치, 또는 해당 뭉치가 포함된 카드뭉치가 '합쳐지기' 수행되는 횟수)
// 합쳐질 횟수가 가장 많은, 즉 가장 처음 합쳐질 뭉치를 가장 작은 것으로 선택하면 되는 간단한 문제였다.

#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int N, ans = 0;
	priority_queue<int, vector<int>, greater<int>> pq;

	cin >> N;
	while (N--)
	{
		int t;
		cin >> t;
		pq.push(t);
	}
	while (pq.size() > 1)
	{
		int a, b;
		a = pq.top();
		pq.pop();
		b = pq.top();
		pq.pop();
		ans += (a + b);
		pq.push(a + b);
	}
	cout << ans;
	return 0;
}