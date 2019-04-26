//백준 10845번
//큐

//실패
//Cygwin 상에서 완벽하게 작동하는 것 같은데 어디가 문제일까?

//엌ㅋㅋ cout과 cin을 printf와 scanf로 바꾸던 중에 실수가 있었음
//어쨌든 결국 성공 ^^

#include <iostream>
#include <cstring>

using namespace std;

int * queue = new int[10000];
int queueBack = -1;
int queueFront = 0;
int main()
{
    int num_of_instruction;
    char* instruction = new char[10];
    int pushNum;
    int queueSize = 0;
    scanf("%d", &num_of_instruction);
    for(int i=0; i<num_of_instruction; i++)
    {
        queueSize = queueBack-queueFront+1;
        scanf("%s", instruction);
        if(strcmp("pop", instruction)==0)
        {
            if(queueSize<=0)
            {
                printf("-1\n");
            }
            else
                printf("%d\n", queue[queueFront++]);
        }
        else if(strcmp("size", instruction)==0)
        {
            printf("%d\n", queueSize);
        }
        else if(strcmp("empty", instruction)==0)
        {
            printf("%d\n",(queueSize==0));
        }
        else if(strcmp("front", instruction)==0)
        {
            if(queueSize<=0)
            {
                printf("-1\n");
            }
            else
            {
                printf("%d\n",queue[queueFront]);
            }
        }
        else if(strcmp("back", instruction)==0)
        {
            if(queueSize<=0)
            {
                printf("-1\n");
            }
            else
            {
                printf("%d\n",queue[queueBack]);
            }
        }
        else //it means push
        {
            scanf("%d", &pushNum);
            queue[++queueBack]=pushNum;
        }
    }
    return 0;
}