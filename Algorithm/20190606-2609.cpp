//백준 2609번
//최대공약수와 최소공배수

//틀림 왜?

//a가 b의 약수일 경우를 생각하지 못함


#include <iostream>

int main()
{   
    int a, b;
    scanf("%d", &a);
    scanf("%d", &b);
    int answer = 1;
    for(long i=a; i>0; i--) {
        if(a%i == 0)
            if(b%i == 0)
            {
                printf("%d\n", i);
                break;
            }
    }
    for(long int i=a; ; i+=a) {
        if(i%b == 0)
        {
            printf("%ld", i);
            break;
        }
    }
    return 0;
}