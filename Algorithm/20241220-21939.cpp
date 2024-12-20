// 백준 21939번: 문제 추천 시스템 Version 1
// multimap은 key로 정렬되긴 하지만 value로 정렬되진 않는다. 
// 따라서, 같은 key값을 가지는 원소가 여럿이라면, 그 원소들이 value 순서대로 정렬되었다고 보장할 수 없음.
// 원한다면 key값을 가지는 녀석들을 범위로 가져와서, 그 안에서 정렬하고 뽑아 써야 됨.
// 이 문제같이 범위가 제한되어있다면 set의 배열로 대체할 수 있겠지만.

#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int n, m;
	set<int> problems[101];
	map<int, int> difficulty;

	cin >> n;
	while (n--)
	{
		int p, l;
		cin >> p >> l;
		problems[l].insert(p);
		difficulty.insert({ p, l });
	}

	cin >> m;
	while (m--)
	{
		string op;
		int arg1, arg2;
		cin >> op;
		if (op == "add")
		{
			cin >> arg1 >> arg2;
			problems[arg2].insert(arg1);
			difficulty.insert({ arg1, arg2 });
		}
		else if (op == "recommend")
		{
			cin >> arg1;
			if (arg1 == 1)
				for (int i = 100; i > 0; i--)
				{
					if (problems[i].empty()) continue;
					cout << *(problems[i].rbegin()) << '\n'; break;
				}
			else
				for (int i = 1; i <= 100; i++)
				{
					if (problems[i].empty()) continue;
					cout << *(problems[i].begin()) << '\n'; break;
				}
		}
		else if (op == "solved")
		{
			cin >> arg1;
			int level = difficulty[arg1];
			problems[level].erase(arg1);
			difficulty.erase(arg1);
		}
	}
	return 0;
}