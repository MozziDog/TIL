// 백준 21944번: 문제 추천 시스템 Version 2
// 야발 맞게 푼 줄 알았는데 왜 자꾸 틀렸다고 하나 했더니
// recommend3 -1 L이 난이도 L 이하가 아니라 난이도 L 미만 이었다....
// 하 개억울하네

#include <bits/stdc++.h>
using namespace std;

int N, M, P, L, G, x;
string op;
map<int, pair<int, int>> probInfo;			// 삭제를 위해 문제번호-{레벨, 그룹} 보관
set<int> probByLevel[101];					// 레벨별로 정렬된 문제
set<int> probByLevelAndGroup[101][101];		// 레벨과 그룹별로 정렬된 문제

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> N;
	while (N--)
	{
		cin >> P >> L >> G;
		probInfo.insert({ P, { L, G } });
		probByLevel[L].insert(P);
		probByLevelAndGroup[L][G].insert(P);
	}
	cin >> M;
	while (M--)
	{
		cin >> op;
		if (op == "recommend")
		{
			cin >> G >> x;
			if (x == 1)
				for (int i = 100; i >= 0; i--)
				{
					if (probByLevelAndGroup[i][G].empty()) continue;
					cout << *probByLevelAndGroup[i][G].rbegin() << '\n';
					break;
				}
			else
				for (int i = 0; i <= 100; i++)
				{
					if (probByLevelAndGroup[i][G].empty()) continue;
					cout << *probByLevelAndGroup[i][G].begin() << '\n';
					break;
				}
		}
		else if (op == "recommend2")
		{
			cin >> x;
			if (x == 1)
				for (int i = 100; i >= 0; i--)
				{
					if (probByLevel[i].empty()) continue;
					cout << *probByLevel[i].rbegin() << '\n';
					break;
				}
			else
				for (int i = 0; i <= 100; i++)
				{
					if (probByLevel[i].empty()) continue;
					cout << *probByLevel[i].begin() << '\n';
					break;
				}
		}
		else if (op == "recommend3")
		{
			int ans = -1;
			cin >> x >> L;
			if (x == 1)
				for (int i = L; i <= 100; i++)
				{
					if (probByLevel[i].empty()) continue;
					ans = *probByLevel[i].begin();
					break;
				}
			else
				for (int i = L-1; i >= 1; i--)
				{
					if (probByLevel[i].empty()) continue;
					ans = *probByLevel[i].rbegin();
					break;
				}
			cout << ans << "\n";
		}
		else if (op == "add")
		{
			cin >> P >> L >> G;
			probInfo[P] = { L, G };
			probByLevel[L].insert(P);
			probByLevelAndGroup[L][G].insert(P);
		}
		else if (op == "solved")
		{
			cin >> P;
			tie(L, G) = probInfo[P];
			probByLevel[L].erase(P);
			probByLevelAndGroup[L][G].erase(P);
		}
	}
	return 0;
}