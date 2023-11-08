// 백준 1931번: 회의실 배정
// 팁: 오름차순 정렬이라면 pair의 first와 second를 바꿔서 굳이 compare 함수를 제공하지 않아도 되도록 할 수 있다.
#include <bits/stdc++.h>
using namespace std;

bool compare(const pair<int, int>& a, const pair<int, int>& b)	// second 기준 오름차순 정렬, second가 동일하다면 first 기준 오름차순.
{
	if (a.second == b.second)
		return a.first <= b.first;
	return a.second <= b.second;
}

int main()
{
	int N;
	int lastMeetingEndT = 0;
	int answer = 0;
	vector<pair<int, int>> meetings;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int startT, endT;
		cin >> startT >> endT;
		meetings.push_back({ startT, endT });
	}
	sort(meetings.begin(), meetings.end(), compare);
	auto meeting = meetings.begin();
	do
	{
		if (meeting->first >= lastMeetingEndT)
		{
			answer++;
			lastMeetingEndT = meeting->second;
		}
	} while (++meeting != meetings.end());
	cout << answer;
}

