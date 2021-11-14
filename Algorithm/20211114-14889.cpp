// https://www.acmicpc.net/problem/14889
// 뭐지? 왜 한번만에 되는 것이지?

#include <iostream>
#include <vector>
using namespace std;

static int INF = 100000000;

int N;
int S[20][20];
int answer = INF;
bool isTeamA[20]{};

void DFS(int numOfTeamA, int next)
{
	if (numOfTeamA == N / 2)
	{
		int teamA=0, teamB=0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (isTeamA[i] == isTeamA[j])
				{
					if (isTeamA[i] == true)
						teamA += S[i][j];
					else
						teamB += S[i][j];
				}
			}
		}
		
		int sub = abs(teamA - teamB);
		if (sub < answer)
		{
			answer = sub;
		}
		return;
	}
	else
	{
		for (int i = next; i < N/2 + numOfTeamA; i++)
		{
			isTeamA[i] = true;
			DFS(numOfTeamA + 1, i + 1);
			isTeamA[i] = false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> S[i][j];
		}
	}

	DFS(0, 0);

	cout << answer;
	return 0;
}