#include <iostream>
#include <algorithm>
#define R 0
#define G 1
#define B 2

using namespace std;

int main(){
	int N;
	cin>>N;
	int cost[1000][3];
	for(int i=0; i<N; i++)
	{
		cin>>cost[i][R]>>cost[i][G]>>cost[i][B];
	}
	for(int i=1; i<N; i++)
	{
		cost[i][R] = min(cost[i-1][G], cost[i-1][B]) + cost[i][R];
		cost[i][G] = min(cost[i-1][R], cost[i-1][B]) + cost[i][G];
		cost[i][B] = min(cost[i-1][R], cost[i-1][G]) + cost[i][B];
	}
	cout<< min( min(cost[N-1][R], cost[N-1][G]), cost[N-1][B]) <<"\n";
	return 0;
}