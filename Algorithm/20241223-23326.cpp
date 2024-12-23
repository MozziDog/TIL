// 백준 23326번: 홍익 투어리스트
// 인덱스를 0에서 시작하는 거랑 1에서 시작하는 거랑 둘 중에 0으로 시작하는 걸로 정해놓고 정작 코드 짤 때 1로 시작하는 거랑 헷갈렸다.
// 앞으로는 그냥 문제에서 사용하는 기준을 그대로 가져다 써야할 듯. 
// 문제에서 0으로 시작하면 나도 0으로 하고 문제에서 1로 시작하면 나도 1로 하는 식으로...

#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int N, Q, curPosition = 0;
	set<int> A;
	cin >> N >> Q;

	for(int i=0; i<N; i++)
	{
		int isSpot;
		cin >> isSpot;
		if (isSpot) A.insert(i);
	}

	while (Q--)
	{
		int op, arg;
		cin >> op;
		if (op == 1)
		{
			cin >> arg;
			if (A.find(arg-1) != A.end())
				A.erase(arg - 1);
			else
				A.insert(arg - 1);
		}
		else if (op == 2)
		{
			cin >> arg;
			curPosition = (curPosition + arg) % N;
		}
		else if (op == 3)
		{
			if (A.empty())
			{
				cout << "-1\n";
				continue;
			}
			auto it = A.lower_bound(curPosition);
			if (it != A.end())
				cout << *it - curPosition << '\n';
			else
			{
				cout << *A.begin() - curPosition + N << '\n';
			}
		}
	}
	return 0;
}