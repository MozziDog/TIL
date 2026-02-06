#include <bits/stdc++.h>
using namespace std;

const int LENGTH = 1'000'001;
const int MIN = -1'000'000'001;

int N, maxLength, A[LENGTH], dp[LENGTH];
vector<int> smallestOfIndex(1, MIN);

void setSmallest(int index, int num)
{
	if (smallestOfIndex.size() > index)
		smallestOfIndex[index] = min(smallestOfIndex[index], num);
	else
		smallestOfIndex.push_back(num);
}

// num보다 작은 largest 원소의 index 찾기
int findIndex(int num)
{
	int start = 0, end = smallestOfIndex.size() - 1;
	while (start <= end)
	{
		int mid = (start + end) / 2;
		if (smallestOfIndex[mid] >= num)
			end = mid - 1;
		else
			start = mid + 1;
	}
	return end;
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;
	A[0] = 0;
	for (int i = 1; i <= N; i++)
	{
		cin >> A[i];
	}

	dp[0] = 0;
	for (int i = 1; i <= N; i++)
	{
		dp[i] = findIndex(A[i]) + 1;
		setSmallest(dp[i], A[i]);
		maxLength = max(maxLength, dp[i]);
	}
	cout << maxLength << '\n';
	int idx = maxLength;
	vector<int> p;
	for (int i = N; i > 0; i--)
	{
		if (dp[i] == idx)
		{
			p.push_back(A[i]);
			idx--;
		}
	}
	for (auto it = p.rbegin(); it != p.rend(); it++)
	{
		cout << *it << ' ';
	}
	return 0;
}