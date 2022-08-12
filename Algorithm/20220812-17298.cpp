// 백준 17298번 : 오큰수

#include <iostream>
#include <stack>

using namespace std;
#define index first
#define value second

int answer[1000001];

int main() {
	int N;
	cin >> N;
	int input;
	stack<pair<int, int>> stk;
	for (int i = 0; i < N; i++)
	{
		cin >> input;
		while (!stk.empty() && stk.top().value < input)
		{
			answer[stk.top().index] = input;
			stk.pop();
		}
		stk.push({ i, input });
	}
	for (int i = 0; i < N; i++)
	{
		cout << (answer[i] != 0 ? answer[i] : -1) << " ";
	}
	return 0;
}