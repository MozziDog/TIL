// 백준 5397 키로거

#include <iostream>
#include <list>

using namespace std;

int main()
{
	int testcase;
	cin >> testcase;
	for (int t=0; t<testcase; t++)
	{
		string input;
		cin >> input;
		list<char> pw;
		auto cursor = pw.begin();
			
		for (char c : input)
		{
			switch (c) {
			case '-':
				if (cursor != pw.begin())
				{
					cursor--;
					cursor = pw.erase(cursor);
				}
				break;
			case '<':
				if (cursor != pw.begin())
					cursor--;
				break;
			case '>':
				if (cursor != pw.end())
					cursor++;
				break;
			default:
				cursor = pw.insert(cursor, c);
				if(cursor != pw.end())
					cursor++;
				break;
			}
		}
		for(cursor = pw.begin(); cursor!= pw.end(); cursor++)
		{
			cout << *cursor;
		}
		cout << '\n';
	}
	return 0;
}