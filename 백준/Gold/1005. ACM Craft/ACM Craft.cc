#include <bits/stdc++.h>
#define llong long long
using namespace std;

int T, N, K, W;
int D[1001];
int indegree[1001];
vector<int> adj[1001];

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> T;
	while (T--)
	{
		cin >> N >> K;
		for (int i = 1; i <= N; i++)
		{
			cin >> D[i];
			indegree[i] = 0;
			adj[i].clear();
		}
		for (int i = 0; i < K; i++)
		{
			int X, Y;
			cin >> X >> Y;
			indegree[Y]++;
			adj[X].push_back(Y);
		}
		cin >> W;
		priority_queue<tuple<llong, int>, vector<tuple<llong, int>>, greater<void>> pq;	// 인덱스, 끝나는 시점
		llong ans =  -1;
		for (int i = 1; i <= N; i++)
		{
			if (indegree[i] == 0)
			{
				pq.push({D[i], i});
				if (i == W)
					ans = D[i];
			}
		}
		if (ans < 0)
		{
			while (!pq.empty())
			{
				llong startTime; int index;
				tie(startTime, index) = pq.top(); pq.pop();
				for (auto nxt : adj[index])
				{
					indegree[nxt]--;
					if (indegree[nxt] == 0)
					{
						if (nxt == W)
							ans = startTime + D[nxt];
						else
							pq.push({ startTime + D[nxt], nxt });
					}
				}
			}
		}
		cout << ans << '\n';
	}

	return 0;
}