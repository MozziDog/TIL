// 백준 11653번: 소인수분해
#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int N;
	int i = 2;

	cin >> N;
	
	while (N >= i * i)
	{
		if (N % i == 0)
		{
			N /= i;
			cout << i << '\n';
		}
		else
		{
			i++;
		}
	}
	if(N != 1)
		cout << N;

	return 0;
}