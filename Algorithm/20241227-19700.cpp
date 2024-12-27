// 백준 19700번: 수업
// 풀이가 생각 안나는 문제를 직관에서 시작해서 알고리즘으로 정제하여 해결하는 연습이 조금씩 되고 있는 것 같다.
// set/multiset은 정렬되어있으므로 원소를 임의로 접근해서 수정하면 정렬이 깨진다. 따라서 임의접근을 지원하지 않고 삭제 및 재삽입만 됨
// 마찬가지로 map/multimap의 key는 임의 접근하여 수정이 불가능하지만 value는 상관없으니 임의로 수정이 됨.

#include <bits/stdc++.h>
using namespace std;

int N, h, k, curTeams;
vector<pair<int, int>> students;
multiset<int> teams;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> N;
	while (N--)
	{
		cin >> h >> k;
		students.push_back({ h, k });
	}
	sort(students.begin(), students.end());
	auto it = students.rbegin();
	while (it != students.rend())
	{
		if (teams.empty())
		{
			teams.insert(1);
			it++;
			continue;
		}

		h = it->first; k = it->second;
		bool foundTeam = false;
		auto t = teams.lower_bound(k);
		if (t == teams.begin())
			teams.insert(1);
		else
		{
			t = prev(t);
			teams.insert(*t + 1);
			teams.erase(t);
		}
		it++;
	}
	cout << teams.size();
	return 0;
}