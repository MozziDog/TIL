// 백준 1240번: 노드 사이의 거리
// N이 작아서 그냥 매번 bfs로 거리를 구해버리면 되는 문제였다.
// N이 좀 컸다면 Kruskal 알고리즘이 필요했으려나?

#include <bits/stdc++.h>
using namespace std;

#define node first
#define weight second

int N, M;
int A, B, W;
vector<pair<int,int>> adj[1001];    // 앞에가 노드, 뒤가 가중치
bool visited[1001];

void bfs(int start, int end)
{
    queue<pair<int, int>> q;        // 앞에가 노드, 뒤가 경로의 가중치합합
    int length = 0;
    fill(visited, visited + 1001, false);
    q.push({start, 0});
    visited[start] = true;
    while(!q.empty())
    {
        int curNode = q.front().node, curWeightSum = q.front().weight;
        q.pop();
        for(auto con : adj[curNode])
        {
            if(visited[con.node]) continue;
            if(con.node == end)
            {
                cout << curWeightSum + con.weight << '\n';
                return;
            }
            q.push({con.node, curWeightSum + con.weight});
            visited[con.node] = true;
        }
    }
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> N >> M;
    for(int i=0; i<N-1; i++)
    {
        cin >> A >> B >> W;
        adj[A].push_back({B, W});
        adj[B].push_back({A, W});
    }

    for(int i=0; i<M; i++)
    {
        cin >> A >> B;
        bfs(A, B);
    }
    return 0;
}