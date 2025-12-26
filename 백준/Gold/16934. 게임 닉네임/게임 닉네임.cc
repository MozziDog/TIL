#include <bits/stdc++.h>
using namespace std;

const int ROOT = 1;
const int MAX = 10 * 100'000 + 1;
int nxt[MAX][26 + 10];
int chk[MAX];
int curSize = 1;

int N;
vector<string> ans;

inline int ctoi(char c) { 
	if (c > '0' && c <= '9') return c - '0'; 
	else return c - 'a' + 10; 
}

void insert(string str)
{
	int curIdx = ROOT;
	bool found = false;
	for(int i = 0; i<str.size(); i++)
	{
		char c = str[i];
		if (nxt[curIdx][ctoi(c)] == 0)
		{
			nxt[curIdx][ctoi(c)] = ++curSize;
			if (!found)
			{
				found = true;
				ans.push_back(str.substr(0, i+1));
			}
		}
		curIdx = nxt[curIdx][ctoi(c)];
	}
	chk[curIdx]++;
	if (!found)
	{
		int dupCount = chk[curIdx];
		if (dupCount == 1)
			ans.push_back(str);
		else
		{
			ostringstream newStr(str, ios_base::ate);
			newStr << dupCount;
			ans.push_back(newStr.str());
		}
	}
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string input;
		cin >> input;
		insert(input);
	}
	for (auto s : ans)
	{
		cout << s << '\n';
	}

	return 0;
}