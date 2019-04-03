//백준 2750번 문제
//삽입정렬

#include <stdio.h>
#include <stdlib.h>

int main()
{

    int i, j;
    int temp;
    int n;

    scanf("%d", &n);
    int *a = malloc(n * sizeof(int));
    for (i=0; i<n; i++)
    {
        scanf("%d", &a[i]);
    }
    //outer loop
    for (i = 1; i < n; i++)
    {
        j = i;
        //inner loop
        //판단
        while (j > 0 && a[j] < a[j - 1])
        {
            //스왑부분
            temp = a[j];
            a[j] = a[j - 1];
            a[j - 1] = temp;

            j--;
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
