// 백준 2661번
// 정답

#include <iostream>
#include <string>

using namespace std;

int N;

bool isPromising(string array)
{
	for (int i = 1; i <= array.length() / 2; i++)
	{
		string substr = array.substr(array.length() - i, i);
		if (substr.compare(array.substr(array.length() - i - i, i)) == 0)
		{
			return false;
		}
	}
	return true;
}

void solve(string str)
{
	if (isPromising(str))
	{
		if (str.length() == N)
		{
			cout << str;
			exit(0);
		}
		
		for (auto i = '1'; i <= '3'; i++)
		{
			string newstr = str;
			newstr.push_back(i);
			solve(newstr);
		}
	}
	return;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	string array;
	solve(array);
	return 0;
}