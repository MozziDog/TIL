// 백준 1927번: 최소 힙
// 오늘만 직접 구현하고 이후부터는 걍 STL 써야지

#include <bits/stdc++.h>
using namespace std;

int arr[100000];
int heapSize = 0;

// 왼쪽 자식: 2n
// 오른쪽 자식: 2n + 1
// 부모: n/2
int leftChild(int parent) { return 2 * parent; }
int rightChild(int parent) { return 2 * parent + 1; }
int parent(int child) { return child / 2; }

void push(int value)
{
	heapSize++;
	arr[heapSize] = value;
	// 버블링
	int index = heapSize;
	while (index > 1)
	{
		if (arr[index] >= arr[parent(index)]) break;
		swap(arr[parent(index)], arr[index]);
		index = parent(index);
	}
}

int fetch()
{
	if (heapSize == 0) return 0;
	else return arr[1];
}

void pop()
{
	if (heapSize == 0) return;
	swap(arr[1], arr[heapSize]);
	arr[heapSize] = 0;	// 굳이 안해도 되지만 디버깅 편의를 위해 0으로 초기화
	heapSize--;
	int index = 1;
	while (leftChild(index) <= heapSize)
	{
		int minChild = leftChild(index);
		if(heapSize >= rightChild(index) && arr[minChild] > arr[rightChild(index)])
			minChild = rightChild(index);
		if (arr[index] < arr[minChild]) break;
		swap(arr[index], arr[minChild]);
		index = minChild;
	}
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int N, x;
	cin >> N;
	while (N--)
	{
		cin >> x;
		if (x == 0)
		{
			cout << fetch() << '\n';
			pop();
		}
		else
		{
			push(x);
		}
	}
	return 0;
}