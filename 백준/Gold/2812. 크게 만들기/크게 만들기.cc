#include <bits/stdc++.h>
using namespace std;

int N, K;
string str;

class myStack
{
	vector<char> v;
	int s = 0;
public:
	void push(char c)
	{
		if (v.size() > s)
			v[s] = c;
		else
			v.push_back(c);
		s++;
	}
	char top()
	{
		return v[s-1];
	}
	void pop()
	{
		s--;
	}
	int size()
	{
		return s;
	}
	bool empty()
	{
		return s == 0;
	}
	void print()
	{
		for (int i = 0; i < s; i++)
		{
			cout << v[i];
		}
	}
};

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> K;
	cin >> str;

	myStack stk;
	for (char c : str)
	{
		if (!stk.empty() && stk.top() <= c)
		{
			while (K > 0 && !stk.empty() && stk.top() < c)
			{
				stk.pop();
				K--;
			}
		}
		stk.push(c);
	}
	while (K--)
		stk.pop();
	stk.print();
	return 0;
}