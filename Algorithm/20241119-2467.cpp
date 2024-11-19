// 백준 2467번 용액
// 조금 걸리긴 했지만 그래도 1트에 클리어.
// 앞으로도 테스트케이스를 열심히 만들어서 가능한 1트 클리어를 목표로 하자.

#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int N; 
	vector<int> arr;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int t;
		cin >> t;
		arr.push_back(t);
	}

	int answer1 = *(arr.begin()), answer2 = *(arr.end() -1);
	for (int i = 0; i < N; i++)
	{
		int alkali = arr[i];

		int top = arr.size() - 1;
		int bot = i + 1;

		if (alkali > abs(answer1 + answer2))
			break;

		while (top >= bot)
		{
			int mid = (top + bot) / 2;
			if (arr[mid] > -alkali)
			{
				top = mid - 1;
			}
			else if (arr[mid] < -alkali)
			{
				bot = mid + 1;
			}
			else
			{
				answer1 = alkali;
				answer2 = arr[mid];
				break;
			}
		}

		if (top > i && abs(answer1 + answer2) > abs(alkali + arr[top]))
		{
			answer1 = alkali;
			answer2 = arr[top];
		}
		if (bot < N && abs(answer1 + answer2) > abs(alkali + arr[bot]))
		{
			answer1 = alkali;
			answer2 = arr[top + 1];
		}
	}

	cout << answer1 << ' ' << answer2;

	return 0;
}