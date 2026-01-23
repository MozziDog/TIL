#include <bits/stdc++.h>
using namespace std;

const int MAX = 1003;

int dp[MAX][MAX];
tuple<int,int> before[MAX][MAX];
bool added[MAX][MAX];
string ans;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	string s1, s2;
	cin >> s1 >> s2;
	s1.insert(s1.begin(), ' ');  // 1-based index로
	s2.insert(s2.begin(), ' ');

	for (int i = 1; i <= s1.size(); i++)
	{
		for (int j = 1; j <= s2.size(); j++)
		{
			if (s1[i] == s2[j])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
				before[i][j] = { i-1, j-1 };
				added[i][j] = true;
			}
			else if (dp[i - 1][j] >= dp[i][j - 1])
			{
				dp[i][j] = dp[i - 1][j];
				before[i][j] = { i - 1, j };
			}
			else
			{
				dp[i][j] = dp[i][j - 1];
				before[i][j] = { i, j - 1 };
			}
		}
	}
	int i = s1.size() - 1, j = s2.size() - 1;
	while (!added[i][j] && i > 0 && j > 0)
		tie(i, j) = before[i][j];

	while (i > 0 && j > 0)
	{
		ans.push_back(s1[i]);
		do
			tie(i, j) = before[i][j];
		while (!added[i][j] && i > 0 && j > 0);
	}
	reverse(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	cout << ans;
	return 0;
}
