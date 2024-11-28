// 백준 7453번
// 합이 0인 네 정수
// 아 answer 자료형 int로 해서 틀렸네
// 자료형 문제인가 생각은 하긴 했는데 a,b,c,d만 하고 answer는 생각을 못했다.

#include <bits/stdc++.h>
using namespace std;

int n = 0;
int a[4000], b[4000], c[4000], d[4000];
vector<int> apb, cpd;
long long answer = 0;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	}
	apb.reserve(n * n);
	cpd.reserve(n * n);
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			apb.push_back(a[i] + b[j]);
			cpd.push_back(c[i] + d[j]);
		}
	}
	sort(cpd.begin(), cpd.end());

	for (int i = 0; i < apb.size(); i++)
	{
		int toFind = -apb[i];
		int bot = 0, top = cpd.size()-1;
		int lowerBound = -1, upperBound;
		while (top >= bot)
		{
			int mid = (top + bot) / 2;
			if (cpd[mid] >= toFind)
				top = mid - 1;
			else if (cpd[mid] < toFind)
				bot = mid + 1;
		}
		if (cpd[bot] != toFind) continue;
		lowerBound = bot;
		top = cpd.size() - 1;
		while (top >= bot)
		{
			int mid = (top + bot) / 2;
			if (cpd[mid] > toFind)
				top = mid - 1;
			else if (cpd[mid] <= toFind)
				bot = mid + 1;
		}
		upperBound = top;
		answer += (upperBound - lowerBound + 1);
	}
	cout << answer;

	return 0;
}