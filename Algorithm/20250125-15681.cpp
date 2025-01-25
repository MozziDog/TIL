// 백준 15681번: 트리와 쿼리
// 미리 서브트리의 자식 갯수를 구해놓고 입력이 들어오면 답을 읽어서 출력만 해주면 되는 간단한 문제
// 근데 다른 사람이랑 로직은 같게 푼 것 같은데 왜 수행시간에 20ms 정도 차이가 날까
// 재귀함수 호출에 parent를 주는 방식 말고 bool visited[]를 쓰면 더 빠르나?
// 아니 너무 사소한 것에 신경쓰나?

#include <bits/stdc++.h>
using namespace std;

int N, R, Q, U, V;
vector<int> adj[100001];
int totalChildCount[100001];

int BuildTree(int curNode, int parent)
{
    for(int next : adj[curNode])
    {
        if(next == parent) continue;
        totalChildCount[curNode] += BuildTree(next, curNode);
    }
    totalChildCount[curNode] ++;
    return totalChildCount[curNode];
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> N >> R >> Q;
    for (int i = 0; i < N-1; i++)
    {
        cin >> U >> V;
        adj[U].push_back(V);
        adj[V].push_back(U);
    }
    BuildTree(R, 0);
    for (int i = 0; i < Q; i++)
    {
        cin >> U;
        cout << totalChildCount[U] << '\n';
    }

    return 0;
}