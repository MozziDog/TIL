// Programmers 하노이의 탑
// 깔끔하게 원트 성공

#include <string>
#include <vector>

using namespace std;

vector<vector<int>> rec(int n, int from, int to)
{
    vector<vector<int>> answer;
    int mid = 6/from/to;
    if(n == 1)
    {
        answer.push_back({from, to});
        return answer;
    }
    answer = rec(n-1, from, mid);
    answer.push_back({from, to});
    vector<vector<int>> left = rec(n-1, mid, to);
    answer.insert(answer.end(), left.begin(), left.end());
    return answer;
}

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer;
    return rec(n, 1, 3);
}