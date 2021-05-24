//백준 15649번 N과 M. 1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열을 모두 구하기
// 오늘의 결론 : 사전식 배열은 DFS와 연관이 깊다.
// 오늘의 결론2: endl은 개행문자이고 '/n'은 개행문자가 아니다. 개행문자가 오면 출력 버퍼가 강제로 flush되어 출력 속도가 느리다.

#include<iostream>
using namespace std;
#define MAX 9

int n, m;
bool visited[MAX] = {false, };
int arr[MAX] = {};

void printArray(int* arr){
	for(int i=0; i<m; i++){
		cout<<arr[i]<<' ';
	}
	cout<<'\n';
}

void dfs(int count){
	if(count==m){
		//출력
		printArray(arr);
	}
	else{
		for(int i=1; i<=n; i++){
			if(!visited[i]){
				visited[i] = true;
				arr[count] = i;
				dfs(count +1);
				visited[i] = false;
			}
		}
	}
}

int main(){
	cin>>n>>m;
	dfs(0);
	
}