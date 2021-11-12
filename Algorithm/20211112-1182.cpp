/*
ios_base::sync_with_stdio(false);
cin.tie(NULL); cout.tie(NULL);
*/

// https://www.acmicpc.net/problem/1182

#include <iostream>

using namespace std;

int N, S;
int* num;
int answerCount = 0;

void foo(int, int);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> S;
	num = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> num[i];
	}

	foo(0, 0);

	cout << answerCount;
	return 0;
}

void foo(int index, int subtotal)
{
	if (subtotal + num[index] == S)
	{
		answerCount++;
	}
	if (index >= N - 1)
	{
		return;
	}
	foo(index + 1, subtotal);
	foo(index + 1, subtotal + num[index]);
}