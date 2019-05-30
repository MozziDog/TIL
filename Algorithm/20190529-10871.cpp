//백준 10871번 문제
//X보다 작은 수

//정답

#include <iostream>

int main() {
    int N, X, A;
    scanf("%d", &N);
    scanf("%d", &X);
    for(int i=0; i<N; i++)
    {
        scanf("%d", &A);
        if(A<X)
            printf("%d ", A);
    }
    return 0;
}