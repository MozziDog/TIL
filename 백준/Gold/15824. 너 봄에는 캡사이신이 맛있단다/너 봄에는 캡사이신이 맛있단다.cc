#include <bits/stdc++.h>
using namespace std;

#define llong long long

const int MAX = 300'000;
const long long DIVIDER = 1'000'000'007;
int N, A[MAX], pow2Left[MAX];
long long ansPlus, ansMinus;

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	sort(A, A + N);

	// 2의 거듭제곱을 1'000'000'007로 나눴을 때의 나머지를 미리 연산
	pow2Left[0] = 1;
	for (int i = 1; i < N; i++)
	{
		pow2Left[i] = (pow2Left[i - 1] << 1) % DIVIDER;
	}

	for (int i = 1; i < N; i++)
	{
		ansPlus += A[i] % DIVIDER * (pow2Left[i] - 1);
		ansPlus %= DIVIDER;
	}

	for (int i = 0; i < N - 1; i++)
	{
		ansMinus += A[i] % DIVIDER * (pow2Left[N - i - 1] - 1);
		ansMinus %= DIVIDER;
	}

	cout << (ansPlus - ansMinus + DIVIDER) % DIVIDER;
	return 0;
}