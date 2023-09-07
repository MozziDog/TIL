// 백준 11729번: 하노이 탑 이동 순서
// 재귀 사용할 때 주의할 것: 반드시 Base Condition으로 수렴해서 재귀가 끝나야 함.
// 확실히 재귀라 그런가 메모리를 많이 잡아먹긴 하네요

#include <bits/stdc++.h>
using namespace std;

void rec(int, int, int);
vector<pair<int, int>> moves;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int N;
	cin >> N;

	rec(0, 2, N);

	cout << moves.size() << '\n';
	for (auto i = moves.begin(); i < moves.end(); i++)
	{
		cout << i->first + 1 << ' ' << i->second + 1 << '\n';
	}
	return 0;
}

void rec(int src, int dst, int count)
{
	if (count == 1)
	{
		moves.push_back({ src, dst });
		return;
	}
	int a= 0;
	for (; a == src || a == dst; a++);	// 나머지 축 하나 찾기
	rec(src, a, count - 1);
	moves.push_back({ src, dst });
	rec(a, dst, count - 1);
}