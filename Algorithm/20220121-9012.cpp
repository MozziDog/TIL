// https://www.acmicpc.net/problem/9012
// 이전에 이미 푼 문제인데 그때는 C로 풀어서 이번에 C++ 스타일로 다시 풀어봄

#include <iostream>

using namespace std;

int main()
{
	int t;
	cin >> t;
	for (int testCase = 0; testCase < t; testCase++)
	{
		int parenthesisStack = 0;
		bool loopBreakFlag = false;
		string input;
		cin >> input;
		for(int i=0; i<input.size(); i++)
		{
			if (input[i] == '(')
			{
				parenthesisStack++;
			}
			else if (input[i] == ')')
			{
				parenthesisStack--;
				if (parenthesisStack < 0)
				{
					cout << "NO\n";
					loopBreakFlag = true;
					break;
				}
			}
		}
		if (loopBreakFlag == false)
		{
			cout << (parenthesisStack == 0 ? "YES\n" : "NO\n");
		}
	}
	return 0;
}