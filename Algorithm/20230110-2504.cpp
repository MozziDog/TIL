// 백준 2504번 : 괄호의 값
#include <iostream>
#include <stack>

using namespace std;

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    stack<char> stk;
    int arrCalc[20] = {0,};
    int answer = 0;
    int tmp;

    cin >> str;
    for (int i = 0; i < str.length(); i++)
    {
        switch (str[i])
        {
        case '(':
            arrCalc[stk.size()] = 2;
            stk.push('(');
            break;
        case '[':
            arrCalc[stk.size()] = 3;
            stk.push('[');
            break;
        case ')':
            if (stk.empty() || stk.top() != '(')
            {
                cout << 0;
                return 0;
            }
            if (str[i - 1] == '(')
            {
                tmp = 1;
                for (int i = 0; i < stk.size(); i++)
                {
                    tmp *= arrCalc[i];
                }
                answer += tmp;
            }
            stk.pop();
            break;
        case ']':
            if (stk.empty() || stk.top() != '[')
            {
                cout << 0;
                return 0;
            }
            if (str[i - 1] == '[')
            {
                tmp = 1;
                for (int i = 0; i < stk.size(); i++)
                {
                    tmp *= arrCalc[i];
                }
                answer += tmp;
            }
            stk.pop();
        }
    }
    if (stk.size() != 0)    // 스택을 사용하여 괄호 짝맞추기를 할 때에는 마지막에 스택에 남은 것이 없는지 반드시 확인
        answer = 0;
    cout << answer;
    return 0;
}