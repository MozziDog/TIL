// https://www.acmicpc.net/problem/1406
// 에디터
// 1트 : 시간 초과. string으로 구현하니 너무 느린 듯.
// 2트 : string으로 되어있던 구현을 연결 리스트로 재구현. 시간 복잡도를 mn에서 m으로 줄임. 
// 정답!

#include <iostream>
#include <list>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string strInput;
	cin >> strInput;

	list<char> strList;
	for (int i = 0; i < strInput.size(); i++)
	{
		strList.push_back(strInput.at(i));
	}

	list<char>::iterator cursorPosition = strList.end();

	int m; // 명령어 갯수
	cin >> m;

	for (int i = 0; i < m; i++)
	{
		char command;
		cin >> command;
		switch (command)
		{
		case 'L':
			if (cursorPosition != strList.begin())
				cursorPosition--;
			break;
		case 'D':
			if (cursorPosition != strList.end())
				cursorPosition++;
			break;
		case 'B':
			if (cursorPosition != strList.begin())
			{
				list<char>::iterator tmp = cursorPosition;
				tmp--;
				strList.erase(tmp); // erase의 parameter로 주어진 iterator는 invalidate되기 때문에 cursorPosition 대신 tmp로 대체하여 사용
			}
			break;
		case 'P':
			char input;
			cin >> input;
			strList.insert(cursorPosition, input);
			break;
		default:
			break;
		}
	}

	for (list<char>::iterator i = strList.begin(); i != strList.end(); i++)
	{
		cout << *i;
	}
	return 0;
}