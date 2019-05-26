//백준 1003번 문제
//피보나치 함수
//at 동적 계획법

//시간 초과

//틀림

#include <iostream>

int numOf_0[41] = {0};
int numOf_1[41] = {0};

int main()
{
    numOf_0[0] = 1;
    numOf_0[1] = 0;
    numOf_1[0] = 0;
    numOf_1[1] = 1;
    for(int i=2; i<=40; i++)
    {
        numOf_0[i] = numOf_0[i-1]+numOf_0[i-2];
        numOf_1[i] = numOf_1[i-1]+numOf_1[i-2];
    }
    int NumTestCase;
    scanf("%d", &NumTestCase);
    for (int testCase = 0; testCase < NumTestCase; testCase++)
    {
        int n;
        scanf("%d", &n);
        printf("%d %d\n", numOf_0[n], numOf_1[n]);
    }
    return 0;
}