// 백준 10828번 : 스택

// 동일한 코드인데 한 번은 시간 초과나고 한 번은 그냥 통과되었음.... 뭐지

#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(0);

	int N;
	cin >> N;
	stack<int> stk;
	for (int i = 0; i < N; i++)
	{
		string cmd;
		cin >> cmd;
		if (!cmd.compare("push"))
		{
			int num;
			cin >> num;
			stk.push(num);
			continue;
		}
		if (!cmd.compare("pop"))
		{
			if (stk.size() == 0)
			{
				cout << -1 << "\n";
				continue;
			}
			else
			{
				cout << stk.top() << "\n";
				stk.pop();
				continue;
			}
		}
		if (!cmd.compare("size"))
		{
			cout << stk.size() << "\n";
			continue;
		}
		if (!cmd.compare("empty"))
		{
			cout << stk.empty() << "\n";
			continue;
		}
		if (!cmd.compare("top"))
		{
			if (stk.size() == 0)
				cout << -1 << "\n";
			else
				cout << stk.top() << "\n";
		}
	}
	return 0;
}