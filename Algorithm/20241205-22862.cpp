// 백준 22862번: 가장 긴 짝수 연속한 부분 수열 (large)
// 코드 최적화에는 gpt의 도움을 받기는 했지만 핵심 로직은 직접 구상한 코드.
// 슬슬 투포인터에 대한 감을 잡아가는 것 같기도?
// vector.erase 때문에 시간초과 한 번 났으니 이 부분은 조심해야겠다.
// vector.erase()가 O(n)이니까 for문 안에서 쓰면 바로 O(n^2)로 시간 초과하기 십상
#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, k, removeCount = 0, answer =0, curLength = 0;

    cin >> n >> k;
    vector<int> s(n);
    for(int i=0; i<n; i++)
    {
        cin >> s[i];
    }

    int bot = 0, top = 0;
    for(; top < n; top++)
    {
        if(s[top]%2 != 0)
            removeCount++;
        else
            curLength++;
        
        while(removeCount > k)
        {
            if(s[bot]%2 != 0)
                removeCount--;
            else
                curLength--;
            bot++;
        }
        answer = max(answer, curLength);
    }
    cout << answer;    
    return 0;
}