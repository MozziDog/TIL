//백준 1629번 문제
//곱셈
//A B C 가 주어졌을 때 (A^B)%C를 구하기

//틀림
//뭐가 문제지

//결국 해설 코드 베낌 ㅜㅜ

//요점 1: O(n)이던 곱셈과정을 O(log_2 n)으로 줄이기 위해 이진트리를
//그리는 것처럼 접근 했었는데 입력받은 b값을 2진수로 나타낸다고 
//생각하는 게 쉽겠더라
//요점 2: 함수 나누지 말고 main 함수 안에서 다 하는 게 편한 듯

#include <iostream>


int main()
{
    long a;
    int b, c;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    a=a%c;
    long answer=1;
    while(b>0)
    {
        if(b%2==1)
        {
            answer *= a;
            answer %= c;
        }
        a=a*a%c;
        b/=2;
    }
    printf("%d", answer);
    return 0;
}
