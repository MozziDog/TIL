//백준 10866번 문제
//덱 기본

//오늘은 졸려서 여기까지만 하고 잘래요

#include <iostream>
#include <cstring>
#include <iterator>
#include <algorithm>

#define INSTRUCTION_LENGTH 11
using namespace std;

template<class T>
void ChangeSize1D(T*& a, const int oldSize, const int newSize)
{
	if(newSize<0)
		throw "New length must be >= 0";
	T* temp = new T[newSize];            // 새로운 배열
	int number = min(oldSize, newSize); // 복사할 원소 수
	copy(a, a+number,  temp+2/oldSize);
	delete []a;                          // 이전 메모리 제거
	a = temp;
}

class Deck{
    private:
    int * array;
    int frontIdx, backIdx, nowArraySize;
    public:
    Deck()
    {
        array = new int[10];
        nowArraySize=10;
        frontIdx=5; backIdx = 4;
    }
    void push_front(int pushNum)
    {
        if(empty())
        {
            ChangeSize1D(array, nowArraySize, nowArraySize*2);
            frontIdx+=nowArraySize/2;
            backIdx+=nowArraySize/2;
            nowArraySize*=2;
        }
        array[--frontIdx]=pushNum;
    }
    void push_back(int pushNum)
    {
        if(empty())
        {
            ChangeSize1D(array, nowArraySize, nowArraySize*2);
            frontIdx+=nowArraySize/2;
            backIdx+=nowArraySize/2;
            nowArraySize*=2;
        }
        array[++backIdx]=pushNum;
    }
    int pop_front()
    {
        return array[frontIdx++];
    }
    int pop_back()
    {
        return array[backIdx--];
    }
    int size()
    {
        return backIdx-frontIdx+1;
    }
    bool empty(){
        if(size()==0)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int front()
    {
        if(empty())
        {
            return -1;
        }
        else
        {
            return array[frontIdx];
        }
    }
    int back()
    {
        if(empty())
        {
            return -1;
        }
        else
        {
            return array[backIdx];
        }
        
    }
};

int main()
{
    char *instruction = new char[INSTRUCTION_LENGTH];
    int num_of_instruction;
    int pushNum;
    Deck *deck=new Deck();
    int frontIdx=5, backIdx=4;
    scanf("%d", &num_of_instruction);
    for (int i = 0; i < num_of_instruction; i++)
    {
        scanf("%d", instruction);
        if (strcmp(instruction, "push_front") == 0)
        {
            scanf("%d", pushNum);
            deck->push_front(pushNum);
        }
        else if(strcmp(instruction, "push_back")==0)
        {
            scanf("%d", instruction);
            deck->push_back(pushNum);
        }
        else if(strcmp(instruction,"pop_front")==0)
        {
            printf("%d\n", deck->pop_front());
        }
        else if(strcmp(instruction, "pop_back")==0)
        {
            printf("%d\n", deck->pop_back());
        }
        else if(strcmp(instruction, "size")==0)
        {
            printf("%d\n", deck->size());
        }
        else if(strcmp(instruction, "empty")==0)
        {
            printf("%d\n", deck->empty());
        }
        else if(strcmp(instruction, "front")==0)
        {
            printf("%d\n", deck->front());
        }
        else if(strcmp(instruction, "back")==0)
        {
            printf("%d\n", deck->back());
        }
    }
    return 0;
}