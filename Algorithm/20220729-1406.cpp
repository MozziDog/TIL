#include <iostream>
#include <list>

using namespace std;

int main()
{
	string str;
	cin >> str;
	list<char> chlist;
	for (char c : str)
	{
		chlist.push_back(c);
	}
	auto cursor = chlist.end();

	int M; 
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		char command;
		cin >> command;
		switch (command)
		{
		case 'L':
			if(cursor != chlist.begin())
				cursor--;
			break;
		case 'D':
			if(cursor != chlist.end())
				cursor++;
			break;
		case 'B':
			if (cursor != chlist.begin())
			{
				cursor--;
				cursor = chlist.erase(cursor);
			}
			break;
		case 'P':
			char input;
			cin >> input;
			chlist.insert(cursor, input);
			break;
		}
	}

	for (char c : chlist)
		cout << c;

	return 0;
}