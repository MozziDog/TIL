#include <bits/stdc++.h>
using namespace std;

#define left first
#define right second

int n, d, ans;
vector<pair<int, int>> pos;
vector<int> leftPoints;

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		if (a > b) swap(a, b);
		pos.push_back({ a, b });
		leftPoints.push_back(a);
	}
	cin >> d;
	sort(pos.begin(), pos.end(), [](pair<int, int> a, pair<int,int> b) {
		return a.right < b.right;
		});
	sort(leftPoints.begin(), leftPoints.end());

	priority_queue<pair<int, int>, vector<pair<int,int>>, greater<void>> que;
	auto it = pos.begin();
	for (int i = 0; i < leftPoints.size(); i++)
	{

		int leftEnd = leftPoints[i], rightEnd = leftEnd + d;
		while (it != pos.end() && it->right <= rightEnd)
		{
			que.push(*it);
			it++;
		}
		while (!que.empty() && que.top().left < leftEnd) {
			que.pop();
		}
		ans = max(ans, (int)que.size());
	}
	cout << ans;
	return 0;
}