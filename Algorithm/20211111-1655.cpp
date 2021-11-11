/*
ios_base::sync_with_stdio(false);
cin.tie(NULL); cout.tie(NULL);
*/
// https://www.acmicpc.net/problem/1655
// 힙을 사용한 우선순위 큐
// 근데 힙(또는 큐)을 사용하면 top밖에 접근하지 못하므로 위아래로 두개의 힙을 사용해서 가운데에 있는 요소를 접근 가능하게 함.

#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	priority_queue<int> maxHeap; // 가운뎃값보다 작은(또는 같은) 부분은 내림차순. 왜냐하면 queue는 top만 접근할 수 있으니까 가운뎃값에 가까운 쪽이 top이 되어야 계산을 할 수 있음.
	priority_queue<int, vector<int>, greater<int>> minHeap; // 가운뎃값보다 큰 부분은 오름차순.

	int N;
	cin >> N;

	int tmp = 0; 
	cin >> tmp;
	maxHeap.push(tmp);
	cout << maxHeap.top() << "\n";

	for (int i = 1; i < N; i++)
	{
		cin >> tmp;
		
		// maxHeap과 minHeap에 골고루 들어가도록 push. 그래야 딱 정가운데의 값을 뽑아낼 수 있음.
		if (maxHeap.size() <= minHeap.size())
		{
			maxHeap.push(tmp);
		}
		else
		{
			minHeap.push(tmp);
		}

		if (maxHeap.top() > minHeap.top()) // 가운뎃값보다 큰게 maxHeap으로 들어가거나 작은게 minHeap으로 들어갔다면 둘을 교환. 
		// 마치 Quicksort에서 피봇 기준으로 반 가르는 느낌? 나눠진 반에 대한 나머지 정렬은 힙 구조가 알아서 해줌.
		{
			int a = maxHeap.top(), b = minHeap.top();
			maxHeap.pop(); 
			minHeap.pop();
			maxHeap.push(b);
			minHeap.push(a);
		}

		cout << maxHeap.top() << "\n";
	}
	return 0;
}