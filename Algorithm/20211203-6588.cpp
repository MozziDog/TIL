// https://www.acmicpc.net/problem/6588
// 골드바흐의 추측

#include <iostream>

using namespace std;
const int MAX_NUM = 1000001;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	bool* isPrime = new bool[MAX_NUM]();
	fill_n(isPrime + 2, MAX_NUM - 2, true);
	for (int i = 2; i < MAX_NUM; i++)
	{
		if (isPrime[i] == false)
			continue;
		for (int j = 2 * i; j < MAX_NUM; j += i)
		{
			isPrime[j] = false;
		}
	}

	int n; bool isGoldbachRight = false;
	while (true)
	{
		isGoldbachRight = false;
		cin >> n;
		if (n == 0)
			break;

		for (int i = 2; i < n; i++)
		{
			if (isPrime[i] == true && isPrime[n-i] == true)
			{
				cout << n << " = " << i << " + " << n - i << "\n";
				isGoldbachRight = true;
				break;
			}
		}

		if (isGoldbachRight != true)
		{
			cout << "Goldbach's conjecture is wrong.\n";
		}
	}

	return 0;
}