//백준 2981번 문제
//검문?
//주어진 N개의 수를 나누어서 나머지가 모두 같게 되는 수를 모두 찾기

//알고리즘이 잘 작동하긴 하지만 너무 시간이 느리다.
//예제입력 3/ 6/ 34/ 38 로 해봤는데 5초가 넘음


#include <iostream>
#include <ctime>

int main()
{
    int N;
    scanf("%d", &N);
    int* numbers = new int[N];
    int smallest = 1000000000;
    int second_smallest = 1000000001;
    for(int i=0; i<N; i++) {
        scanf("%d", &numbers[i]);
        if(numbers[i]<smallest)
        {
            second_smallest = smallest;
            smallest = numbers[i];
        }
    }
    time_t start = time(0);
    bool isAnswer = true;
    int left;
    for(int i=2; i<=second_smallest; i++) {
        isAnswer = true;
        left = numbers[0] % i;
        for(int j =1; j< N; j++) {
            if(numbers[j] % i != left){
                isAnswer = false;
                break;
            }
        }
        if(isAnswer)
        printf("%d ", i);
    }
    printf("%f", (double)time(0)-start);
    return 0;
}