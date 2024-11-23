// 백준 2143번: 두 배열의 합.
// 부배열의 합을 미리 구해둬서 이분탐색 문제로 바꾸는 것이 핵심이었다.

#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int T, N, M;
	long long answer = 0;
	long long A[1001], B[1001];
	vector<long long> Asub, Bsub;

	cin >> T;
	cin >> N;

	A[0] = 0;
	cin >> A[1];
	for (int i = 2; i <= N; i++)
	{
		cin >> A[i];
		A[i] += A[i - 1];
	}
	cin >> M;
	B[0] = 0;
	cin >> B[1];
	for (int i = 2; i <= M; i++)
	{
		cin >> B[i];
		B[i] += B[i - 1];
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N + 1; j++)
		{
			Asub.push_back(A[j] - A[i]);
		}
	}
	for (int i = 0; i < M; i++)
	{
		for (int j = i+1; j < M + 1; j++)
		{
			Bsub.push_back(B[j] - B[i]);
		}
	}

	sort(Bsub.begin(), Bsub.end());
	for (int i = 0; i < Asub.size(); i++)
	{
		int toFind = T - Asub[i];

		int top = Bsub.size() - 1;
		int bot = 0;
		int lowerBound, upperBound;
		while (top >= bot)
		{
			int mid = (top + bot) / 2;
			if (Bsub[mid] >= toFind)
			{
				top = mid - 1;
			}
			else if (Bsub[mid] < toFind)
			{
				bot = mid + 1;
			}
		}
		lowerBound = bot;
		top = Bsub.size() - 1;
		while (top >= bot)
		{
			int mid = (top + bot) / 2;
			if (Bsub[mid] > toFind)
			{
				top = mid - 1;
			}
			else if (Bsub[mid] <= toFind)
			{
				bot = mid + 1;
			}
		}
		upperBound = top;
		answer += (upperBound - lowerBound + 1);
	}

	cout << answer;
	return 0;
}