// 백준 14921번: 용액 합성하기
// 이거 어제 푼 문제랑 거의 동일한 것 같은데
// 주의: while 루프를 벗어났을 때 top 인덱스가 정해진 범위를 벗어날 수 있음
// (==bot의 초기값보다 작아질 수 있음)

#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int N;
	vector<int> arr;
	int answer = INT_MAX;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int t;
		cin >> t;
		arr.push_back(t);
	}

	for (int i = 0; i < N-1; i++)
	{
		int top = N - 1;
		int bot = i + 1;
		while (top >= bot)
		{
			int mid = (top + bot) / 2;
			if (arr[i] + arr[mid] < 0)
			{
				bot = mid + 1;
			}
			else if (arr[i] + arr[mid] > 0)
			{
				top = mid - 1;
			}
			else
			{
				cout << 0;
				return 0;
			}
		}
		if (bot < N && abs(answer) > abs(arr[i] + arr[bot]))
			answer = arr[i] + arr[bot];
		if(top != i && top >= 0 && abs(answer) > abs(arr[i] + arr[top]))
			answer = arr[i] + arr[top];
	}

	cout << answer; 
	return 0;
}