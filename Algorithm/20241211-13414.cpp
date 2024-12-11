// 백준 13414번: 수강신청
// key를 int로 해서 틀렸는데 왜지 싶었더니 0으로 시작하는 입력이 있을 수 있어서였다...
// 현실에서는 상식적으로 학번이 0으로 시작할리 없어서 놓쳤던 케이스

#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	int k, l;
	unordered_map<string, int> m;

	cin >> k >> l;
	for (int i = 0; i < l; i++)
	{
		string t;
		cin >> t;
		m[t] = i;
	}
	vector<pair<string, int>> answer(m.begin(), m.end());
	sort(answer.begin(), answer.end(), [](pair<string, int> &a, pair<string, int> &b){ return a.second < b.second; });
	for (int i = 0; i < min(k, (int)answer.size()); i++)
	{
		cout << answer[i].first << '\n';
	}
	return 0;
}