//백준 1966번 문제
//프린터 큐

//백준에서 제시한 예시 입력으로는 문제가 없는데
//직접 만든 테스트 입력으로는 오류 발생

//::테스트::
//N: 10, M=0, queue={1,1,8,1,1,9,8,1,1,1}

//제출 결과: 시간초과
//위 테스트 케이스에서 발생한 무한 루프때문인 듯.

//코드 고치려다가 오히려 엉망이 되어버렸는데
//아 몰랑 시험끝나고 생각하자

#include <stdio.h>

int main()
{
    int testCase;
    int N, M;
    int index = 0, indexSave;
    int answer = 1;
    int nowChecking;
    scanf("%d", &testCase);
    for (int i = 0; i < testCase; i++)
    {
        index = 0;
        scanf("%d %d", &N, &M);
        int *queue = new int[N];
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &queue[j]);
            if (queue[index] < queue[j])
            {
                index = j; //가장 중요도가 높은 녀석을 마킹.
            }
        }
        //printf("index : %d, queue[index] : %d\n",index, queue[index] );
        nowChecking = queue[index];
        indexSave = index;
        for (int i = index + 1; i > -1; i++)
        {
            if (i == N)
            {
                i = 0;
            }
            if ((M == i) && (queue[M] == nowChecking))
            {
                break;
            }

            if (i == index)
            {
                nowChecking--;
            }
            if (queue[i] == nowChecking)
            {
                printf("인쇄: %d번째 원소, 중요도 %d\n", i, queue[i]);
                answer++;
                index = i;
            }
            printf("nowChecking: %d\n", nowChecking);
        }
        printf("%d\n", answer);
        answer = 1;
    }
}