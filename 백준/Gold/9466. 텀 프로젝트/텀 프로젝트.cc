#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

const int MAX = 100'001;
int T, n, p[MAX], ans;
bool visited[MAX], finished[MAX];

void dfs(int cur)
{
	unordered_set<int> candidates;

	// 다른 시작점으로부터 이미 탐색해본 노드일 경우
	if (finished[cur])
		return;

	// 사이클 감지
	if (visited[cur])
	{
		int c = cur, count = 0;
		do
		{
			c = p[c];
			count++;
		} while (c != cur);
		ans -= count;
		return;
	}

	visited[cur] = true;
	dfs(p[cur]);
	finished[cur] = true;
}

void solve()
{
	cin >> n;
	fill(visited, visited + n + 1, false);
	fill(finished, finished + n + 1, false);
	ans = n;

	for (int i = 1; i <= n; i++)
	{
		cin >> p[i];
		if (i == p[i])
		{
			ans--;
			visited[i] = true;
			finished[i] = true;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (visited[i]) 
			continue;
		dfs(i);
	}
	std::cout << ans << '\n';
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> T;
	while (T--)
	{
		solve();
	}
	return 0;
}