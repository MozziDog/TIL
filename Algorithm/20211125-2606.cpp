// https://www.acmicpc.net/problem/2606
// 시간 초과할 것 같았는데 그냥 성공해버리네;;

#include <iostream>

int numOfPC;
bool connection[101][101] = { false, };
bool infected[101] = { false, };

void infect(int id)
{
	infected[id] = true;
	for (int i = 1; i <= numOfPC; i++)
	{
		if (connection[id][i] == true && infected[i] == false)
		{
			infect(i);
		}
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL); std::cout.tie(NULL);

	std::cin >> numOfPC;
	int connections;
	std::cin >> connections;

	for (int i = 0; i < connections; i++)
	{
		int x, y;
		std::cin >> x >> y;
		connection[x][y] = true;
		connection[y][x] = true;
	}

	infect(1);

	int count = 0;
	for (int i = 2; i <= numOfPC; i++)
	{
		if (infected[i] == true)
		{
			count++;
		}
	}

	std::cout << count;
	return 0;
}