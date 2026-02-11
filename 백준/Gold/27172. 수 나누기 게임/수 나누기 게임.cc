#include <bits/stdc++.h>
using namespace std;

int N;
int A[100'000], score[1'000'001];
vector<int> divider[1'000'001];
bool cardExist[1'000'001];


int main()
{
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;
	
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
		cardExist[A[i]] = true;
	}
	for (int i = 0; i < N; i++)
	{
		if(A[i] > 1)
			divider[A[i]].push_back(1);
		for (int j = 2; j * j <= A[i]; j++)
		{
			if (A[i] % j == 0)
			{
				divider[A[i]].push_back(j);
				if(j * j != A[i])
					divider[A[i]].push_back(A[i] / j);
			}
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (auto d : divider[A[i]])
		{
			if (cardExist[d])
			{
				score[d]++;
				score[A[i]]--;
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		cout << score[A[i]] << ' ';
	}

	return 0;
}