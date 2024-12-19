// 백준 1351번: 무한 수열
// 바텀업으로 하면 딱 봐도 시간 초과 날 것 같으니 탑다운으로, 근데 재귀함수를 사용하는 대신 해시 컨테이너를 사용하여 최적화하는 문제였다.
// 항상 그렇지만 자료형 최대/최솟값에 주의! 

#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	long long n, p, q;
	unordered_map<long long, long long> count;

	cin >> n >> p >> q;
	
	count[n] = 1;
	for(; n > 0; n /= min(p, q))
	{
		unordered_map<long long, long long> t;
		for (auto i : count)
		{
			if (i.first == 0) 
				t[0] += i.second;
			else
			{
				t[i.first / p] += i.second;
				t[i.first / q] += i.second;
			}
		}
		count.swap(t);
	}
	cout << count[0];
	return 0;
}