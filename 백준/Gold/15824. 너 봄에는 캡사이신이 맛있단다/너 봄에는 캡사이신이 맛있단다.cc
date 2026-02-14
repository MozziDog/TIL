#include <bits/stdc++.h>
using namespace std;

const int MAX = 300'000;
const long long DIVIDER = 1'000'000'007;
int N, A[MAX], pow2Left[MAX];
long long ans = 0;

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

	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			ans += (A[j] - A[i]) % DIVIDER * pow2Left[j - i - 1];
			ans %= DIVIDER;
		}
	}

	cout << ans;
	return 0;
}