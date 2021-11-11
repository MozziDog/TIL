/*
ios_base::sync_with_stdio(false);
cin.tie(NULL); cout.tie(NULL);
*/
// https://www.acmicpc.net/problem/1655

// 시간 초과

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <typename T>
class priorityQueue
{
public:
	vector<T> items;
	T& operator [](int index)
	{
		return items[index];
	}
	void push(T item)
	{
		int i = 0;
		while(true)
		{
			if (items.size() <= i || items[i] > item)
				break;
			i++;
		}
		items.insert(items.begin() + i, item);
	}
	size_t length()
	{
		return items.size();
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	priorityQueue<int> numbers;
	for (int i = 0; i < N; i++)
	{
		int tmp;
		cin >> tmp;
		numbers.push(tmp);
		cout<< numbers[(numbers.length()-1) / 2] << "\n";
	}

	return 0;
}