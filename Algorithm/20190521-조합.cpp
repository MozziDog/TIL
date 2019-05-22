//백준 2407번 문제
//조합

//n_C_m 의 값을 구하기

//틀림 뭐가 문제인 걸까
//자료형이 int라서 크기가 부족했던 것 같다.

//자료형을 long형으로 변경
//cache의 크기를 문제가 요구하는 수준인 100*100까지 축소
//문제에서 요구하는 최대값 100_C_50 이 잘 출력됨

//이번에도 틀림
//아 100_C_49하니까 음수나오네
//long형으로도 부족했었구나  테스트를 좀 더 꼼꼼히 해야겠다 ㅜ

//long long형으로 변경...해도 안됨

//직접 큰 정수를 나타내는 클래스를 만들었다
//어차피 덧셈만 오버로딩하면 됨 ㅎ

//틀림
//테스트 해보면 완벽하게 작동하는 것 같은데... 시간 초과도 아니고 그냥 틀렸다는데

#include<iostream>
#define UNIT 1000000000
class BigInt
{
    unsigned int data[20]; //각 10진수 9자리씩. 
    //arrayIndex가 작을수록 작은 값을 나타내는 걸로 하자
    public:
    BigInt(int a)
    {
        for(int i=0; i<20; i++)
        {
            data[i]=a%UNIT;
            a/=UNIT;
        }
    }
    BigInt()
    {
        for(int i=0; i<20; i++)
            data[i]=0;
    }
    BigInt operator + (BigInt a)
    {
        BigInt tmp;
        int upcount;
        for(int i=0; i<20; i++)
        {
            tmp.data[i]=data[i]+a.data[i];
            tmp.data[i]+=upcount;
            upcount=tmp.data[i]/UNIT; //받아올림
            tmp.data[i]%=UNIT;
        }
        return tmp;
    }
    void Print()
    {
        for(int i=19; i>=0; i--)
        {
            if(data[i]==0)
            {/*do nothing*/}
            else
            {
                printf("%u", data[i]);
            }
            
        }
    }
    
};

BigInt cache[101][101];

int main()
{
    int N, K;
    scanf("%d", &N);
    scanf("%d", &K);
    for(int i=1; i<= N; i++)
    {
        cache[i][1] = i;
        cache[i][i] = cache[i][0] = 1;
    }
    for(int i=3; i<=N; i++)
    {
        for(int j=2; j<i; j++)
        {
            cache[i][j] = cache[i-1][j-1]+cache[i-1][j];
        }
    }
    cache[N][K].Print();
    return 0;
}