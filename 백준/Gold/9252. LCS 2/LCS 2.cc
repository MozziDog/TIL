#include <bits/stdc++.h>
using namespace std;

const int MAX = 1003;

int dp[MAX][MAX];
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
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	int i = s1.size() - 1, j = s2.size() - 1;
	ans.reserve(dp[i][j]);
	while (dp[i][j] > 0)
	{
		if (dp[i][j] == dp[i - 1][j])
			i--;
		else if (dp[i][j] == dp[i][j - 1])
			j--;
		else
		{
			ans.push_back(s1[i]);
			i--; j--;
		}
	}
	reverse(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	cout << ans;
	return 0;
}
