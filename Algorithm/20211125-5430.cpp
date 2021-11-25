// https://www.acmicpc.net/problem/5430
// 시간 초과

#include <iostream>
#include <string>
#include <vector>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);	

	int T;
	std::cin >> T;

	std::string p;
	int n;
	std::string inputBuffer;
	std::vector<int> array;


	for (int testCase = 0; testCase < T; testCase++)
	{
		array.clear();
		bool errorFlag = false;

		bool reversed = false;
		std::cin >> p;
		std::cin >> n;
		std::cin >> inputBuffer;

		if (n != 0)
		{
			inputBuffer.erase(inputBuffer.begin());
			inputBuffer.erase(inputBuffer.end() - 1); // 처음과 끝의 대괄호 지우기
			size_t index;
			while ((index = inputBuffer.find(",")) != std::string::npos)
			{
				std::string token = inputBuffer.substr(0, index);
				array.push_back(std::stoi(token));
				inputBuffer.erase(0, index + 1);
			}
			array.push_back(std::stoi(inputBuffer));
		}

		for (int now = 0; now < p.length(); now++)
		{
			if (p[now] == 'R')
				reversed = !reversed;
			else if (p[now] == 'D')
			{
				if (array.size() != 0) 
				{
					array.erase(reversed ? array.end() - 1 : array.begin());
				}
				else
				{
					std::cout << "error\n";
					errorFlag = true;
					break;
				}
			}
		}

		if (errorFlag == true)
		{
			continue;
		}

		std::cout << "[";
		if (array.size() > 0)
		{
			if (reversed == false)
			{
				for (int i = 0; i < array.size() - 1; i++)
				{
					std::cout << array[i] << ",";
				}
				std::cout << array.back();
			}
			else
			{
				for (int i = array.size() - 1; i > 0; i--)
				{
					std::cout << array[i] << ",";
				}
				std::cout << array.front();
			}
		}
		std::cout << "]\n";
	}
}