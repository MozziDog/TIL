// 1. 디버깅용으로 넣어둔 출력을 안지우고 제출했다. 바보 자식
// 2. 인접 리스트를 사용하지 않아, 특정 노드와 연결된 다른 노드를 탐색하기 위해 fares를
// 처음부터 끝까지 탐색하는 문제가 있었다.
// 결국은 그래프 쪽 연습이 안되어서 그랬던 것으로...

#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define inf 20000000
vector<pair<int, int>> connection[201];
vector<int> cost;

void Dijkstra(int startNode)
{
    // 다익스트라 알고리즘에 사용할 priority queue
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;      
    // first가 node, second가 cost
    fill(cost.begin(), cost.end(), inf);
    cost[startNode] = 0;
    pq.push({0, startNode});
    while(!pq.empty())
    {
        int curNode = pq.top().second;
        int curCost = cost[curNode];
        pq.pop();
        // 현재 노드와 연결된 모든 간선 확인
        for(int i=0; i<connection[curNode].size(); i++)
        {
            int otherNode = connection[curNode][i].first;
            int newCost = curCost + connection[curNode][i].second;
            if(newCost < cost[otherNode])
            {
                cost[otherNode] = newCost;
                pq.push({cost[otherNode], otherNode});
            }
        }
    }
}


int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    vector<int> costA, costB, costS;
    cost.resize(n+1, inf);
    for(int i=0; i<fares.size(); i++)
    {
        connection[fares[i][0]].push_back({fares[i][1], fares[i][2]});
        connection[fares[i][1]].push_back({fares[i][0], fares[i][2]});
    }
    
    // A와의 거리 구하기
    Dijkstra(a);
    costA = cost;
    
    // B와의 거리 구하기
    Dijkstra(b);
    costB = cost;
    
    // S와의 거리 구하기
    Dijkstra(s);
    costS = cost;
    
    // 마지막으로 최솟값 구하기
    int answer = inf;
    for(int i=1; i<=n; i++)
    {
        answer = min(answer, costA[i] + costB[i] + costS[i]);
    }
    return answer;
}