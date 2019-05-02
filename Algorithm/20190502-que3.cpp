//백준 11866번 문제
//조세퍼스 문제
//(N, K) 조세퍼스 순열을 구하기

//정답

#include <iostream>

int main()
{
    int N, K, index = -1;
    int tmp; //swap을 위한 tmp
    scanf("%d", &N);
    scanf("%d", &K);
    bool *array = new bool[N];
    for (int i = 0; i < N; i++)
    {
        array[i] = true;
    }
    printf("<");
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < K; j++)
        {
            index++;
            if (index == N)
                index = 0;
            while (array[index] == false)
            {
                index++;
                if (index == N)
                    index = 0;
            }
            //printf("nowindex = %d\n", index);
        }
        printf("%d", index+1);
        if(i<N-1)
        {
            printf(", ");
        }
        array[index]=false;
    }
    printf(">");
    return 0;
}