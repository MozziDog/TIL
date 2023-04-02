// 백준 1697번: 숨바꼭질
// 성공
// 오늘의 교훈: 제출 전에 엣지케이스들을 생각해보고 테스트해보자

#include <bits/stdc++.h>

using namespace std;

int location[100001];

int main()
{
	int N, K;
	queue<int> que;

	fill(location, location + 100001, INT_MAX);

	cin >> N >> K;
	location[N] = 0;
	que.push(N);

	while (!que.empty())
	{
		int cur = que.front();
		int time = location[cur];
		que.pop();
		if (cur == K)
		{
			cout << time;
			return 0; 
		}

		if (cur + 1 <= 100000 && location[cur + 1] > time + 1)
		{
			location[cur + 1] = time + 1;
			que.push(cur + 1);
		}
		if (cur - 1 >= 0 && location[cur - 1] > time + 1)
		{
			location[cur - 1] = time + 1;
			que.push(cur - 1);
		}
		if (cur * 2 <= 100000 && location[cur * 2] > time + 1)
		{
			location[cur * 2] = time + 1;
			que.push(cur * 2);
		}
	}
	return 0;
}