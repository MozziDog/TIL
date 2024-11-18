// 이분탐색 문제집에 있어서 이분탐색으로 풀어봤는데 실패했고 정작 Set container 사용해서 풀었다.
// 나중에 다시 시도해봐야할 듯.

#include <bits/stdc++.h>
using namespace std;

int nA, nB;
set<int> A;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> nA >> nB;
    for (int i = 0; i < nA; i++)
    {
        int tmp;
        cin >> tmp;
        A.insert(tmp);
    }

    for (int i = 0; i < nB; i++)
    {
        int tmp;
        cin >> tmp;
        A.erase(tmp);
    }

    cout << A.size() << '\n';
    for (set<int>::iterator it = A.begin(); it != A.end(); it++)
    {
        cout << *it << ' ';
    }
}
