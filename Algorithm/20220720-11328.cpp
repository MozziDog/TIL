// 백준 11328번 : Strfry

#include <iostream>
#include <string>
using namespace std;

int main()
{
	int N;
	cin >> N;
	string origin, strfried;
	for (int i = 0; i < N; i++)
	{
		int charCountOrigin[26] = {}, charCountStrfried[26] = {};
		cin >> origin >> strfried;
		for (char c : origin)
		{
			charCountOrigin[c - 'a']++;
		}
		for (char c : strfried)
		{
			charCountStrfried[c - 'a']++;
		}
		string answer = "Possible\n";
		for(int i=0; i<26; i++)
			if (charCountOrigin[i] != charCountStrfried[i])
			{
				answer = "Impossible\n";
				break;
			}
		cout << answer;
	}
}