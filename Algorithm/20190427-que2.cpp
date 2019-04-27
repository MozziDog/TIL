//백준 1966번 문제
//프린터 큐

//백준에서 제시한 예시 입력으로는 문제가 없는데
//직접 만든 테스트 입력으로는 오류 발생

//::테스트:: 
//N: 10, M=0, queue={1,1,8,1,1,9,8,1,1,1}

#include <stdio.h>

int main()
{
    int testCase;
    int N, M;
    int index=0 ,indexSave;
    int answer=1;
    int nowChecking;
    scanf("%d", &testCase);
    for(int i=0; i<testCase; i++)
    {
        index = 0;
        scanf("%d %d", &N, &M);
        int *queue = new int[N];
        for(int j=0; j<N; j++)
        {
            scanf("%d", &queue[j]);
            if(queue[index]<queue[j])
            {
                index = j;
            }
        }
        printf("index : %d, queue[index] : %d\n",index, queue[index] );
        nowChecking = queue[index];
        indexSave=index;
        while(1)
        {
            printf("%d\n", nowChecking);
            if((M==index)&&(queue[M]==nowChecking))
            {
                break;
            }
            else
            {
                if(queue[index]==nowChecking)
                {
                    answer++;
                    indexSave=index;
                }
                index++;
                if(index==indexSave)
                {
                    nowChecking--;
                }
                if(index==N)
                {
                    index=0;
                }
            }
        }
        printf("%d\n", answer);
        answer = 1;
    }
}