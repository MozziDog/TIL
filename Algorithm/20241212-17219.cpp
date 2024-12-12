// 백준 17219번: 비밀번호 찾기
// unordered_map을 알고만 있으면 3분 카레 데워지기 전에 풀 수 있는 간단한 문제

#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int N, M;
	unordered_map<string, string> pwdict;	// 사이트/비번 순
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string site, pw;
		cin >> site >> pw;
		pwdict.insert({ site, pw });
	}

	for (int i = 0; i < M; i++)
	{
		string q;
		cin >> q;
		cout << pwdict[q] << '\n';
	}

	return 0;
}