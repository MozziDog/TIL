//백준 2750번 문제
//선택 정렬

#include<stdio.h>
#include<stdlib.h>

void swap(int*, int*);

int main()
{
    int n=5, min;
    scanf("%d", &n);
    int* a = malloc(n*sizeof(int));
    for(int i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }
    

    //start sorting
    for(int i=0; i<n-1; i++)
    {
        min = i;
        //find minimum number
        for(int j=i+1; j<n; j++)
        {
            if(a[min] > a[j])
            {
                min = j;
            }
        }
        swap(&a[min], &a[i]);
    }

    for(int i=0; i<n; i++)
    {
        printf("%d\n", a[i]);
    }
    return 0;
}

void swap(int* a, int* b)
{
    int temp=*a;
    *a = *b;
    *b = temp;
}