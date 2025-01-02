// 백준 1781번: 컵라면
// 여태껏 priority_queue를 하나만 써서 2개를 병용한다는 생각을 하기 어려웠다.
// 일단 그 점만 힌트로 알고 나서는 (거꾸로 생각하기가 들어가긴 했다만) 대체로 평범했던 문제. 

#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
	return a.second < b.second;
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int N, answer = 0;
	priority_queue<pair<int, int>> problems;
	priority_queue<pair<int, int>, vector<pair<int, int>>, function<bool(pair<int, int>, pair<int, int>)>> candidates(cmp);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int deadline, cup;
		cin >> deadline >> cup;
		problems.push({ deadline, cup });
	}
	for (int i = N; i > 0; i--)
	{
		while (!problems.empty() && problems.top().first >= i)
		{
			candidates.push(problems.top());
			problems.pop();
		}
		if (candidates.empty()) continue;
		answer += candidates.top().second;
		candidates.pop();
	}
	cout << answer;
	return 0;
}