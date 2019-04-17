//백준 1874번 문제
//스택 수열

//시간 초과

//私の心の目は君に向かっている
//覚悟しなさい

#include<iostream>

using namespace std;

int main(void)
{
    int length;
    scanf("%d",length);
    int* array = new int[length];
    int* tmparray = new int[length];
    char* answer = new char[1000000];
    int tmparrayLength = 0;
    int answerLength = 0;
    int maxinStack = 0;
    for(int i=0; i<length; i++){
        scanf("%d",array[i]);
    }
    for(int i=0; i<length; i++)
    {
        if(array[i]<maxinStack)
        {
            if(tmparray[tmparrayLength]!=array[i])
            {
                printf("NO");
                return 0;
            }
            else
            {
                answer[answerLength++]='-';
                tmparrayLength--;
            }
        }
        else
        {
            int a=array[i]-maxinStack;
            for(int j=0; j<a; j++)
            {
                answer[answerLength++]='+';
                tmparray[++tmparrayLength]=++maxinStack;
            }
            answer[answerLength++]='-';
            tmparrayLength--;
        }
    }
    for(int i=0; i<answerLength; i++)
    {
        printf("%d\n",answer[i]);
    }
    return 0;
}