#include <bits/stdc++.h>
using namespace std;

int N;
int X[10'000];
int Y[10'000];

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cout.setf(ios_base::fixed);
	
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> X[i];
		cin >> Y[i];
	}
	
	double ans = 0;
	int x0 = X[0];
	int y0 = Y[0];
	for (int i = 1; i < N-1; i++)
	{
		double dx1 = X[i] - x0;
		double dy1 = Y[i] - y0;
		double dx2 = X[i + 1] - x0;
		double dy2 = Y[i + 1] - y0;

		double tri = dx1 * dy2 - dx2 * dy1;
		ans += tri / 2;
	}
	cout << setprecision(1) << abs(ans);
	return 0;
}
