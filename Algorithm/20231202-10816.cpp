// 백준 10816번: 숫자 카드 2

#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int N, M;
	vector<int> nums;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;
		nums.push_back(tmp);
	}
	sort(nums.begin(), nums.end());
	
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int toFind;
		int start = 0, end = -1;
		int c1 = 0, c2 = N - 1;

		cin >> toFind;
		while (c1 <= c2)		// 우선 시작점 찾기
		{
			int half = (c1 + c2) / 2;
			if (nums[half] > toFind)
			{
				c2 = half - 1;
			}
			else if (nums[half] < toFind)
			{
				c1 = half + 1;
			}
			else  // if (nums[half] == toFind)
			{
				if (half == 0 || nums[half - 1] != nums[half])
				{
					start = half;
					break;
				}
				else
				{
					c2 = half - 1;
				}
			}
		}
		c1 = 0; c2 = N - 1;
		while (c1 <= c2)		// 다음으로 끝나는 지점 찾기
		{
			int half = (c1 + c2) / 2;
			if (nums[half] > toFind)
			{
				c2 = half - 1;
			}
			else if (nums[half] < toFind)
			{
				c1 = half + 1;
			}
			else  // if (nums[half] == toFind)
			{
				if (half == N-1 || nums[half + 1] != nums[half])
				{
					end = half;
					break;
				}
				else
				{
					c1 = half + 1;
				}
			}
		}
		cout << (end - start + 1) << ' ';
	}
	return 0;
}