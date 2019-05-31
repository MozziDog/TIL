//백준 2490번
//윷놀이

//정답

#include <iostream>

int main()
{
    int tmp, count;
    for(int i=0; i<3; i++)
    {
        count = 0;
        for(int j=0; j<4; j++)
        {
            scanf("%d", &tmp);
            if(tmp == 0)
                count ++;
        }
        if(count == 0)
            printf("E\n");
        else
            printf("%c\n", 'A'+count-1);
        
    }
    return 0;
}