// Programmers 코딩 테스트 연습 2일차
// 숫자 짝꿍
// 오늘의 교훈: stoi는 string의 범위가 int 범위 내인지 파악하고 할 것.
// 그게 아니라면 숫자로 파싱해서 처리하는 것보다는 string인 채로 처리하는 게 낫다.

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool dec(char a, char b){
    return a > b;
}

string solution(string X, string Y) {
    string answer = "";
    // 내림차순 정렬
    sort(X.begin(), X.end(), dec);
    sort(Y.begin(), Y.end(), dec);
    
    auto Xit = X.begin(), Yit = Y.begin();
    while(Xit < X.end() && Yit < Y.end())
    {
        if(*Xit == *Yit)
        {
            answer.push_back(*Xit);
            Xit++; Yit++;
        }
        else
        {
            if(*Xit < *Yit)
            {
                Yit++;
            }
            else
            {
                Xit++;
            }
        }
    }
    
    if(answer.size() == 0)
        answer = "-1";
    else if(answer[0] == '0')
        answer = "0";
    
    return answer;
}