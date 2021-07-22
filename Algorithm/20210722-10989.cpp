// 백준 10989 수 정렬하기3
// # 카운팅 정렬 (계수 정렬)

#include <iostream>
#define LENGTH 10001
using namespace std;

int main()
{
	ios_base:: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	cin>>N;
	int num[LENGTH] = {0,};
	for(int i = 0; i < N; i++)
	{
		int tmp;
		cin>>tmp;
		num[tmp]++;
	}
	for(int i = 0; i<LENGTH; i++)
	{
		for(int j=0; j<num[i]; j++)
		{
			cout<<i<<"\n";
		}
	}
	return 0;
}