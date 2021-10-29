// https://www.acmicpc.net/problem/9095
// 아니 이건 맞는 것 같은데 왜 백준은 틀렸다고 하지?????????

#include <iostream>

using namespace std;

int GetExpressedBy123(int);

int main()
{
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++)
	{
		int n;
		scanf("%d", &n);
		printf("%d", GetExpressedBy123(n));
	}
	return 0;
}

int GetExpressedBy123(int leftNumbers)
{
	if (leftNumbers <= 0)
		return 0;
	if (leftNumbers == 1)
		return 1;
	if (leftNumbers == 2)
		return 2;
	if (leftNumbers == 3)
		return 4;

	return GetExpressedBy123(leftNumbers - 3) + GetExpressedBy123(leftNumbers - 2) + GetExpressedBy123(leftNumbers - 1);
}