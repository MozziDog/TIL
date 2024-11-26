// 백준 2110번: 공유기 설치
// 여태까지 이분탐색으로 찾는 것이 항상 '인덱스' 였는데,
// 인덱스 외의 것도 이분 탐색으로 찾을 수 있다는 점을 빨리 깨닫지 못해서 어렵게 느껴진 듯.
// 핵심 아이디어만 떠올리면 그렇게 어렵지 않은 문제였다.

#include<bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int N, C;
	vector<int> arr;
	cin >> N >> C;
	arr.reserve(N);
	for (int i = 0; i < N; i++)
	{
		int t;
		cin >> t;
		arr.push_back(t);
	}
	sort(arr.begin(), arr.end());

	int top = arr[arr.size()-1] - arr[0];
	int bot = 1;
	while (top >= bot)
	{
		int mid = (top + bot) / 2;
		int lastHouse = arr[0];
		int count = 1;
		// mid이상의 간격으로 설치하면 남은 공유기를 다 설치할 수 잇는지 체크
		for (int j = 0; j < N; j++)
		{
			if (arr[j] - lastHouse >= mid)
			{
				count++;
				lastHouse = arr[j];
			}
		}
			
		// 다 설치할 수 있다면
		if (count >= C)
		{
			bot = mid + 1;
		}
		else
		{
			top = mid - 1;
		}
	}
	cout << top;

	return 0;
}