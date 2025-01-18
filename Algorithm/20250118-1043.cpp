// 백준 1043번: 거짓말
// 서로 다른 2종류의 노드들이 혼합된 형태의 그래프를 가지고 푸는 문제였다.
// 1트만에 성공해서 기모찌하긴 한데 더 코드를 간결하게 쓰는 방법이 있을 것 같은데...
// 짖는개의 해답을 보면 파티를 아예 노드로 취급하지 않고, 파티안에 인물들을 앞뒤로만 연결시키면
// 자연스럽게 bfs를 돌렸을 때 진실을 아는/전파당한 사람들을 구할 수 있게 되는 식으로 풀었네
// 그래프가 꼭 문제에서 주어진 상황을 충실하게 반영할 필요는 없겠구나

#include <bits/stdc++.h>
using namespace std;

int N, M, C, t, ans;
vector<int> personOfParty[51], partyOfPerson[51];
vector<int> origin;
bool partyKnowsTruth[51];	// visited

void bfs(int start)
{
	queue<int> q;
	bool visited[51];
	fill(visited, visited + 51, false);
	q.push(start);
	visited[start] = true;
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		for (int party : partyOfPerson[cur])
		{
			if (partyKnowsTruth[party]) continue;
			partyKnowsTruth[party] = true;
			for (int person : personOfParty[party])
			{
				if (visited[person]) continue;
				q.push(person);
				visited[person] = true;
			}
		}
	}
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> N >> M;
	cin >> C;
	while (C--)
	{
		cin >> t;
		origin.push_back(t);
	}
	for (int i = 1; i <= M; i++)
	{
		cin >> C;
		while (C--)
		{
			cin >> t;
			personOfParty[i].push_back(t);
			partyOfPerson[t].push_back(i);
		}
	}

	for (int p : origin)
	{
		bfs(p);
	}

	for (int i = 1; i <= M; i++)
	{
		if (!partyKnowsTruth[i]) ans++;
	}
	cout << ans;
	return 0;
}