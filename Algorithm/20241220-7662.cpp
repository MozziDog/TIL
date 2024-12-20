// 백준 7662번: 이중 우선순위 큐
// (multi)set, (multi)map은 이진탐색 트리로 구현되어있으므로, O(log n)에 삽입/삭제가 가능하다.
// 해시 기반의 unordered_xxx 보다는 느리지만 항상 정렬된다는 특징이 있으므로 그때그때 골라 쓰기.
// O(log n)이라도 노드 재배열 등의 과정이 있어 생각보다는 느리다. 
// 대신 해시는 해시 충돌 시 O(n)까지 시간복잡도가 치솟지만 이진탐색 트리는 그런 게 없이 어느정도 수행시간을 예측가능할 수 있다는 점도 차이점.
// 근데 iterator 왜 it+n, it-n 안되냐 되야할 것 같이 생겼는데
// 아 노드 기반이라 실제 메모리상에서 연속되지는 않아서 그렇다고 하네. 마치 연결리스트와 같은 거구나
// 찾아보니 it+n이 되는 건 random access iterator라고 하고 ++/--만 되는 건 bidirectional iterator라고 한단다.

#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int t, k;
	cin >> t;
	while (t--)
	{
		multiset<int> q;
		cin >> k;
		while (k--)
		{
			char op;
			int arg;
			cin >> op >> arg;
			if (op == 'I')
				q.insert(arg);
			else if (op == 'D')
				if (q.empty()) continue;
				else if (arg == 1)
				{
					q.erase(--q.end());
				}
				else
					q.erase(q.begin());
		}
		if (q.empty())
			cout << "EMPTY\n";
		else
			cout << *(--q.end()) << ' ' << *(q.begin()) << '\n';
	}
	return 0;
}