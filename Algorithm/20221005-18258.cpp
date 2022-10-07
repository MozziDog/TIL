#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	queue<int> q;

	int N;
	cin >> N;
	while (N--)
	{
		string inst;
		cin >> inst;
		if (inst.compare("push")==0)
		{
			int num;
			cin >> num;
			q.push(num);
		}
		else if (inst.compare("pop") == 0)
		{
			if (q.empty())
				cout << -1 << "\n";
			else
			{
				cout << q.front() << "\n";
				q.pop();
			}
		}
		else if (inst.compare("size") == 0)
		{
			cout << q.size() << "\n";
		}
		else if (inst.compare("empty") == 0)
		{
			cout << (q.empty() ? 1 : 0) << "\n";
		}
		else if (inst.compare("front") == 0)
		{
			if (q.empty())
				cout << -1 << "\n";
			else
				cout << q.front() << "\n";
		}
		else if (inst.compare("back") == 0)
		{
			if (q.empty())
				cout << -1 << "\n";
			else
				cout << q.back() << "\n";
		}
	}
	return 0;
}