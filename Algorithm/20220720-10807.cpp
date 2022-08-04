// 백준 10807 방 배정

#include <iostream>
using namespace std;

int boys[7], girls[7];	// 전역변수에 선언하면 초기화 안해도 됨.
int main()
{
	int N, K, ans = 0;
	cin >> N >> K;
	for (int i = 0; i < N; i++)
	{
		int sex, grade;
		cin >> sex >> grade;
		if (sex == 1)
			boys[grade] ++;
		else
			girls[grade] ++;\
	}
	for (int i = 1; i <= 6; i++)
	{
		ans += boys[i] / K;
		if (boys[i] % K != 0)
			ans++;
		ans += girls[i] / K;
		if (girls[i] % K != 0)
			ans++;
	}
	cout << ans;
}