#include <bits/stdc++.h>
using namespace std;

const int MIN = INT_MIN;
string s;
int dp[200'000];
bool correct[200'000];	// 유효한 해석 여부

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	cin >> s;
	fill(dp, dp + 200'000, MIN);

	dp[0] = s[0] == '+' ? 10 : 1;
	correct[0] = true;

	if (s.size() > 1)
	{
		if (s[0] == '+' && s[1] == '-')	// +-
		{
			dp[1] = 11;
			correct[1] = true;
		}
		else							// ++, -+, --, 잘못된 식
			correct[1] = false;
	}
	
	for (int i = 2; i < s.size(); i++)
	{
		if (i > 2 && correct[i-3])
		{
			if (s[i - 2] == '+' && s[i - 1] == '+' && s[i] == '-')	// ++-
			{
				dp[i] = max(dp[i], dp[i - 3] + 11);
				correct[i] = true;
			}
			if (s[i - 2] == '-' && s[i - 1] == '+' && s[i] == '-') // -+-
			{
				dp[i] = max(dp[i], dp[i - 3] - 11);
				correct[i] = true;
			}
		}
		if (correct[i - 2])
		{
			if (s[i - 1] == '+')
			{
				if (s[i] == '+')	// ++
					dp[i] = max(dp[i], dp[i - 2] + 10);
				else				// +-
					dp[i] = max(dp[i], dp[i - 2] + 1);
			}
			else
			{
				if (s[i] == '+')	// -+
					dp[i] = max(dp[i], dp[i - 2] - 10);
				else				// --
					dp[i] = max(dp[i], dp[i - 2] - 1);
			}
			correct[i] = true;
		}
	}

	cout << dp[s.size() - 1];
	return 0;
}

// 나올 수 있는 패턴
/*
+-  -> +1
++  -> +10
++- -> + 11
--  -> -1
-+  -> -10
-+- -> -11
*/