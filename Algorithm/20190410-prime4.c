//백준 4948번 문제
//소수구하기-베르트랑 공준
//
//임의의 자연수 n에 대하여 n보다 크고 2n보다 작거나 같은 소수가
//적어도 하나 존재

//실수: 입력의 끝을 표시하는 0을 포함하여 n개의 입력이 있으면 
//n-1개의 출력이 있어야 하는데 0에 대한 결과를 포함하여 n개가 출력됬음

//성공


#include <stdio.h>

int list[246913]= {1, 1};
int num=0;
int input[100];

int main()
{
    //에라토스테네스의 체 생성
    for(int i=2; i<=246913; i++)
    {
        if(list[i]==0)
        {
            for(int j=2*i; j<=246913; j+=i)
            {
                list[j]=1;
            }
        }
    }
    /*디버깅용
    printf("에라토스테네스의 체:\n");
    for(int i=1; i<=123456; i++)
    {
        if(list[i]==0)
        {
            printf("%d ", i);
        }
    }
    return 0;
    */
    do{
        scanf("%d",&input[num]);
        num++;
    }while(input[num-1]!=0);

    int output;
    for(int i=0; i<num-1; i++){
        output=0;
        for(int j=input[i]+1; j<=2*input[i]; j++)
        {
            if(list[j]==0)
            {
                output++;
                //printf("now j: %d, output: %d\n", j, output); //디버깅용
            }
        }
        printf("%d\n", output);
    }
    //printf("끝\n");

    return 0;
}