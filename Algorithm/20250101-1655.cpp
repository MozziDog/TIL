// 백준 1655번: 가운데를 말해요
// 3년전에 푼 제출이 있길래 비교해봤는데 시간은 지금 코드가 좀 더 낫고 공간은 예전 코드가 좀 더 낫다.
// 뭐때문에 차이가 생기는 거지?
// 48KB... 
// main 함수에서 사용되는 지역변수의 타입과 갯수는 동일한데...
// 몰루겠다...

#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int N, t;
	priority_queue<int> maxHeap;
	priority_queue<int, vector<int>, greater<>> minHeap;

	cin >> N;
	while (N--)
	{
		cin >> t;
		if (maxHeap.empty() || t < maxHeap.top())
			maxHeap.push(t);
		else
			minHeap.push(t);
		if (minHeap.size() > maxHeap.size())
		{
			t = minHeap.top();
			minHeap.pop();
			maxHeap.push(t);
		}
		else if (maxHeap.size() > minHeap.size() + 1)
		{
			t = maxHeap.top();
			maxHeap.pop();
			minHeap.push(t);
		}
		cout << maxHeap.top() << '\n';
	}
	return 0;
}