//백준 10773번 문제
//제로

//왜 틀렸지?

//아 미띤 answer 초기화를 안해서였어 ㅜㅜ


#include <iostream>

int num[100000];
int main()
{
    int K;
    scanf("%d", &K);
    int tmp;
    int idx = 0;
    for(int i=0; i<K; i++)
    {
        scanf("%d", &tmp);
        if(tmp == 0)
        {
            idx--;
            num[idx] = 0;
        }
        else
        {
            num[idx] = tmp;
            idx++;
        }
    }
    long long answer=0;
    for(int i=0; i<idx; i++)
    {
        answer += num[i];
    }
    printf("%lld", answer);
}