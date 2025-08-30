// 로직은 맞았는데 ans의 자료형이 double이 아니라 float여서 틀렸다.
// 아무래도 정밀도가 낮아서 오차 누적 때문에 답이 0.01 단위로 차이가 났던 듯
// 왠만하면 앞으로 실수형을 다룰 땐 널널하게 double을 쓰는 것이 좋을 듯함.
// 아니 찾아보니 float의 유효자리 숫자가 6~9자리라고 하네
// 그럼 당연히 틀리는 게 정상이겠구나

#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> p(1005, -1);

int find(int a)
{
	if (p[a] < 0) return a;
	return p[a] = find(p[a]);
}

bool uni(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a == b) return false;

	if (p[a] > p[b]) swap(a, b);
	if (p[a] == p[b])
		p[a]--;
	p[b] = a;
	return true;
}

int N, M;
pair<int, int> pos[1005];
double ans = 0;
priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<>> pq;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	// 입력
	cin >> N >> M;
	for (int i = 1; i < N+1; i++)
	{
		cin >> pos[i].first >> pos[i].second;
	}
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		uni(a, b);
	}
	// 거리 계산
	for (int i = 1; i < N + 1; i++)
	{
		for (int j = i+1; j < N + 1; j++)
		{
			ll deltaX = pos[i].first - pos[j].first,
				deltaY = pos[i].second - pos[j].second;
			ll len = deltaX * deltaX + deltaY * deltaY;
			pq.push({ len, i, j});
		}
	}
	// mst 계산
	while (!pq.empty())
	{
		ll d; int a, b;
		tie(d, a, b) = pq.top(); pq.pop();
		if (!uni(a,b)) continue;
		ans += sqrt(d);
	}

	cout << fixed << setprecision(2) << ans;

	return 0;
}