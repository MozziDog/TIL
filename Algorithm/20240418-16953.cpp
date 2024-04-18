// 백준 16953번: A → B
// A to B를 반대로 B to A로 접근하기를 생각안해본 건 아닌데
// 확실히 반대로 접근하니까 오버플로우 문제가 없어서 좋다.

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int A, B;
	int level = 0;
	cin >> A >> B;

	while (A <= B)
	{
		level++;
		if (A == B)
		{
			cout << level;
			return 0;
		}

		if (B % 2 == 0)
		{
			B /= 2;
		}
		else if (B % 10 == 1)
		{
			B /= 10;
		}
		else
		{
			break;
		}
	}
	
	cout << -1;
	return 0;
}