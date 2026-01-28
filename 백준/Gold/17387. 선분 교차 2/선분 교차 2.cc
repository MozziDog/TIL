#define X first
#define Y second

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> vec;

inline int cross(vec v1, vec v2)
{
	long long val = (long long)v1.X * v2.Y - (long long)v2.X * v1.Y;
	// 1,000,000 ^ 4면 llong보다 크므로 계산 불가. 부호 정보만 남김
	return val > 0 ? 1 : val == 0 ? 0 : -1;
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	int x[4], y[4];
	for (int i = 0; i < 4; i++)
	{
		cin >> x[i] >> y[i];
	}
	vec v01 = { x[1] - x[0], y[1] - y[0] };
	vec v02 = { x[2] - x[0], y[2] - y[0] };
	vec v03 = { x[3] - x[0], y[3] - y[0] };

	vec v23 = { x[3] - x[2], y[3] - y[2] };
	vec v20 = { x[0] - x[2], y[0] - y[2] };
	vec v21 = { x[1] - x[2], y[1] - y[2] };

	int c012 = cross(v01, v02);
	int c013 = cross(v01, v03);
	int c230 = cross(v23, v20);
	int c231 = cross(v23, v21);

	// 네 점이 일직선상에 놓인 경우
	if (c012 == 0 && c013 == 0)
	{
		bool xInter = min(x[0], x[1]) <= x[2] && x[2] <= max(x[0], x[1])
			|| min(x[0], x[1]) <= x[3] && x[3] <= max(x[0], x[1])
			|| min(x[2], x[3]) <= x[0] && x[0] <= max(x[2], x[3]);
		bool yInter = min(y[0], y[1]) <= y[2] && y[2] <= max(y[0], y[1])
			|| min(y[0], y[1]) <= y[3] && y[3] <= max(y[0], y[1])
			|| min(y[2], y[3]) <= y[0] && y[0] <= max(y[2], y[3]);

		cout << (xInter && yInter);
	}
	else
		cout << (c012 * c013 <= 0 && c230 * c231 <= 0);
	return 0;
}