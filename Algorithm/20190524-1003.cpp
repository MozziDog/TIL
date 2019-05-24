//백준 1003번 문제
//피보나치 함수
//at 동적 계획법

//시간 초과

#include <iostream>

int numOf_0 = 0;
int numOf_1 = 0;

int fibonacci(int n)
{
    if (n == 0)
    {
        numOf_0++;
        return 0;
    }
    else if (n == 1)
    {
        numOf_1++;
        return 1;
    }
    else
    {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main()
{
    int NumTestCase;
    scanf("%d", &NumTestCase);
    for (int testCase = 0; testCase < NumTestCase; testCase++)
    {
        int n;
        scanf("%d", &n);
        fibonacci(n);
        printf("%d %d", numOf_0, numOf_1);
        numOf_0 = 0;
        numOf_1 = 0;
    }
    return 0;
}