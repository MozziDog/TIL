//백준 1629번 문제
//곱셈
//A B C 가 주어졌을 때 (A^B)%C를 구하기

//A=C+D 라고 할 때, (D는 자연수)
//A^2=C^2+2CD+D^2
//(A^2)%C = (D^2)%C
//A^3=C^3+3(C^2)D+3C(D^2)+D^3
//(A^3)%C = (D^3)%C

//그러므로
//(A^B)%C = ((A-C)^B)%C 이다.
//D가 음의 정수일 때에도 성립하는가?
//10 11 12의 경우 답은 4임
//(10-12)^11= -2048
//-2048 % 12 = -8
//성립하지 않음.
//하지만 -8+12 = 4임
//if문으로 보정하면 될 듯.

//A(A-C)=A^2-AC

//시간초과

//최적화가 필요함.
//방안 1: A가 C보다 클경우 A=A%C로 한다. 숫자가 작으면 더 빠를 것임
//방안 2: 같은 수를 계속 곱하면 일정한 패턴이 반복 될 것이니
//n번마다 반복되는 패턴을 찾은 뒤
//찾아낸 패턴의 n과 B값을 활용하여 답을 구함.

//메모리 초과... 
//배열의 크기를 B로 해서 그런듯 하다.
//이것으로 백준 채점에서는 극단적인 케이스도 테스트한다는 것을 알 수 있다.
//방안 1: 패턴은 C로 나눈 나머지 수들의 배열이므로 패턴의 길이는 C보다 
//커질 수 없다는 점에 착안해 배열의 길이를 C로 함. 
//이것도 C가 크면 답이 없는데
//그냥 적당히 큰 상수로 둘까

//런타임 에러
//지역변수로 선언된 배열의 크기는 커서는 안된다는 걸 까먹었다.
//전역으로 수정해도 에러네 ㅅㅂ

//https://onsil-thegreenhouse.github.io/programming/problem/2018/03/29/problem_math_power/
//여기 참고해서 풀어볼 것

#include <iostream>
int array[100] = {0};
int main()
{
    int A, B, C;
    long answer = 1;
    int arrayIdx = 0;
    int patLength = 3;
    scanf("%d", &A);
    scanf("%d", &B);
    scanf("%d", &C);
    for (int i = 0; i < B; i++)
    {
        answer *= A;
        if (answer >= C)
        {
            answer %= C;
        }
        //printf("%d", answer);
        if (array[arrayIdx] == answer)
        {
            arrayIdx++;
            //printf(": 패턴의 %d번째와 일치\n", arrayIdx);
        }
        else
        {
            arrayIdx = 0;
            patLength=i+1;
            //printf(": 패턴과 불일치. 패턴찾기 리셋\n");
        }
        array[i] = answer;
        if (arrayIdx > patLength*2)
        {
            //printf("패턴 발견 : %d마다 반복\n", patLength);
            B = B % patLength;
            //printf("B를 %d로 대체\n", B);
            answer = 1;
            for (int j = 0; j < B; j++)
            {
                answer *= A;
                if (answer >= C)
                {
                    answer %= C;
                }
                //printf("%d\n", answer);
            }
            break;
        }
    }
    printf("%d", answer);
    return 0;
}