// Programmers 코테 준비 7일차.
// 대충 1시간 반에서 2시간 고민한 것 같은데 푸는데 개같이 실패!
// 나중에 다시 생각해봐야겠다. 반례가 생각 안나네
// https://school.programmers.co.kr/learn/courses/30/lessons/72413

#include <string>
#include <vector>
#include <climits>
#include <algorithm>
#include <iostream>

using namespace std;

#define inf 20000000
vector<bool> visited;   // 다익스트라 알고리즘에 사용
vector<int> costA, costB, costS;


int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    costA.resize(n+1, inf);
    costB.resize(n+1, inf);
    costS.resize(n+1, inf);
    visited.resize(n+1, false);
    
    // A와의 거리 구하기
    int curNode = a;
    costA[curNode] = 0;
    for(int i=0; i<n; i++)
    {
        int nextNode = -1;
        visited[curNode] = true;
        // 현재 노드와 연결된 모든 간선 확인
        for(int j=0; j<fares.size(); j++)
        {
            if(fares[j][0] == curNode || fares[j][1] == curNode)
            {
                int other = fares[j][0] == curNode ? fares[j][1] : fares[j][0];
                if(visited[other] == true)
                    continue;
                costA[other] = min(costA[other], costA[curNode] + fares[j][2]);
                // 다음 탐색할 노드 산정
                if(nextNode == -1 || costA[nextNode] > costA[other])
                    nextNode = other;
                    
            }
        }
        if(nextNode == -1)
            break;
        else
            curNode = nextNode;
    }
    
    fill(visited.begin(), visited.end(), false);
    
    // B와의 거리 구하기
    curNode = b;
    costB[curNode] = 0;
    for(int i=0; i<n; i++)
    {
        int nextNode = -1;
        visited[curNode] = true;
        // 현재 노드와 연결된 모든 간선 확인
        for(int j=0; j<fares.size(); j++)
        {
            if(fares[j][0] == curNode || fares[j][1] == curNode)
            {
                int other = fares[j][0] == curNode ? fares[j][1] : fares[j][0];
                if(visited[other] == true)
                    continue;
                costB[other] = min(costB[other], costB[curNode] + fares[j][2]);
                // 다음 탐색할 노드 산정
                if(nextNode == -1 || costB[nextNode] > costB[other])
                    nextNode = other;
            }
        }
        if(nextNode == -1)
            break;
        else
            curNode = nextNode;
    }
    
    fill(visited.begin(), visited.end(), false);
    
    // S와의 거리 구하기
    curNode = s;
    costS[curNode] = 0;
    for(int i=0; i<n; i++)
    {
        int nextNode = -1;
        visited[curNode] = true;
        // 현재 노드와 연결된 모든 간선 확인
        for(int j=0; j<fares.size(); j++)
        {
            if(fares[j][0] == curNode || fares[j][1] == curNode)
            {
                int other = fares[j][0] == curNode ? fares[j][1] : fares[j][0];
                if(visited[other] == true)
                    continue;
                costS[other] = min(costS[other], costS[curNode] + fares[j][2]);
                // 다음 탐색할 노드 산정
                if(nextNode == -1 || costS[nextNode] > costS[other])
                    nextNode = other;
            }
        }
        if(nextNode == -1)
            break;
        else
            curNode = nextNode;
    }
    
    // 마지막으로 최솟값 구하기
    int answer = inf;
    for(int i=1; i<=n; i++)
    {
        answer = min(answer, costA[i] + costB[i] + costS[i]);
    }
    return answer;
}