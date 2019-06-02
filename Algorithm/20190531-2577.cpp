//백준 2577번
//숫자의 개수

//정답

#include <iostream>

int main()
{
    int a, b, c;
    long tmp;
    int answer[10]= {0};
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    tmp = a*b*c;
    while(tmp!=0)
    {
        answer[tmp%10]+=1;
        tmp/=10;
    }
    for(int i=0; i<10; i++)
    {
        printf("%d\n", answer[i]);
    }
    return 0;
}