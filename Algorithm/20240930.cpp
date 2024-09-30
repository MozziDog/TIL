// programmers 코테 연습 4일차.
// 점화식은 깔끔하게 구했다만 mod로 나누는 과정에서 문제가 있었다.
// dp[i-1] * 4 - dp[i-2]가 순간적으로 int 범위를 벗어날 수도 있고, 음수가 될 수도 있었다.
// 항상 자료형 범위에 주의!

#include <string>
#include <vector>

using namespace std;

const int mod = 1000000007;
vector<long long> dp;

int solution(int n) {
    if(n%2 != 0)
        return 0;
    
    int step = n/2;
    
    dp.push_back(0);
    dp.push_back(3);
    dp.push_back(11);
    for(int i=3; i<=step; i++)
    {
        long long a = (dp[i-1] * 4 - dp[i-2]) % mod;
        if(a < 0) a += mod;
        dp.push_back(a);
    }
    
    return dp[step];
}