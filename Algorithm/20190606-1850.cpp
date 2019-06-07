//백준 1850문제
//최대공약수

//모든 자릿수가 1로만 이루어진 두 수의 최대공약수 구하기

//시간 초과

#include <iostream>

int main()
{
    long int a, b;
    scanf("%ld", &a);
    scanf("%ld", &b);
    long answer;
    if (a == b)
    {
        answer = a;
    }
    else
    {
        for (long int i = (a-b)>0 ? a-b : b-a;; i--)
        {
            if (a % i == 0)
                if (b % i == 0)
                {
                    answer = i;
                    break;
                }
        }
    }
    for (int i = 0; i < answer; i++)
    {
        printf("1");
    }
    return 0;
}
