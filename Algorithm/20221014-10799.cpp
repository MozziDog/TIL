// 괄호 문제라서 스택 써야 하는 줄 알았는데 그냥 int 써도 됨 ㅋㅋ

#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int stk = 0, answer = 0;
    bool isLastPushed = false;

    string in;
    cin >> in;
    for (int i = 0; i < in.size(); i++)
    {
        if (in[i] == '(')
        {
            stk++;
            isLastPushed = true;
        }
        else
        {
            if (stk == 0)
                return -1;
            stk--;
            if (isLastPushed) // laser
                answer += stk;
            else // end of stick
                answer++;
            isLastPushed = false;
        }
    }
    cout << answer;
    return 0;
}