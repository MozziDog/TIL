// 백준 18870번: 좌표 압축
// 중복 제거(=압축)은 원본에서 중복을 제거 (= O(N))보다
// 정렬된 배열을 순회하면서 새로운 값이 나올 때마다 새로운 배열에 추가하는 게 나을 수 있다. (= O(M), M은 서로 다른 원소의 갯수)

// C++에서 기본적으로 제공하는 upper_bound(), lowewr_bound()를 사용하면 이분탐색을 더 간단히 작성할 수 있다.
// 성능은 손으로 구현하는 거랑 똑같은 듯?
#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int N;
	vector<long long> X;
	vector<long long> uniq;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;
		X.push_back(input);
	}

	vector<long long> sorted(X);
	sort(sorted.begin(), sorted.end());

	// 압축
	for(int i=0; i<N; i++)
	{
		if (i== 0 || sorted[i] != sorted[i-1])
		{
			uniq.push_back(sorted[i]);
		}
	}

	// 검색
	for (int i = 0; i < N; i++)
	{
		cout << lower_bound(uniq.begin(), uniq.end(), X[i]) - uniq.begin() << ' ';
	}

	return 0;
}