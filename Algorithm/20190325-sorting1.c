//백준 2750번 문제
//수 정렬하기
//버블 정렬

#include <stdio.h>
#include <stdlib.h>

void swap(int*, int* b);

int main(void)
{
    int length;
    scanf("%d", &length);
    int* list=(int*)malloc(length*sizeof(int));
    for(int i=0; i<length; i++)
    {
        scanf("%d", &list[i]);
    }
    for(int i=0; i<(length-1); i++)
    {
        for(int j=0; j<(length-i-1); j++)
        {
            if(list[j]>list[j+1])
            {
                swap(&list[j], &list[j+1]);
            }
        }
    }
    for(int i=0; i<length; i++)
    {
        printf("%d\n", list[i]);
    }
    return 0;
}

void swap(int* a, int* b)
{
    int tmp;
    tmp=*a;
    *a=*b;
    *b=tmp;
    return;
}