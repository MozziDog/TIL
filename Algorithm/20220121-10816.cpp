// https://www.acmicpc.net/problem/10816

#include <iostream>
#include <vector>
#include <algorithm>
// 정렬된 배열에서 lower_bound 와 upper_bound를 사용해 지정된 범위 내의 원소 갯수 세기

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m;
	vector<int> cards;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		cards.push_back(tmp);
	}
	sort(cards.begin(), cards.end());

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int toFind;
		cin >> toFind;
		vector<int>::iterator low = lower_bound(cards.begin(), cards.end(), toFind);
		vector<int>::iterator high = upper_bound(cards.begin(), cards.end(), toFind);
		cout << high - low << " ";
	}

	return 0;
}