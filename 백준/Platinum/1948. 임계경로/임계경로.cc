// 백준 1948번
#include <bits/stdc++.h>
using namespace std;

#define city first
#define cost second

int INF = 0x3f3f3f3f;

int n, m, han, rom, ans;
vector<pair<int, int>> adj[10001];
vector<int> backTrace[10001];
long long t[10001];
bool visited[10001][10001];

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ v, w });
	}
	cin >> han >> rom;

	queue<tuple<int, long long>> q;	// 현재 도시 번호, 지금까지 거친 도시 갯수, 현재 도시까지의 경로 길이
	q.push({ han, 0 });
	while (!q.empty())
	{
		int cur;
		long long len;
		tie(cur, len) = q.front();
		q.pop();
		for (auto road : adj[cur])
		{
			if (t[road.city] < len + road.cost)
			{
				t[road.city] = len + road.cost;
				backTrace[road.city].clear();
				backTrace[road.city].push_back(cur);
				q.push(make_tuple(road.city, t[road.city]));
			}
			else if (t[road.city] == len + road.cost)
			{
				backTrace[road.city].push_back(cur);
			}
		}
	}

	queue<int> q2;
	q2.push(rom);
	while(!q2.empty())
	{
		int s = q2.front();
		q2.pop();
		for (int d : backTrace[s])
		{
			if (visited[s][d]) continue;
			visited[s][d] = true;
			ans++;
			q2.push(d);
		}
	}

	cout << t[rom] << '\n' << ans;
	return 0;
}