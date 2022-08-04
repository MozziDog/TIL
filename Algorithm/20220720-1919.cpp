// 백준 1919번 : 애너그램 만들기

#include <iostream>
#include <string>
using namespace std;

int main()
{
	string A, B;
	cin >> A >> B;
	int charCountA[26] = {}, charCountB[26] = {};
	for (char c : A)
		charCountA[c - 'a']++;
	for (char c : B)
		charCountB[c - 'a']++;
	int ans = 0;
	for (int i = 0; i < 26; i++)
		ans += abs(charCountA[i] - charCountB[i]);
	cout << ans;
	return 0;
}