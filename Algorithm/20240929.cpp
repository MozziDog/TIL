// 영어 끝말잇기
// programmers에서 코테 연습 3일차.
// 쉽네. set 사용 연습이라고 치자.

#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    set<string> already;
    
    for(int i=0; i<words.size(); i++)
    {
        // 조건 1: 끝말잇기에 실패
        if(i != 0)
        {
            if(words[i][0] != words[i-1][words[i-1].size()-1])
            {
                // 실패
                answer.push_back(i%n +1);
                answer.push_back(i/n + 1);
                return answer;
            }
        }
        // 조건 2: 이미 나왔던 단어 사용
        auto it = already.find(words[i]);
        if(it != already.end())
        {
            // 실패
            answer.push_back(i%n +1);
            answer.push_back(i/n + 1);
            return answer;
        }
        already.insert(words[i]);
    }
    
    answer.push_back(0);
    answer.push_back(0);
    return answer;
}