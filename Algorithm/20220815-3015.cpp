// 백준 3015번 : 오아시스 재결합
// 어려웠다;;

#include <iostream>
#include <stack>
using namespace std;

#define value first
#define count second


int main() {
	int N;
	cin >> N;
	int input;
	stack<pair<int, int>> stk;
	long long answer = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> input;
		while (!stk.empty() && stk.top().value < input)
		{
			answer+= stk.top().count;
			stk.pop();
		}

		if (!stk.empty() && stk.top().value == input)
		{
			stk.top().count++;
			answer += stk.top().count;
		}
		else
		{
			stk.push({ input,1 });
			answer++;
		}
		if (stk.size() == 1)
			answer--;
	}
	cout << answer;

	return 0;
}