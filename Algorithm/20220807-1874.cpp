// 백준 1874 : 스택 수열

#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
	int n;
	cin >> n;

	stack<int> stk;
	int next = 1;
	vector<char> out;

	for (int i = 0; i < n; i++)
	{
		int input;
		cin >> input;
		
		for (; next <= input; next++)
		{
			stk.push(next);
			out.push_back('+');
		}
		if (stk.top() == input)
		{
			stk.pop();
			out.push_back('-');
		}
		else
		{
			cout << "NO";
			return 0;
		}
	}
	for (char c : out)
	{
		cout << c << '\n';
	}
	return 0;
}