// 백준 1202번: 보석 도둑
// 1. set인지 multiset인지 확인 한 번 더 해볼 것
// 2. answer 범위 미리 계산해볼 것. 아니면 무조건 long long으로 선언하든가

#include <bits/stdc++.h>
using namespace std;
#define weight second
#define value first

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int n, k;
	long long answer = 0;
	cin >> n >> k;
	multimap<int, int> jewels;
	multiset<int> bags;
	while (n--)
	{
		int m, v;
		cin >> m >> v;
		jewels.insert({ v, m });
	}
	while (k--)
	{
		int c;
		cin >> c;
		bags.insert(c);
	}

	auto jewel = jewels.end();
	while (!bags.empty())
	{
		if (jewel == jewels.begin()) break;
		jewel = prev(jewel);
		auto bag = bags.lower_bound(jewel->weight);
		if (bag != bags.end())
		{
			answer += jewel->value;
			bags.erase(bag);
		}
	}
	cout << answer;
	return 0;
}