#include<bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int n, top = 0, bot = 0;
	long long answer = 0;
	vector<int> arr;
	bool exist[100001];

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		arr.push_back(t);
	}

	fill(exist, exist + n + 1, false);
	for (; bot<n; bot++)
	{
		for (; top < n; top++)
		{
			if (exist[arr[top]] == true) break;
			exist[arr[top]] = true;
		}
		answer += top - bot;
		exist[arr[bot]] = false;
	}

	cout << answer;
	return 0;
}