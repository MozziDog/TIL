//백준 2740번 문제
//행렬 곱셈

//굳

#include <iostream>

int main() {
    int N, M, K;
    scanf("%d %d", &N, &M);
    int **matrix1 = new int*[N];
    for(int i=0; i<N; i++)
    {
        matrix1[i] = new int[M];
    }
    for(int i = 0; i<N; i++)
    {
        for(int j=0; j<M; j++)
        {
            scanf("%d", &matrix1[i][j]);
        }
    }
    scanf("%d %d", &M, &K);
    int **matrix2 = new int*[M];
    for(int i=0; i<M; i++)
    {
        matrix2[i] = new int[K];
    }
    for(int i = 0; i<M; i++)
    {
        for(int j=0; j<K; j++)
        {
            scanf("%d", &matrix2[i][j]);
        }
    }
    int **answerMatrix = new int*[N];
    for(int i=0; i<N; i++)
    {
        answerMatrix[i] = new int[K];
    }
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<K; j++)
        {
            int element = 0;
            for(int k=0; k<M; k++)
            {
                element += (matrix1[i][k]*matrix2[k][j]);
            }
            answerMatrix[i][j] = element;
        }
    }
    for(int i=0; i<N; i++)
    {
        for(int j=0; j<K; j++)
        {
            printf("%d ", answerMatrix[i][j]);
        }
        printf("\n");
    }
}