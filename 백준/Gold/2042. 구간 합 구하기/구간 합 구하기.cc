#include <bits/stdc++.h>
using namespace std;

#define llong long long

const int MAX = 1'000'002;

llong N, M, K, a, b, c;
llong num[MAX];
llong sum[MAX];
vector<pair<int, llong>> modify;

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++)
	{
		cin >> num[i];
	}
	sum[0] = 0;
	for (int i = 1; i <= N; i++)
	{
		sum[i] = num[i] + sum[i - 1];
	}
	for (int i = 0; i < M + K; i++)
	{
		cin >> a >> b >> c;
		// 숫자 바꾸기
		if (a == 1)
		{
			const pair<int, llong> newModify = { b, c };
			auto f = lower_bound(modify.begin(), modify.end(), newModify, [](pair<int, llong> a, pair<int, llong> b) { return a.first < b.first; });
			if (f != modify.end() && f->first == b)
				f->second = c;
			else
				modify.insert(f, newModify);
		}
		// 부분합 구하기
		else
		{
			llong tmp = sum[c] - sum[b - 1];
			const pair<int, llong> low = { b, LLONG_MIN }, 
						high = { c, LLONG_MAX };
			auto l = lower_bound(modify.begin(), modify.end(), low), 
				u = upper_bound(modify.begin(), modify.end(), high);
			for (auto it = l; it != u; it++)
			{
				tmp += it->second - num[it->first];
			}
			cout << tmp << '\n';
		}
	}
	return 0;
}