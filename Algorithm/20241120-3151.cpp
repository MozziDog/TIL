// 백준 3151번: 합이 0
// 오늘의 교훈: 이분 탐색에서 '특정 값이 있는 범위'를 구하려면 
// 시작점과 끝점을 찾기 위해 이분 탐색 두번 하는 편이 빠르다.

#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int N;
	vector<int> stu;
	long long answer = 0;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;
		stu.push_back(tmp);
	}
	
	sort(stu.begin(), stu.end());

	for (int i = 0; i < N - 2; i++)
	{
		for (int j = i + 1; j < N - 1; j++)
		{
			int top = N - 1;
			int bot = j + 1;
			int lowerBound, upperBound;

			// get lowerBound
			while (top >= bot)
			{
				int mid = (top + bot) / 2;
				if (stu[mid] + stu[i] + stu[j] >= 0)
				{
					top = mid - 1;
				}
				else if (stu[mid] + stu[i] + stu[j] < 0)
				{
					bot = mid + 1;
				}
			}
			lowerBound = bot;
			
			top = N - 1;
			bot = lowerBound;
			while (top >= bot)
			{
				int mid = (top + bot) / 2;
				if (stu[mid] + stu[i] + stu[j] > 0)
				{
					top = mid - 1;
				}
				else if (stu[mid] + stu[i] + stu[j] <= 0)
				{
					bot = mid + 1;
				}
			}
			upperBound = top;

			answer += (upperBound - lowerBound + 1);
		}
	}

	cout << answer;

	return 0;
}