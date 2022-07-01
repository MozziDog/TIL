// 백준 1002번 : 터렛
// https://www.acmicpc.net/problem/1002

# include <iostream>

int main()
{
	int T;
	std::cin >> T;
	for (int t = 0; t < T; t++)
	{
		int x1, y1, r1, x2, y2, r2;
		std::cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		int dx = x2 - x1, dy = y2 - y1;
		int sqdist = dx * dx + dy * dy;
		if (x1 == x2 && y1 == y2 && r1 == r2)
			std::cout << -1 << "\n";
		else if ((r1 - r2) * (r1 - r2) < sqdist && sqdist < (r1 + r2) * (r1 + r2))
			std::cout << 2 << "\n";
		else if ((r1 + r2) * (r1 + r2) == sqdist || (r1 - r2) * (r1 - r2) == sqdist)
			std::cout << 1 << "\n";
		else
			std::cout << 0 << "\n";
	}
	return 0;
}