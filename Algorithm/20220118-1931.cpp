// https://www.acmicpc.net/problem/1931
// 1차 시간 초과
// 2차 최적화하니 통과 앙 기모띠

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

vector<pair<unsigned int, unsigned int>> meetings;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		pair<unsigned int, unsigned int> meeting;
		cin >> meeting.first >> meeting.second;
		meetings.push_back(meeting);
	}
	
	sort(meetings.begin(), meetings.end());

	int MaxOfMeetings = 0;
	unsigned int lastMeetingEndTime = 0;
	int index = -1; // 시간 단축을 위해 기존에 확인했던 회의 일정은 더이상 확인하지 않음
	while (true)
	{
		unsigned int tmp = UINT_MAX;
		for (int i = index+1; i < meetings.size(); i++)
		{
			if (meetings[i].first >= lastMeetingEndTime && meetings[i].second < tmp)
			{
				tmp = meetings[i].second;
				index = i;
			}
			if (meetings[i].first >= tmp) // 시간 단축을 위해 시작 시간이 다른 회의의 종료시간보다 늦을 경우 for문 종료
			{
				break;
			}
		}
		if (tmp == UINT_MAX)
		{
			break;
		}
		else
		{
			MaxOfMeetings++;
			lastMeetingEndTime = tmp;
		}
	}

	cout << MaxOfMeetings;

	return 0;
}