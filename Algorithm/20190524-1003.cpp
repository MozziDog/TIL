//백준 1003번 문제
//피보나치 함수
//at 동적 계획법

//시간 초과

//틀림

//또 틀림 ㅜㅜ

#include <iostream>

int array[42] = {0};

int main()
{
    array[0] = 1;
    array[1] = 0;
    array[2] = 1;
    for(int i=3; i<=40; i++)
    {
        array[i] = array[i-1]+array[i-2];
    }
    int NumTestCase, n;
    scanf("%d", &NumTestCase);
    for (int testCase = 0; testCase < NumTestCase; testCase++)
    {
        scanf("%d", &n);
        printf("%d %d\n", array[n], array[n+1]);
    }
    return 0;
}