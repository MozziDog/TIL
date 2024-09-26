// 백준 18869번: 멀티버스 Ⅱ
// 정렬 전의 인덱스를 보관하고 있으면 정렬을 초기의 1번만 수행해도 된다.

#include "bits/stdc++.h"
using namespace std;

int M, N;
vector<vector<pair<int, int>>> space;

#define idx second

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> M >> N;
	for (int i = 0; i < M; i++)
	{
		vector<pair<int, int>> s;
		for (int i = 0; i < N; i++)
		{
			int v;
			cin >> v;
			s.push_back({v, i});
		}
		sort(s.begin(), s.end(), [](pair<int, int> e1, pair<int, int> e2)->bool {return e1.first < e2.first; });
		space.push_back(s);
	}

	int answer = 0;
	for (int s1 = 0; s1 < M; s1++)
	{
		for (int s2 = s1 + 1; s2 < M; s2++)
		{
			bool isEven = true;
			// 각 우주 순서쌍에 대해서 평가 수행
			for (int i = 0; i < N; i++)
			{
				if (space[s1][i].idx != space[s2][i].idx)
				{
					isEven = false;
					break;
				}
				else
				{
					// 둘 다 동일한 값을 가졌던가 아니면 둘 다 증가하던가인지 판단
					if (i > 0)
					{
						int a = space[s1][i - 1].first - space[s1][i].first;
						int b = space[s2][i - 1].first - space[s2][i].first;
						if ((a == 0 && b != 0) || (a != 0 && b == 0))
						{
							isEven = false;
							break;
						}
					}
				}
			}
			answer += isEven? 1 : 0;
		}
	}
	cout << answer;	

	return 0;
}