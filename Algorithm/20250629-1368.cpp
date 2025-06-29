// 백준 1368번: 물대기
// 감이 안와서 짖는개 힌트 보고 풀었다.
// 논에 우물을 직접 파는 것을 가상의 '물을 이미 대고 있는 논'과의 연결로 대체해서 생각하는 거임
#include <bits/stdc++.h>
using namespace std;

int N, ans;
int P[301][301]; // W[i] = P[0][i] = P[i][0]
int chk[301];

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<void>> pq;	// 비용, 논 번호 A, B 순

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> P[0][i];
		P[i][0] = P[0][i];
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> P[i][j];
		}
	}

	pq.push({ 0, 0 });
	while (!pq.empty())
	{
		int cost= pq.top().first, idx = pq.top().second;
		pq.pop();
		if (chk[idx] == true) continue;

		chk[idx] = true;
		ans += cost;
		for (int i = 1; i <= N; i++)
		{
			if (chk[i] == true) continue;
			pq.push({ P[idx][i], i });
		}
	}
	cout << ans;
	return 0;
}