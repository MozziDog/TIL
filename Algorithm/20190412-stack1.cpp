//백준 10828번 문제
//기초적인 스택 사용

//성공

#include <cstdlib>
#include <iostream>
#include <string>
#define MAX_STACK 10000
using namespace std;

class stack
{
  private:
    unsigned int nArray[MAX_STACK];
    int top;

  public:
    stack();
    void push(int data);
    int pop();
    int size();
    int empty();
    int returnTop();
};
stack::stack()
{
    top = -1;
}
void stack::push(int data)
{
    if (top == (MAX_STACK - 1))
    {
        cout << "::Stack Overflow::" << endl;
        return;
    }
    nArray[++top] = data;
}
int stack::pop()
{
    if (top == -1)
    {
        return -1;
    }
    return nArray[top--];
}
int stack::size()
{
    return (top + 1);
}
int stack::empty()
{
    return (top == -1) ? 1 : 0;
}
int stack::returnTop()
{
    if (top == -1)
        return -1;
    else
        return nArray[top];
}
int main(int argc, char *argv[])
{
    stack s1;
    int pushNum = 0;
    int instNum;
    cin >> instNum;
    string* getString=new string[instNum];
    int* getInt = new int[instNum];

    for (int i = 0; i < instNum; i++)
    {
        cin>>getString[i];
        if(getString[i].compare("push")==0)
        {
            cin>>getInt[i];
        }
    }
    for (int i=0; i<instNum; i++)
    {
        if(getString[i].compare("push")==0)
        {
            s1.push(getInt[i]);
        }
        else if(getString[i].compare("pop")==0)
        {
            cout<<s1.pop()<<endl;
        }
        else if(getString[i].compare("size")==0)
        {
            cout<<s1.size()<<endl;
        }
        else if(getString[i].compare("empty")==0)
        {
            cout<<s1.empty()<<endl;
        }
        else if(getString[i].compare("top")==0)
        {
            cout<<s1.returnTop()<<endl;
        }
        else
        {
            cout<<"명령어 해석 오류"<<endl;
        }
        
    }
    return 0;
}