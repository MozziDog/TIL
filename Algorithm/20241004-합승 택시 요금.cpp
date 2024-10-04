// 어제 못 푼거 다시 시도
// 어제 틀렸던 건 다익스트라 구현 자체가 틀려서 그랬던 거였슴;;
// 그래프 다루는 거 연습 좀 해야되겠다.
// 오늘 제출한 코드는 정답은 맞는데 효율성 체크에서 시간 초과난다고 한다.
// 다른 사람이 올려놓은 정답 코드랑 시간복잡도가 차이나지는 않을텐데 왜그럴까
// 어디서 실수가 있었던 건지 몰루겟슴.

#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

#define inf 20000000
vector<vector<int>> edgeData;
vector<int> cost;

void Dijkstra(int startNode)
{
    // 다익스트라 알고리즘에 사용할 priority queue
    auto cmp = [](pair<int, int> a, pair<int, int>b){ return a.second < b.second; };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);      
    // first가 node, second가 cost
    fill(cost.begin(), cost.end(), inf);
    cost[startNode] = 0;
    pq.push({startNode,0});
    while(!pq.empty())
    {
        int curNode = pq.top().first;
        pq.pop();
        // 현재 노드와 연결된 모든 간선 확인
        for(int j=0; j<edgeData.size(); j++)
        {
            if(edgeData[j][0] == curNode || edgeData[j][1] == curNode)
            {
                int other = edgeData[j][0] == curNode ? edgeData[j][1] : edgeData[j][0];
                int newCost = cost[curNode] + edgeData[j][2];
                if(newCost < cost[other])
                {
                    cost[other] = newCost;
                    pq.push({other, cost[other]});
                }
            }
        }
    }
}


int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    vector<int> costA, costB, costS;
    edgeData = fares;
    cost.resize(n+1, inf);
    
    // A와의 거리 구하기
    Dijkstra(a);
    costA = cost;
    
    // B와의 거리 구하기
    Dijkstra(b);
    costB = cost;
    
    // S와의 거리 구하기
    Dijkstra(s);
    costS = cost;
    
    // 디버그
    for(int i=1; i<=n; i++)
    {
        cout << "costA[" << i << "]: " << costA[i] << "\n";
    }
    
    // 마지막으로 최솟값 구하기
    int answer = inf;
    for(int i=1; i<=n; i++)
    {
        answer = min(answer, costA[i] + costB[i] + costS[i]);
    }
    return answer;
}