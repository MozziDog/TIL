#include <bits/stdc++.h>
using namespace std;

const long long INF = 1000000 * 2 + 1;
int N, R, M, K;
vector<int> dest;

map<string, int> cityToInt;
map<string, float> nailroCoef;

double costY[101][101], costN[101][101];

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	string city1, city2, tp;
	nailroCoef.insert({ {"Subway", 1}, {"Bus", 1}, {"Taxi", 1}, {"Airplane", 1}, {"KTX", 1}, 
					{"S-Train", 0.5f}, {"V-Train", 0.5f}, 
					{"ITX-Saemaeul", 0}, {"ITX-Cheongchun", 0},{"Mugunghwa", 0} });
	fill(&costY[0][0], &costY[100][100], INF);
	fill(&costN[0][0], &costN[100][100], INF);

	cin >> N >> R;
	for (int i = 0; i < N; i++)
	{
		cin >> city1;
		cityToInt.insert({ city1, i });
	}
	for (int i = 0; i < N; i++)
	{
		costY[i][i] = 0;
		costN[i][i] = 0;
	}

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> city1;
		dest.push_back(cityToInt[city1]);
	}
	cin >> K;
	for (int i = 0; i < K; i++)
	{
		int c1, c2;
		double cost;
		cin >> tp >> city1 >> city2 >> cost;
		c1 = cityToInt[city1]; c2 = cityToInt[city2];
		costN[c1][c2] = costN[c2][c1] = min(costN[c1][c2], cost);
		costY[c1][c2] = costY[c2][c1] = min(costY[c1][c2], cost * nailroCoef[tp]);
	}

	for(int i = 0; i<N; i++)
		for (int m = 0; m < N; m++)
			for(int s = 0; s < N; s++)
				for (int d = 0; d < N; d++)
				{
					costY[s][d] = min(costY[s][d], costY[s][m] + costY[m][d]);
					costN[s][d] = min(costN[s][d], costN[s][m] + costN[m][d]);
				}
	
	double sumY = R, sumN = 0;
	for (int i = 0; i < M - 1; i++)
	{
		sumY += costY[dest[i]][dest[i + 1]];
		sumN += costN[dest[i]][dest[i + 1]];
	}

	cout << ((sumY < sumN) ? "Yes" : "No");
	return 0;
}