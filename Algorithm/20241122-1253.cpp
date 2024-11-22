// 백준 1253번: 좋다
// 이분탐색 문제집에 있어서 풀어봤지만 이분 탐색으로 풀만한 문제는 아닌 것 같다. 
// 오히려 투포인터로 푸는 게 코드도 간단하고 시간복잡도도 더 낫다.
// 이분탐색으로 풀면 O(N^2 * logN), 투포인터로 풀면 O(N^2).

#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int N;
	vector<int> arr;
	int answer = 0;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int t;
		cin >> t;
		arr.push_back(t);
	}
	sort(arr.begin(), arr.end());

	for (int i = 0; i < N; i++)
	{
		int l = 0, r = N - 1;
		while (l < r)
		{
			int sum = arr[l] + arr[r];
			if (sum == arr[i])
			{
				if (i != l && i != r)
				{
					answer++;
					break;
				}
				else if (l == i) l++;
				else if (r == i) r--;
			}
			else if (sum < arr[i])
				l++;
			else
				r--;
		}
	}

	cout << answer;
	return 0;
}