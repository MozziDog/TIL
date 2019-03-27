//백준 2751번 문제
//수 정렬하기
//힙 정렬
//실패 : 입력 받은 이후 출력이 되지 않음

#include <stdio.h>
#include <stdlib.h>

int num;
int *array;
void makeHeap(int);
void swap(int*, int*);

int main(void)
{
    scanf("%d", &num);
    array = malloc(num * sizeof(int));
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &array[i]);
    }
    for(int i=num; i>1; i--)
    {
        makeHeap(i);
        swap(&array[0], &array[i]);
    }
    for (int i = 0; i<num; i++)
    {
        printf("%d\n", array[i]);
    }
}

void makeHeap(int num)
{
    for (int i = 1; i < num; i++)
    {
        int c = i;
        do
        {
            if (array[c] > array[(c - 1) / 2])
            {
                swap(&array[c], &array[(c - 1) / 2]);
            }
        } while (c != 0);
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
