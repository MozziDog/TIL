#include <iostream>

using namespace std;

int main()
{
	string N;
	cin >> N;
	int num[9] = {0,};
	for (char c : N)
	{
		if (c == '9')
			c = '6';
		num[c - '0']++;
	}
	num[6] -= num[6] / 2;
	int max = 0;
	for (int i=0; i<9; i++)
		if (num[i] > max) max = num[i];
	cout << max;
	return 0;
}