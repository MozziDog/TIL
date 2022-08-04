// 투 포인터로 나중에 다시 풀어봐야?

#include <iostream>
#include <vector>

using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, x;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	cin >> x;

	bool* nums = new bool[2000001];
	for (int i = 0; i < n; i++)
	{
		nums[arr[i]] = true;
	}
	
	int answer = 0;
	for (int i = 0; i < n; i++)
	{
		if(x > arr[i])
			if (nums[x - arr[i]])
				answer++;
	}
	
	cout << answer / 2;
	delete[] arr;
	delete[] nums;

	return 0;
}