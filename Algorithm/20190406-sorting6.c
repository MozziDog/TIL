//백준 2751번
//퀵 정렬 quick sort
//시간 초과로 실패 

#include <stdio.h>
#include <stdlib.h>

void swap(int * a, int * b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Partition(int[], int, int);

void QuickSort(int array[], int start, int end)
{
    int index;

    if(start<end){
        index = Partition(array, start, end);
        QuickSort(array, start, index-1);
        QuickSort(array, index+1, end);
    }
    else{
        return;
    }
}

int Partition(int array[], int start, int end)
{
    int pivot = array[end];
    int i;
    int index = start;

    for(i = start; i<end; i++)
    {
        if(array[i] <= pivot)
        {
            swap(&array[i], &array[index]);
            index++;
        }
    }
    swap(&array[index], &array[end]);
    return index;
}


int main()
{
    int length;
    scanf("%d", &length);
    int* array = malloc(length*sizeof(int));
    for(int i; i<length; i++)
    {
        scanf("%d", &array[i]);
    }
    QuickSort(array, 0, length-1);
    for(int i; i<length; i++)
    {
        printf("%d\n", array[i]);
    }
    return 0;
}