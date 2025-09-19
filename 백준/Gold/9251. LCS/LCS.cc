#include <bits/stdc++.h>
using namespace std;

int cs[1005][1005];

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	string A, B;
	cin >> A >> B;

	for (int i = 1; i <= A.size(); i++)
	{
		for (int j = 1; j <= B.size(); j++)
		{
			if (A[i-1] == B[j-1])
				cs[i][j] = max(max(cs[i - 1][j - 1] + 1, cs[i - 1][j]), cs[i][j - 1]);
			else
				cs[i][j] = max(cs[i - 1][j], cs[i][j - 1]);
		}
	}

	cout << cs[A.size()][B.size()];
	return 0;
}