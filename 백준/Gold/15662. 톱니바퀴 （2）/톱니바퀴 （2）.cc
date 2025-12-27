#include <bits/stdc++.h>
using namespace std;

int T, K, ans = 0;
vector<string> cogs;
int top[1001]; // 위쪽 방향의 톱니 인덱스

void rotate(int c, int d)	// d는 -1이 왼쪽 1이 오른쪽
{
	// 왼쪽 방향 전파
	int i = c;
	for (; i > 0; i--)
	{
		char right = cogs[i][(top[i] + 6) % 8];
		char left = cogs[i - 1][(top[i - 1] + 2) % 8];

		if (right == left)
		{
			break;
		}
	}
	int td = d;
	for (int j = c - 1; j >= i; j--)
	{
		top[j] = (top[j] + td + 8) % 8;
		td *= -1;
	}

	// 오른쪽 방향 전파
	i = c;
	for (; i < T-1; i++)
	{
		char right = cogs[i+1][(top[i+1] + 6) % 8];
		char left = cogs[i][(top[i] + 2) % 8];

		if (right == left)
		{
			break;
		}
	}
	td = d;
	for (int j = c + 1; j <= i; j++)
	{
		top[j] = (top[j] + td + 8) % 8;
		td *= -1;
	}

	top[c] = (top[c] - d + 8) % 8;
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	cin >> T;
	for (int i = 0; i < T; i++)
	{
		string s;
		cin >> s;
		cogs.push_back(s);
	}
	cin >> K;
	for(int i=0; i<K; i++)
	{
		int c, d;
		cin >> c >> d;
		rotate(c-1, d);
	}
	for (int i = 0; i < T; i++)
	{
		if (cogs[i][top[i]] == '1')
		{
			ans++;
		}
	}
	cout << ans;

	return 0;
}