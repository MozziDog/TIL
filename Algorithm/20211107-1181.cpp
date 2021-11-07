// https://www.acmicpc.net/problem/1181

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool cmp (string a, string b)
{
	if (a.length() != b.length())
	{
		return a.length() < b.length() ? true : false;
	}
	else
	{
		return a.compare(b) < 0 ? true : false;
	}
}


int main()
{
	int N;
	scanf("%d", &N);
	string* words;
	words = new string[N];

	char inputBuffer[50];
	for (int i = 0; i < N; i++)
	{
		scanf("%s", inputBuffer);
		words[i] = inputBuffer;
	}

	sort(words, words + N, cmp);
	
	string laststr = "";

	for (int i = 0; i < N; i++)
	{
		if (words[i] != laststr)
		{
			printf("%s\n", words[i].c_str());
			laststr = words[i];
		}
	}
	return 0;
}