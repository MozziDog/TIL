// 백준 21276번: 계보 복원가 호석
// 그래프 탐색을 시조부터 시작하니까 먼저 indegree가 0이 될 수록 위쪽 세대임.

// 로직 자체는 올바르고 깔끔하게 짠 것 같은데 index(int)와 string을 혼용해서 쓴 게 좀 걸린다
// 아예 index 기반으로 하기에는 출력이 사전순을 요구하고
// string으로 통일하는 방법은 array의 index로 쓸 수 없으니...
// 지금이 최선인가?
#include <bits/stdc++.h>
using namespace std;

int N, M;
map<string, int> name2idx;
map<int, string> idx2name;
vector<int> adj[1001];
int indegree[1001];
set<string> roots;
set<string> childs[1001];

inline int toInt(string name) { return name2idx[name]; }
inline string toName(int idx) { return idx2name[idx]; }

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	queue<int> q;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string name;
		cin >> name;
		name2idx.insert({ name, i });
		idx2name.insert({ i, name });
	}
	cin >> M;
	while (M--)
	{
		string X, Y;
		cin >> X >> Y;
		adj[toInt(Y)].push_back(toInt(X));
		indegree[toInt(X)]++;
	}
	// 시조 찾기
	for (int i = 0; i < N; i++)
	{
		if (indegree[i] == 0)
		{
			roots.insert(toName(i));
			q.push(i);
		}
	}
	// 그래프 간선 지워가며 탐색
	while (!q.empty())
	{
		int cur = q.front(); q.pop();
		for (int next : adj[cur])
		{
			indegree[next]--;
			if (indegree[next] == 0)
			{
				q.push(next);
				childs[cur].insert(toName(next));
			}
		}
	}
	// 시조 출력
	cout << roots.size() << '\n';
	for (string name : roots) { cout << name << ' '; }
	cout << '\n';
	// 이름 사전순으로 자식 출력
	for (pair<string, int> p : name2idx)
	{
		cout << p.first << ' ' << childs[p.second].size() << ' ';
		for (string child : childs[p.second]) { cout << child << ' '; }
		cout << '\n';
	}
	return 0;
}