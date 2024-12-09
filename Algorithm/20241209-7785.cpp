// 백준 7785번: 회사에 있는 사람
// 해시를 사용한 stl 자료구조에는 unsorted set/multiset/map/multimap 4종류가 있다.
// set은 key만, map은 keyValue pair. 
// multi가 붙은 건 복수의 value 허용. 
// multiset/map은 erase할 때 erase(key)하면 해당하는 모든 원소를 지워버리므로 조심해야 함.
// 하나만 지우고 싶으면 multiset.erase(multiset.find(key)); 처럼 해야 됨.

#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int n;
	unordered_set<string> inCompany;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string person;
		string action;
		cin >> person >> action;
		if (action == "enter")
		{
			inCompany.insert(person);
		}
		else
		{
			if (inCompany.find(person) != inCompany.end())
				inCompany.erase(person);
		}
	}

	vector<string> answer(inCompany.begin(), inCompany.end());
	sort(answer.begin(), answer.end());
	for (auto i = answer.rbegin(); i != answer.rend(); i++)
		cout << *i << '\n';

	return 0;
}