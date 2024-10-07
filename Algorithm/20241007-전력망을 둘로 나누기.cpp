// programmers 코딩 테스트 연습
// 그래프쪽과 관련해서 약간의 복습이 필요하긴 했지만 그래도 제출 1트만에 클리어

#include <string>
#include <vector>

using namespace std;

vector<int> adjList[101];
int subTreeSize[101];
bool visited[101];

int countSubTree(int nodeId)
{
    visited[nodeId] = true;
    subTreeSize[nodeId] = 1;
    for(int i=0; i<adjList[nodeId].size(); i++)
    {
        if(!visited[adjList[nodeId][i]])
            subTreeSize[nodeId] += countSubTree(adjList[nodeId][i]);
    }
    return subTreeSize[nodeId];
}

int solution(int n, vector<vector<int>> wires) {
    // 그래프 형성
    for(int i=0; i<wires.size(); i++)
    {
        adjList[wires[i][0]].push_back(wires[i][1]);
        adjList[wires[i][1]].push_back(wires[i][0]);
    }
    
    // 각 노드를 루트로 삼는 서브트리 크기 계산
    countSubTree(1);
    
    // 가장 정답에 가까운 것을 탐색
    int answer = n;
    for(int i=1; i<=n; i++)
    {
        int t = abs(n - 2 * subTreeSize[i]);
        answer = min(t, answer);
    }
    return answer;
}