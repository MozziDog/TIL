#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    deque<int> dq;

    while (N--)
    {
        string cmd;
        cin >> cmd;
        if (cmd == "push_back")
        {
            int el;
            cin >> el;
            dq.push_back(el);
        }
        else if (cmd == "push_front")
        {
            int el;
            cin >> el;
            dq.push_front(el);
        }
        else if (cmd == "pop_front")
        {
            if (dq.empty())
                cout << -1 << "\n";
            else
            {
                cout << dq.front() << "\n";
                dq.pop_front();
            }
        }
        else if (cmd == "pop_back")
        {
            if (dq.empty())
                cout << -1 << "\n";
            else
            {
                cout << dq.back() << "\n";
                dq.pop_back();
            }
        }
        else if (cmd == "size")
        {
            cout << dq.size() << "\n";
        }
        else if (cmd == "empty")
        {
            cout << (dq.empty() ? 1 : 0) << "\n";
        }
        else if (cmd == "front")
        {
            if (dq.empty())
                cout << -1 << "\n";
            else
            {
                cout << dq.front() << "\n";
            }
        }
        else if (cmd == "back")
        {
            if (dq.empty())
                cout << -1 << "\n";
            else
            {
                cout << dq.back() << "\n";
            }
        }
    }
}