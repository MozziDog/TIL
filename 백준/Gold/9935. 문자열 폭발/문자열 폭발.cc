#include <bits/stdc++.h>
using namespace std;

char ans[1'000'000];
int stkSize = 0;

bool strcmp(const char* str1, const char* str2, int len)
{
	for (int i = 0; i < len; i++)
	{
		if (*(str1 + i) != *(str2 + i)) return false;
	}
	return true;
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	string input, bomb;
	cin >> input >> bomb;
	char c;
	for(char c : input)
	{
		ans[stkSize] = c;
		stkSize++;
		while (stkSize >= bomb.size() && ans[stkSize-1] == bomb[bomb.size() - 1])
		{
			if (strcmp(ans + (stkSize - bomb.size()), bomb.c_str(), bomb.size()))
				stkSize -= bomb.size();
			else break;
		}
	}
	if (stkSize == 0)
		cout << "FRULA";
	else
		for (int i = 0; i < stkSize; i++)
			cout << ans[i];

	return 0;
}