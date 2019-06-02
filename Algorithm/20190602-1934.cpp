//백준 1934번 문제
//최소공배수

//시간 초과 걸릴 것 같은데
//엥 맞았네
//개꿀

#include <iostream>

int main()
{
    int T, A, B;
    int answer;
    scanf("%d", &T);
    for (int testCase = 0; testCase < T; testCase++)
    {
        answer = 0;
        scanf("%d", &A);
        scanf("%d", &B);
        if (A > B)
        {
            while (true)
            {
                answer += A;
                if (answer % B == 0)
                {
                    printf("%d\n", answer);
                    break;
                }
            }
        }
        else
        {
            while(true)
            {
                answer += B;
                if(answer % A == 0)
                {
                    printf("%d\n", answer);
                    break;
                }
            }
        }
    }
    return 0;
}