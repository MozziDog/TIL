#include "bits/stdc++.h"
using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int N, M;
	vector<int> A;

	cin >> N;
	A.resize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	// O(nlogn)
	sort(A.begin(), A.end());
	
	// search
	cin >> M;
	for (int t = 0; t < M; t++)
	{
		int target;
		int left = 0, right = N - 1;
		int mid;
		int result = 0;

		cin >> target;
		while (left <= right)
		{
			mid = (left + right) / 2;
			if (A[mid] == target)
			{
				result = 1;
				break;
			}
			else if (A[mid] > target)
			{
				right = mid - 1;
			}
			else
			{
				left = mid + 1;
			}
		}
		cout << result << '\n';
	}
	return 0;
}