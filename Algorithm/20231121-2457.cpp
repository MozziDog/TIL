// 백준 2457번: 공주님의 정원
// 엣지케이스에서 무한 루프 발생할 수 있는 것 항상 주의하기!

#include <bits/stdc++.h>
#define bloom second
#define fall first
using namespace std;

bool cmpByBloom(const pair<int, int>& a, const pair<int, int>& b)
{
	if (a.bloom < b.bloom)
		return true;
	return false;
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int N;
	int currentFall = 3 * 31 + 1;
	int answer = 0;
	bool flag = false;
	vector<pair<int, int>> flowers;		// 앞이 지는 날짜, 뒤가 피는 날짜

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int startMon, startDay, endMon, endDay;
		cin >> startMon >> startDay >> endMon >> endDay;
		flowers.push_back({ endMon * 31 + endDay, startMon * 31 + startDay });
	}

	// 여기 없으면 아래쪽의 while문에서 무한루프를 돌게 됨.
	// 피는 날짜로 정렬
	sort(flowers.begin(), flowers.end(), cmpByBloom);
	if (flowers.front().bloom > 3 * 31 + 1)
	{
		cout << 0;
		return 0;
	}

	// 지는 날짜로 정렬
	sort(flowers.begin(), flowers.end());
	if (flowers.back().fall <= 11 * 31 + 30)
	{
		cout << 0;
		return 0;
	}
	
	while (true)
	{
		auto nextFlower = flowers.rbegin();
		for (; nextFlower < flowers.rend(); nextFlower++)
		{
			if (nextFlower->fall <= currentFall)	// 지는 날짜가 마지막으로 지는 날짜보다 앞서면 안됨.
			{
				cout << 0;
				return 0;
			}

			if (nextFlower->bloom > currentFall) // 피는 날짜가 지는 날짜보다 같거나 더 일러야 됨.
				continue;

			currentFall = nextFlower->fall;
			answer++;
			break;
		}
		if (currentFall > 11 * 31 + 30)
		{
			cout << answer;
			return 0;
		}
	}
	
	return 0;
}