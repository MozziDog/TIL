#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> num, ans;
bool used[10];

void solve(int len)
{
	if (len == M)
	{
		for (int i = 0; i < M; i++)
			cout << ans[i] << ' ';
		cout << '\n';
		return;
	}

	int before = -1;
	for (int i = 0; i < N; i++)
	{
		if (num[i] == before) continue;
		if (used[i]) continue;
		used[i] = true;
		ans[len] = num[i];
		before = num[i];
		solve(len+1);
		used[i] = false;
	}
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> N >> M;
	num.resize(N); 	ans.resize(N);
	for (int i = 0; i < N; i++)
		cin >> num[i];

	sort(num.begin(), num.end());
	solve(0);

	return 0;
}