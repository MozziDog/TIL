//백준 13241번 문제
//최소공배수

//정답

#include <iostream>
//#include <time.h>

int main() {
    //time_t start;
    long long int a, b;
    long long int answer = 0;
    scanf("%lld", &a);
    scanf("%lld", &b);

    //start = time(0);

    for(long long int i=a; ; i+=a) {
        if(i%b == 0)
        {
            answer = i;
            break;
        }
    }
    printf("%lld", answer);
    //printf("\n%f", (double)time(0)-start);
    return 0;
}