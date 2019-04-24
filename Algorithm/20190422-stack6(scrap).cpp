//코드 출처: https://suriisurii.tistory.com/53


//눈여겨볼만한 점
//
//1. ()와 []를 관리하는 변수(k, l)가 하나씩 존재함
//2. 괄호를 닫을 때 보단 열 때 위주로 알고리즘이 작동함
//3. 괄호열의 부분집합이 평가되는 값을 스택에 넣지 않고 별도의 변수에 저장함
//4. #include <stack>
//5. 마지막 if문에서 오류처리를 진행하는데 비정상적인 괄호열도
//  오류 처리를 통과하여 else문으로 도달할 수 있음.
//  단, ans가 0이므로 출력 결과가 0임은 변하지 않음.

#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main() {
    string n;
    cin >> n;
    stack<char> s;
    int ans = 0, k = 0, l = 0, mul = 1;
    for (int i = 0; i<n.length(); i++) {
        char now = n[i];
        switch (now) {
        case '(':
            ++k;
            s.push(now);
            mul *= 2;
            if (i + 1<n.length() && n[i+1] == ')')
                ans += mul;
            break;
        case '[':
            ++l;
            s.push(now);
            mul *= 3;
            if (i + 1<n.length() && n[i + 1] == ']')
                ans += mul;
            break;
        case ')':
            --k;
            s.pop();
            mul /= 2;
            break;
        case ']':
            --l;
            s.pop();
            mul /= 3;
            break;
        }
    }
    if (s.size()!=0 || l != 0 || k != 0) cout << 0 << endl;
    else cout << ans << endl;
    return 0;
}


