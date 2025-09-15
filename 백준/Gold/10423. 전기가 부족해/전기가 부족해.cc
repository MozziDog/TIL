#include <bits/stdc++.h>
using namespace std;

vector<int> p(1005, -1);

int find(int a)
{
	if (p[a] < 0)
		return a;
	else return p[a] = find(p[a]);
}

bool merge(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a == b)
		return false;

	if (p[a] > p[b])
		swap(a, b);
	if (p[a] == p[b])
		p[a]--;
	p[b] = a;
	return true;
}

int N, M, K;
long long ans = 0;
vector<tuple<int,int>> adj[1005];

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;

	cin >> N >> M >> K;
	for (int i = 0; i < K; i++)
	{
		int a; 
		cin >> a;
		pq.push({ 0, 1001, a });
	}
	for (int i = 0; i < M; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		adj[u].push_back({ w, v });
		adj[v].push_back({ w, u });
	}
	
	while (!pq.empty())
	{
		int a, b, weight;
		tie(weight, a, b) = pq.top();
		pq.pop();
		
		if (merge(a, b))
		{
			ans += weight;
			for (int i=0; i<adj[b].size(); i++)
			{
				pq.push({ get<0>(adj[b][i]), b, get<1>(adj[b][i])});
			}
		}
	}
	cout << ans;
	return 0;
}