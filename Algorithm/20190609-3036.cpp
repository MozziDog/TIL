//백준 3036번
//링
//톱니바퀴 문제?

//정답

#include <iostream>

int main()
{
    int N;
    scanf("%d", &N);
    int *ring = new int[N];
    int A=1, B=1;
    scanf("%d", &ring[0]);
    for(int i=1; i<N; i++) {
        scanf("%d", &ring[i]);
        A*=ring[i-1];
        B*=ring[i];
        //기약분수로 만들기
        for(int j= A>B? B: A; j>0; j--) {
            if((A%j == 0) && (B % j == 0))
            {
                A/=j; B/=j;
                printf("%d/%d\n", A, B);
                break;
            }
        }
    }
    return 0;
}