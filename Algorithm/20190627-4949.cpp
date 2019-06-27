//백준 4949번 문제
//균형잡힌 세상
//괄호가 적절한지 검사

//틀림
//혹시 여러문장을 한꺼번에 검사해야하는 건가?
//그릏네

//여러 문장을 한꺼번에 검사하도록 수정
//문장간의 구분을 '.'이 아닌 '\n'으로 하도록 수정
//한 문장이 no로 결정이 나도 끝까지 scanf하도록 수정(안그러면 다음 줄에 영향을 줌)

//정답

#include <iostream>

int main()
{
    char stack[100] = {0};
    int stackIdx = -1;
    char nextChar;
    bool answer;
    while (true)
    {
        scanf("%c", &nextChar);
        if(nextChar == '.')
            break;
        answer = true;
        while (true)
        {
            if (nextChar == '(')
            {
                stack[++stackIdx] = '(';
            }
            if (nextChar == ')')
            {
                if (stack[stackIdx] != '(')
                {
                    answer = false;
                }
                stack[stackIdx--] = '\0';
            }
            if (nextChar == '[')
            {
                stack[++stackIdx] = '[';
            }
            if (nextChar == ']')
            {
                if (stack[stackIdx] != '[')
                {
                    answer = false;
                }
                stack[stackIdx--] = '\0';
            }
            if (nextChar == '\n')
            {
                if (stackIdx == -1 && answer == true)
                {
                    printf("yes\n");
                    break;
                }
                else
                {
                    printf("no\n");
                    break;
                }
            }
            scanf("%c", &nextChar);
        }
        stackIdx=-1;
    }
    return 0;
}