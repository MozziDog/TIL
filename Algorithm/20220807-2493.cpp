// 백준 2493번 : 탑

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int answer[500001];
int main()
{
	int N;
	cin >> N;
	stack<int> stk;
	vector<int> heightof;

	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;
		heightof.push_back(input);
	}

	int lastIndex = N-1;

	for (int i = 0; i < N; i++)
	{
		if (stk.size() == 0)
		{
			stk.push(lastIndex--);
			continue;
		}
		while (stk.size() > 0)
		{
			if (heightof[stk.top()] < heightof[lastIndex])
			{
				answer[stk.top()] = lastIndex+1;
				stk.pop();
			}
			else
				break;
		}
		stk.push(lastIndex--);
	}
	for (int i = 0; i < N; i++)
	{
		cout << answer[i] << ' ';
	}
	return 0;
}