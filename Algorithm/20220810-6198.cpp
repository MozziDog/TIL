// 백준 6198번 : 옥상 정원 꾸미기
// 오늘의 교훈 1 : 자료형의 범위를 항상 생각하자
// 오늘의 교훈 2 : 거꾸로 생각해보자. 
// A를 관측할 수 있는 B의 갯수를 세서 합치는 것 뿐만 아니라
// B가 관측당할 수 있는 A의 갯수를 세서 합칠 수도 있다.

#include <iostream>
#include <stack>
using namespace std;

#define index first
#define height second

int main()
{
	int N;
	cin >> N;
	stack<pair<int, long long>> stk;
	long long answer=0;
	long long input;
	for (int i = 0; i < N; i++)
	{
		cin >> input;
		while (!stk.empty() && stk.top().height <= input)
			stk.pop();
		answer += stk.size();
		stk.push({ i, input });
	}
	cout << answer;
}