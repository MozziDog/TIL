// 백준 5014번: 스타트링크
// 부등호에 등호 포함/미포함 잘못 쓴 거 때문에 메모리 초과났었음. 주의할 것.

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int Floors, Start, Goal, Up, Down;
	vector<int> minStepsToGo;
	queue<pair<int, int>> que; // floor, step

	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> Floors >> Start >> Goal >> Up >> Down;

	minStepsToGo.resize(Floors + 1, INT32_MAX);
	que.push({ Start, 0 });
	while (!que.empty())
	{
		auto front = que.front();
		que.pop();

		if (front.first == Goal)
		{
			cout << front.second;
			return 0;
		}

		if (minStepsToGo[front.first] > front.second)
		{
			minStepsToGo[front.first] = front.second;
		}
		else
		{
			continue;
		}

		if (front.first + Up <= Floors)
		{
			que.push({ front.first + Up, front.second + 1 });
		}
		if (front.first - Down >= 1)
		{
			que.push({ front.first - Down, front.second + 1 });
		}
	}

	cout << "use the stairs";
	return 0;
}