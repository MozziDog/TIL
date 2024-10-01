// programmers 코딩 테스트 연습 5일차.
// 아주 깔끔하게 푼 것 같다. 만족.

#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    if(s < n)
    {
        answer.push_back(-1);
        return answer;
    }
    
    for(; n>0; n--)
    {
        answer.push_back(s/n);
        s -= s/n;
    }
    return answer;
}