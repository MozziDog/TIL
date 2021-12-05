// https://www.acmicpc.net/problem/6603
// 나중에 재귀(백트래킹) 방식으로도 한번 풀어봐야겠다.
// 근데 아무리 생각해봐도 이게 제일 간단한 해결방법임.

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (true)
	{
		vector<int> numbers;
		int count, tmp;
		cin >> count;
		if (count == 0)
			break;

		for (int i = 0; i < count; i++)
		{
			cin >> tmp;
			numbers.push_back(tmp);
		}

		for (int n1 = 0; n1 < numbers.size(); n1++)
		{
			for (int n2 = n1+1; n2 < numbers.size(); n2++)
			{
				for (int n3 = n2+1; n3 < numbers.size(); n3++)
				{
					for (int n4 = n3+1; n4 < numbers.size(); n4++)
					{
						for (int n5 = n4+1; n5 < numbers.size(); n5++)
						{
							for (int n6 = n5+1; n6 < numbers.size(); n6++)
							{
								cout << numbers[n1] << " " << numbers[n2] << " " << numbers[n3] << " " << numbers[n4] << " " << numbers[n5] << " " << numbers[n6] << "\n";
							}
						}
					}
				}
			}
		}
		cout << "\n";
	}
	return 0;
}