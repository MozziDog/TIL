// 양식에 맞춰 입출력해야되서 쓸데없이 틀림 ㅜㅜ
// C++가 아니라 python으로 했으면 편했을지도?

#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--)
    {
        string cmd;
        cin >> cmd;
        int n;
        cin >> n;

        deque<int> dq;
        char buf;
        int num;

        cin >> buf; // [
        for (int i = 0; i < n; i++)
        {
            cin >> num;
            dq.push_back(num);
            if (i != n - 1)
                cin >> buf; // ,
        }
        cin >> buf; // ]

        bool reverse = false, valid = true;
        for (int i = 0; i < cmd.size(); i++)
        {
            if (cmd[i] == 'R')
                reverse = !reverse;
            if (cmd[i] == 'D')
            {
                if (!dq.empty())
                {
                    if (reverse)
                        dq.pop_back();
                    else
                        dq.pop_front();
                }
                else
                {
                    valid = false;
                    break;
                }
            }
        }

        if (valid)
        {
            cout << '[';
            if (reverse)
            {
                for (int i = dq.size() - 1; i >= 0; i--)
                {
                    cout << dq[i];
                    if (i > 0)
                        cout << ',';
                }
            }
            else
            {
                for (int i = 0; i < dq.size(); i++)
                {
                    cout << dq[i];
                    if (i < dq.size() - 1)
                        cout << ',';
                }
            }
            cout << "]\n";
        }
        else
            cout << "error\n";
    }

    return 0;
}