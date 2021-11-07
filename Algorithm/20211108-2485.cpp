#pragma warning(disable: 4996)

// https://www.acmicpc.net/problem/2485

#include <iostream>

int Euclidean(int, int);

int main()
{
	int N;
	scanf("%d", &N);
	int* trees = new int[N];
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &trees[i]);
	}
	int dist = Euclidean(trees[1] - trees[0], trees[2] - trees[1]);
	for (int i = 2; i < N - 1; i++)
	{
		Euclidean(dist, trees[i + 1] - trees[i]);
	}
	int answer = (trees[N - 1] - trees[0]) / dist + 1 - N;
	printf("%d", answer);
	return 0;
}

int Euclidean(int a, int b)
{
	int leftover = a>b? a:b;
	int gcd = a>b? b:a;
	while (true)
	{
		if (leftover % gcd == 0)
		{
			break;
		}
		else
		{
			int tmp = leftover % gcd;
			leftover = gcd;
			gcd = tmp;
		}
	}
	return gcd;
}

