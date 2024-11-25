// 백준 2473번: 세 용액
// 1트에 맞춰버릴 수 있었는데... 1) 오타 때문에, 2) 자료형 범위 때문에 아쉽게 틀림
// 항상 자료형 범위를 신경쓰자!

#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int N;
	vector<long long> arr;
	long long answer[] = { 0, 0, 0 };
	long long answerSum = LLONG_MAX;

	cin >> N;
	arr.reserve(N);
	for (int i = 0; i < N; i++)
	{
		int t;
		cin >> t;
		arr.push_back(t);
	}
	sort(arr.begin(), arr.end());

	for (int i = 0; i < N - 2; i++)
	{
		for (int j = i + 1; j < N - 1; j++)
		{
			long long toFind = -(arr[i] + arr[j]);
			int top = N - 1;
			int bot = j + 1;
			while (top >= bot)
			{
				int mid = (top + bot) / 2;
				if (arr[mid] < toFind)
				{
					bot = mid + 1;
				}
				else if (arr[mid] > toFind)
				{
					top = mid - 1;
				}
				else
				{
					cout << arr[i] << ' ' << arr[j] << ' ' << arr[mid];
					return 0;
				}
			}
			if (top > j && abs(arr[i] + arr[j] + arr[top]) < abs(answerSum))
			{
				answer[0] = arr[i];
				answer[1] = arr[j];
				answer[2] = arr[top];
				answerSum = arr[i] + arr[j] + arr[top];
			}
			if (bot < N && abs(arr[i] + arr[j] + arr[bot]) < abs(answerSum))
			{
				answer[0] = arr[i];
				answer[1] = arr[j];
				answer[2] = arr[bot];
				answerSum = arr[i] + arr[j] + arr[bot];
			}
		}
	}

	cout << answer[0] << ' ' << answer[1] << ' ' << answer[2];
	return 0;
}