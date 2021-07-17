//백준 9375번 패션왕 신해빈
// 21.07.17 정답!

#include <iostream>
#include <string>
#include <map>
using namespace std;

int main(void){
	int testCase, n;
	multimap<string, string> closet;
	cin>>testCase;
	string category, item;
	for(int t=0; t<testCase; t++)
	{
		cin>>n;
		for(int i=0; i<n; i++)
		{
			cin>>item>>category;
			closet.insert(pair<string, string>(category, item));
		}
		int numOfCategory[n] = {0,};
		int categoryIndex = 0;
		multimap<string, string>::iterator it = closet.begin();
		while(it != closet.end())
		{
			numOfCategory[categoryIndex] = closet.count(it->first);
			categoryIndex ++;
			it = closet.upper_bound(it->first); 
			// upper_bound는 폐구간을 쓰기 때문에 key값이 it->first인 마지막 원소의 다음값을 가리킴.
		}
		
		int answer = 1;
		for(int i=0; i<categoryIndex; i++)
		{
			answer *= (numOfCategory[i] + 1);
		}
		answer -= 1;
		cout<<answer<<"\n";
		closet.clear();
	}
	return 0;
}