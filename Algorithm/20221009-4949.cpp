// 수식의 괄호쌍 맞출 때 stack에 남아있는 거 있는지 체크하기!!

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (true)
    {
        string s;
        getline(cin, s);
        if (s == ".")
            return 0;
        stack<char> stk;
        bool isValid = true;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '[')
            {
                stk.push('[');
            }
            if (s[i] == '(')
            {
                stk.push('(');
            }
            if (s[i] == ']')
            {
                if (!stk.empty() && stk.top() == '[')
                    stk.pop();
                else
                {
                    isValid = false;
                    break;
                }
            }
            if (s[i] == ')')
            {
                if (!stk.empty() && stk.top() == '(')
                    stk.pop();
                else
                {
                    isValid = false;
                    break;
                }
            }
        }
        if (stk.size() > 0)
            isValid = false;
        cout << (isValid ? "yes\n" : "no\n");
    }
    return 0;
}