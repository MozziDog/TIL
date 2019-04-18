//백준 9012번 문제
//괄호 문자열

//성공

#include <iostream>

int stack = 0;
void check(char *string)
{
    int i = 0;
    stack = 0;
    while (string[i] != '\0')
    {
        if (string[i] == '(')
        {
            stack++;
        }
        else if (string[i] == ')')
        {
            stack--;
        }
        if (stack < 0)
        {
            printf("NO\n");

            return;
        }
        i++;
    }
    if(stack==0)
        printf("YES\n");
    else
    {
        printf("NO\n");
    }
    
    return;
}

int main()
{
    int T;
    scanf("%d", &T);
    char *string = new char[50];
    for (int i = 0; i < T; i++)
    {
        scanf("%s", string);
        check(string);
    }

    return 0;
}