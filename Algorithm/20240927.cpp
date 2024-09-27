// programmers 사이트에서 코딩 테스트 어떤식으로 진행되는지 연습
// 함수 이름이나 파라미터 생각 안나면 큰일나네...

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int apples[10];

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    
    sort(score.begin(), score.end());
    while(score.size() >= m)
    {
        answer += *(score.end() - m) * m;
        score.erase(score.end() - m, score.end());
    }
    
    return answer;
}