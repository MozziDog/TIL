// 백준 9375번: 패션왕 신해빈
// 해시를 사용하는 컨테이너들의 operator[]는 값이 없을 때 0을 자동으로 삽입함
// C#의 default 키워드랑 비슷하다고 생각하면 될 듯
// 따라서 closet[cat]은 기본 0임

#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int t, n;
	cin >> t;
	while (t--)
	{
		unordered_map<string, int> closet;
		cin >> n;
		while (n--)
		{
			string cat, item;
			cin >> item >> cat;
			closet[cat]++;
		}
		int answer = 1;
		for (auto i : closet)
			answer *= (i.second + 1);
		cout << answer - 1 << '\n';
	}

	return 0;
}