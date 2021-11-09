#pragma warning(disable: 4996)

// https://www.acmicpc.net/problem/12865
// DP 점화식 찾는 거 너무 어려움 ㅜㅜ

#include <iostream>
#include <vector>

using namespace std;
#define item pair<int,int>
#define weight first
#define value second



int main()
{
	int N;
	scanf("%d", &N);
	int K;
	scanf("%d", &K);

	vector<item> items;

	item emptyItem(0, 0);
	items.push_back(emptyItem);

	for (int i = 0; i < N; i++)
	{
		item tmp;
		scanf("%d", &tmp.weight);
		scanf("%d", &tmp.value);
		items.push_back(tmp);
	}

	int** DP = new int*[N+1];
	for(int i=0; i<=N; i++)
	{
		DP[i] = new int[K + 1]();
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j <= K; j++) // j는 현재 가방 무게
		{
			if (j < items[i].weight)
			{
				DP[i][j] = DP[i - 1][j];
			}
			else
			{
				DP[i][j] = max(DP[i - 1][j], DP[i - 1][j - (items[i].weight)] + items[i].value);
			}
		}
	}

	printf("%d", DP[N][K]);

	return 0;
}