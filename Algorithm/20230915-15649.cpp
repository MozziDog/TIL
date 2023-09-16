// 백준 15649번: N과 M(1)

#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> s;
vector<bool>used;

void bt()
{
	for (int i = 1; i <= N; i++)
	{
		if (used[i] == false)
		{
			s.push_back(i);
			used[i] = true;
			if (s.size() == M)
			{
				// print
				for (int j = 0; j < s.size(); j++)
					cout << s[j] << ' ';
				cout << '\n';
			}
			else
			{
				bt();
			}
			s.pop_back();
			used[i] = false;
		}
	}
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> N >> M;
	
	s.reserve(8);
	used.resize(9, false);
	bt();
	return 0;
}