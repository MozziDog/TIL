#include <bits/stdc++.h>
using namespace std;

#define y first
#define x second


void solve()
{
	int h, w, ans = 0;
	vector<vector<char>> map;
	bool visited[100][100];

	cin >> h >> w;
	vector<char> row(w);
	map.resize(h, row);
	memset(&visited[0][0], 0, sizeof(visited));

	queue<pair<int, int>> q;	// bfs
	set<int> key;
	multimap<int, pair<int, int>> lockedDoor;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == '*')
				continue;
			if(i == 0)
				q.push({ i-1, j });
			if (i == h - 1)
				q.push({ i + 1, j });
			if (j == 0)
				q.push({ i, j - 1 });
			if (j == w - 1)
				q.push({ i, j + 1 });
		}
	}
	string alreadyHasKey;
	cin >> alreadyHasKey;
	for (char c : alreadyHasKey)
	{
		if (c == '0') break;
		key.insert(c);
	}

	while (!q.empty())
	{
		auto cur = q.front(); q.pop();
		const pair<int, int> d[] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
		for (int i = 0; i < 4; i++)
		{
			pair<int,int> nxt = { cur.y + d[i].y, cur.x + d[i].x };
			if (nxt.x < 0 || nxt.x >= w || nxt.y < 0 || nxt.y >= h)
				continue;

			if (visited[nxt.y][nxt.x])
				continue;

			char nc = map[nxt.y][nxt.x];
			if (nc == '*')
				continue;

			visited[nxt.y][nxt.x] = true;
			if (nc >= 'a' && nc <= 'z') // 소문자 = 열쇠
			{
				key.insert(nc);
				char d = nc - 'a' + 'A';
				if (lockedDoor.find(d) != lockedDoor.end())
				{
					auto it = lockedDoor.lower_bound(d);
					while (it != lockedDoor.upper_bound(d))
					{
						q.push({ it->second.y, it->second.x });
						it++;
					}
				}
				lockedDoor.erase(d);
				q.push({ nxt.y, nxt.x });
				continue;
			}

			if (nc >= 'A' && nc <= 'Z') // 대문자 = 자물쇠
			{
				char k = nc - 'A' + 'a';
				if (key.find(k) != key.end())
				{
					q.push({ nxt.y, nxt.x });
					continue;
				}
				else
				{
					lockedDoor.insert({ nc, { nxt.y, nxt.x } });
					continue;
				}
			}

			// else
			if (nc == '$')
				ans++;

			q.push({ nxt.y, nxt.x });
		}
	}

	cout << ans << '\n';
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}