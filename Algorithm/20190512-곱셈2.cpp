//백준 1629번 문제
//곱셈
//A B C 가 주어졌을 때 (A^B)%C를 구하기

//틀림
//뭐가 문제지

#include <iostream>

int multiply(int, int, int);

int main()
{
    int a, b, c;
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    int answer=multiply(a,b,c);
    printf("%d", answer);
    return 0;
}

int multiply(int a, int b, int c)
{
    if(b==1)
        return a;
    int tmp = multiply(a, b/2, c)%c;
    if(b%2==1)
        return tmp*tmp*a%c;
    else
        return tmp*tmp%c;
    
}