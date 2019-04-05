//백준 2751번 문제
//merge sort 병합 정렬
//난 잘 실행되는데 왜 백준에서는 런타임 에러가 날까

#include <stdio.h>
#include <stdlib.h>

//conquer
void merge(int* array, int low, int mid, int high){
    int b[1000];
    //low는 왼쪽의 시작, mid+1은 오른쪽의 시작
    int i=low, j=mid+1, k= 0;
    //
    while(i<=mid && j<=high)
    {
        if(array[i]<=array[j])
        {
            b[k++]=array[i++];
        }
        else
        {
            b[k++]=array[j++];
        }
    }
    while(i<=mid)
    {
        b[k++]=array[i++];
    }
    while(j<=high)
    {
        b[k++]=array[j++];
    }
    /* 디버깅용
    for(int i=low; i<=high; i++){
        printf("%d ", b[i]);
    }
    printf("\n");
    */
    k--;
    while(k>=0)
    {
        array[low+k]= b[k];
        k--;
        //궁금증 1
        //array[low+k]= b[k--]; 와 array[low+k]= b[k]; k--; 가 왜 서로 다른가?
    }
    /* 디버깅용
    for(int i=low; i<=high; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
    */
}

//divide
void mergesort(int* array, int low, int high){
    //exit condition
    if(low < high)
    {
        int mid=(low+high)/2;

        //left
        mergesort(array, low, mid);
        //right
        mergesort(array, mid+1, high);

        //merge
        merge(array, low, mid ,high);
    }
    else
    {
        return;
    }
}

int main(){
    int length;
    scanf("%d", &length);
    int * array = malloc(length*sizeof(int));
    for(int i=0; i<length; i++)
    {
        scanf("%d", &array[i]);
    }

    mergesort(array,0,length-1);

    for(int i=0; i<length; i++)
    {
        printf("%d\n", array[i]);
    }
    return 0;
}