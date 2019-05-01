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

//해결. 중요도 n을 검사한 후 n-1을 검사하기 전에 더 남은 n이 없나
//체크하는 과정에서 체크포인트가 반바퀴마다 갱신되는 현상으로 인해
//체크포인트로 돌아오지 못하고 무한순환하는 것이었음.

#include <stdio.h>

int main()
{
    int testCase;
    int N, M;
    int index = 0, indexSave;
    int answer = 0;
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
        for (int i = index; i > -1; )
        {
            if ((M == i) && (queue[M] == nowChecking))
            {
                //printf("인쇄: %d번째 원소, 중요도 %d\n", i, queue[i]);
                answer ++;
                break;
            }

            if (queue[i] == nowChecking)
            {
                //printf("인쇄: %d번째 원소, 중요도 %d\n", i, queue[i]);
                answer++;
                indexSave = i;
            }
            //printf("i: %d, nowChecking: %d\n", i,nowChecking);
            if (++i == N)
            {
                i = 0;
            }
            if (i == index)
            {
                nowChecking--;
                index=indexSave;
                i=index;
            }
        }
        printf("%d\n", answer);
        answer = 0;
    }
}