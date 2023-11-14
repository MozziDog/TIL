// 백준 1026번: 보물
// 그냥 두 배열 다 정렬해버리고 가장 큰 건 가장 작은 거랑 매치시키면 되는 문제였슴.

#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int N; 
	int A[50], B[50];
	int answer = 0;
	
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	for (int i = 0; i < N; i++)
		cin >> B[i];
	sort(&A[0], &A[N]);
	sort(&B[0], &B[N]);
	for (int i = 0; i < N; i++)
	{
		answer += A[i] * B[N - i - 1];
	}
	cout << answer;

	return 0;
}