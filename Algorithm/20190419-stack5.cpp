//백준 2504번
//괄호의 값
//(X)의 값은 2*X (X가 없으면 2), [X]의 값은 3*X (X가 없으면 3)
//괄호열 "XY"의 값은 X+Y
//올바른 괄호열이 아니면 0 출력.

//cygwin 상에서 동작 확인.
//백준 사이트에서는 런타임 에러로 뜸
//참고한 사이트: https://zorba91.tistory.com/entry/java-백준-알고리즘-2504번-괄호의-값-풀이

//런타임 에러의 대표적인 유형으로 segfault가 있다는 정보.
//stack의 자료형을 char에서 int로 수정
//givenArray 배열 크기를 31로 증가.
//여전히 런타임 에러...

#include <iostream>

int main()
{
    int stack[15];
    int stackIdx = -1; //스택 최상위를 가리킴.
    char givenArray[31] = {0};
    int total = 0;
    int tmp;
    scanf("%s", givenArray);
    for (int i = 0; givenArray[i] != 0; i++)
    {
        if (givenArray[i] == '(')
        {
            stack[++stackIdx] = '(';
        }
        else if (givenArray[i] == '[')
        {
            stack[++stackIdx] = '[';
        }
        if (givenArray[i] == ')')
        {
            if (i == 0)
            {
                printf("0\n");
                return 0;
            }
            switch (stack[stackIdx])
            {
            case '(':
                stack[stackIdx] = 2;
                break;
            case '[':
                printf("0\n");
                return 0;
            case ')':
                printf("0\n");
                return 0;
            case ']':
                printf("0\n");
                return 0;
            default:
                tmp = 0;
                for (stackIdx; stack[stackIdx] != '('; stackIdx--)
                {
                    if ((stack[stackIdx] == '[') || (stack[stackIdx] == ')') || (stack[stackIdx] == ']'))
                    {
                        printf("0\n");
                        return 0;
                    }
                    tmp += stack[stackIdx];
                }
                stack[stackIdx] = tmp * 2;
            }
        }
        if (givenArray[i] == ']')
        {
            if (i == 0)
            {
                printf("0\n");
                return 0;
            }
            switch (stack[stackIdx])
            {
            case '[':
                stack[stackIdx] = 3;
                break;
            case '(':
                printf("0\n");
                return 0;
            case ']':
                printf("0\n");
                return 0;
            case ')':
                printf("0\n");
                return 0;
            default:
                tmp = 0;
                for (stackIdx; stack[stackIdx] != '['; stackIdx--)
                {
                    if ((stack[stackIdx] == '(') || (stack[stackIdx] == ')') || (stack[stackIdx] == ']'))
                    {
                        printf("0\n");
                        return 0;
                    }
                    tmp += stack[stackIdx];
                }
                stack[stackIdx] = tmp * 3;
            }
        }
        /*디버깅용
        printf("%d 처리, stack: ", i);
        for (int j = 0; j < stackIdx + 1; j++)
        {
            printf("%d ", stack[j]);
        }
        printf("\n");
        */
    }
    tmp = 0;
    for (int i = 0; i < stackIdx + 1; i++)
    {
        tmp += stack[i];
    }
    printf("%d\n", tmp);

    return 0;
}
