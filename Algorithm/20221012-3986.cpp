#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{
    int N;
    cin >> N;

    int answer = 0;
    while (N--)
    {
        string str;
        cin >> str;
        stack<char> s;
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == 'A')
            {
                if (!s.empty() && s.top() == 'A')
                {
                    s.pop();
                }
                else
                {
                    s.push('A');
                }
            }
            if (str[i] == 'B')
            {
                if (!s.empty() && s.top() == 'B')
                {
                    s.pop();
                }
                else
                {
                    s.push('B');
                }
            }
        }
        if (s.empty())
            answer++;
    }
    cout << answer;

    return 0;
}