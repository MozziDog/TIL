// 백준 2805번: 나무 자르기
// 각 변수가 가질 수 있는 범위 꼭 확인하기!

#include "bits/stdc++.h"
using namespace std;

int N, M; 
vector<int> tree;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int maxHeight = 1;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		int t;
		cin >> t;
		tree.push_back(t);
		if (maxHeight < t) maxHeight = t;
	}

	int top = maxHeight, bot = 0;
	while (top >= bot)
	{
		int mid = (top + bot) / 2;
		long long sum = 0;
		for (int i = 0; i < N; i++)
		{
			sum += max(tree[i] - mid, 0);
		}
		if (sum >= M)
			bot = mid + 1;
		else
			top = mid - 1;
	}
	cout << top;

	return 0;
}