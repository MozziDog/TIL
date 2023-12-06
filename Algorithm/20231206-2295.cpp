// 백준 2295번: 세 수의 합
// O(N^4)가 걸릴 작업을 2단계로 구분, 
// 사전 계산된 결과들을 모아놓은 two 배열을 만드는 것과 해당 배열에서 조건을 만족하는 경우를 검색하는 것으로
// O(N^2 * logN)까지 시간 복잡도를 줄일 수 있다.

#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int N;
	vector<int> nums;
	vector<int> two;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;
		nums.push_back(tmp);
	}

	sort(nums.begin(), nums.end());
	// two 배열 구하기
	for (int i = 0; i < nums.size(); i++)
	{
		for (int j = 0; j < nums.size(); j++)
		{
			two.push_back(nums[i] + nums[j]);
		}
	}
	sort(two.begin(), two.end());

	// 탐색
	for (int i = nums.size() - 1; i >= 0; i--)
	{
		for (int j = 0; j < nums.size(); j++)
		{
			if(binary_search(two.begin(), two.end(), nums[i] - nums[j]))
			{
				cout << nums[i];
				return 0;
			}
		}
	}

	return 0;
}