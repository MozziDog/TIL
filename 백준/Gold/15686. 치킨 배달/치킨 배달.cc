#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int N, M;
	int answer = 9999999;
	vector<pair<int, int>> house;
	vector<pair<int, int>> chicken;

	cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int input;
			cin >> input;
			if (input == 1)
			{
				house.push_back({ i, j });
			}
			if (input == 2)
			{
				chicken.push_back({ i, j });
			}
		}
	}

	vector<bool> selected(chicken.size(), 1);
	fill(selected.begin(), selected.end() - M, 0);
	do
	{
		int totalChickenDist = 0;
		// 치킨거리 계산
		for (int h = 0; h < house.size(); h++)
		{
			int minChickenDist = 999999;
			for (int c = 0; c < chicken.size(); c++)
			{
				if (selected[c])
				{
					int dist = abs(chicken[c].first - house[h].first) + abs(chicken[c].second - house[h].second);
					if (dist < minChickenDist)
						minChickenDist = dist;
				}
			}
			totalChickenDist += minChickenDist;
		}
		if (answer > totalChickenDist)
			answer = totalChickenDist;
	} while (next_permutation(selected.begin(), selected.end()));

	cout << answer;

	return 0;
}