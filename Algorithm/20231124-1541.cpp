// 백준 1541번: 잃어버린 괄호
#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	bool minusEnabled = false;
	string str;
	int num, answer = 0;
	char op;

	cin >> str;
	istringstream ss(str);
	ss >> num;
	answer += num;

	while (ss >> op)
	{
		if (op == '-') minusEnabled = true;
		ss >> num;
		if (minusEnabled) answer -= num;
		else answer += num;
	}

	cout << answer;
	return 0;
}