// 백준 10773번 : 제로
// 슬슬 푸는 속도가 빨라진 듯?

#include <iostream>
#include <stack>

using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(0);

	int K;
	cin >> K;

	stack<int> stk;

	for (int i = 0; i < K; i++)
	{
		int input;
		cin >> input;
		if (input == 0)
			stk.pop();
		else
			stk.push(input);
	}

	int sum = 0;
	while (stk.size() != 0)
	{
		sum += stk.top();
		stk.pop();
	}
	cout << sum;
	return 0;
}