// 시간 복잡도가 N*M이 나와서 이게 맞나 싶었는데
// 맞네
// 더 빠르게 푸는 방법이 있을 것 같은디
#include <iostream>
#include <deque>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    deque<int> dq;
    for (int i = 1; i <= N; i++)
    {
        dq.push_back(i);
    }
    int answer = 0;

    while (M--)
    {
        int num, count = 0;
        cin >> num;
        while (true)
        {
            if (dq.front() == num)
            {
                answer += (count > dq.size() - count) ? dq.size() - count : count;
                dq.pop_front();
                break;
            }
            dq.push_back(dq.front());
            dq.pop_front();
            count++;
        }
    }

    cout << answer;
    return 0;
}