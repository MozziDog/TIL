//백준 10872번 문제
//팩토리얼

//N이 12 이하이기에 int 로도 될 것 같은데 혹시몰라서 long형으로 함

//정답 

#include <iostream>

int main()
{
    int N; 
    scanf("%d", &N);
    long answer = 1;
    for(int i=1; i<=N; i++)
        answer *= i;
    printf("%ld", answer);
    return 0;
}