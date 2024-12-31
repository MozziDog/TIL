// 백준 2075번: N번째 큰 수
// 아니 생각해보니 마지막에 정렬 필요 없잖아 걍 첫번쨰 원소 내보내면 되잖아
// 그럼 원소 임의 접근도 필요없으니 priority_queue써도되는건데
// 대체 뭐했노;;

#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int N, t;
	priority_queue<int, vector<int>, greater<>> pq;
	cin >> N;
	for (int i = 0; i < N * N; i++)
	{
		cin >> t;
		pq.push(t);
		if (pq.size() > N)
			pq.pop();
	}
	cout << pq.top();
	return 0;
}