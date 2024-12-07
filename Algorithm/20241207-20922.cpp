// 백준 20922번: 겹치는 건 싫어

#include <bits/stdc++.h>
using namespace std;

int numCount[100001];

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int n, k, answer=0;
	cin >> n >> k;
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int bot = 0, top = 0;
	for (; top<n; top++)
	{
		numCount[arr[top]]++;

		while (numCount[arr[top]] > k)
		{
			numCount[arr[bot]]--;
			bot++;
		}

		answer = max(answer, top - bot + 1);
	}
	cout << answer;
	return 0;
}