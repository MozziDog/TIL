//백준 1874번 문제
//스택 수열

//실패
//Cygwin 상에서는 잘 작동하는데 왜 백준에서는 틀렸다고 나올까
//알고리즘이 틀린 것 같지도 않은데
//http://blog.naver.com/occidere/220812563361 
//여기 참고해서 다시 풀어보기

#include <cstdlib>
#include <iostream>
#define MAX_STACK 10000
using namespace std;

class stack
{
  private:
    unsigned int nArray[MAX_STACK];
    int size;

  public:
    stack();
    void push(int data);
    int pop();
    int top();
};
stack::stack()
{
    size = -1;
}
void stack::push(int data)
{
    if (size == (MAX_STACK - 1))
    {
        cout << "::Stack Overflow::" << endl;
        return;
    }
    nArray[++size] = data;
}
int stack::pop()
{
    if (size == -1)
    {
        return -1;
    }
    return nArray[size--];
}
int stack::top()
{
    if (size == -1)
        return -1;
    else
        return nArray[size];
}

int main(int argc, char *argv[])
{
    stack s1;
    char* popNpush = new char[10000];
    int popNpushIndex=-1;
    int arrayLength;
    int leftNumisBeginWith =1;
    int popNeeded;
    cin>>arrayLength;
    int* array = new int[arrayLength];
    for(int i=0; i<arrayLength; i++)
    {
        cin>>array[i];
    }
    //cout<<"--------"<<endl;
    for(int i=0; i<arrayLength; i++)
    {
        //cout<<"target: "<<array[i]<<endl;
        if(array[i]==s1.top())
        {
            s1.pop();
            popNpush[++popNpushIndex]='-';
            //cout<<"pop"<<endl;
        }
        else if(array[i]>=leftNumisBeginWith)
        {
            popNeeded = array[i]-leftNumisBeginWith+1;
            for(int j=0; j<popNeeded; j++)
            {
                s1.push(leftNumisBeginWith++);
                popNpush[++popNpushIndex]='+';
                //cout<<"push"<<endl;
            }
            s1.pop();
            popNpush[++popNpushIndex]='-';
            //cout<<"pop"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
            //cout<<"현재 "<<array[i]<<"가 스택 깊숙이 있어 꺼낼 수 없음"<<endl;
            return 0;
        }
    }
    for(int i=0; i<(popNpushIndex+1); i++)
    {
        cout<<popNpush[i]<<endl;
    }

    return 0;
}