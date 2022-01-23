// https://www.acmicpc.net/problem/1874
// 이전에 풀었던 문제인데 그 때 C스타일로 해서 이번에 복습 겸 C++로 다시 풀어봄

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	vector<int> inputArray;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		inputArray.push_back(tmp);
	}

	vector<int> stack;
	vector<char> outputArray;
	int nowNumber = 1;
	bool noFlag = false;
	for (int index = 0; index < n; index++)
	{
		if (stack.size() > 0)
		{
			if (inputArray[index] < *(stack.end() - 1))
			{
				noFlag = true;
				break;
			}
		}
		for (; nowNumber <= inputArray[index]; nowNumber++)
		{
			stack.push_back(nowNumber);
			outputArray.push_back('+');
		}
		stack.pop_back();
		outputArray.push_back('-');
	}

	if (noFlag == true)
	{
		cout << "NO";
	}
	else
	{
		for (int i = 0; i < outputArray.size(); i++)
		{
			cout << outputArray[i] << '\n';
		}
	}

	return 0;
}