// 백준 2217번: 로프
// 다수의 약한 로프를 병렬로 사용하면 큰 무게를 들어올릴 수 있다는 점을 간과함.
// 틀렸던 테스트 케이스 예시:
/*
10
2 2 2 2 2 2 2 2 2 10
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int N;
	vector<int> ropes;
	int selectedCount = 0, selectedMin;
	int answer = 0;
	
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;
		ropes.push_back(tmp);
	}

	sort(ropes.begin(), ropes.end());

	for (int i = 1; i <= N; i++)
	{
		answer = max(ropes[N - i] * i, answer);
	}

	cout << answer;
	return 0;
}