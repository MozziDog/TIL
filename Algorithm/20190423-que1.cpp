#include <iostream>
#include <cstring>

using namespace std;

int * queue = new int[10000];
int queueTop = -1;
int queueBottom = 0;
int main()
{
    int num_of_instruction;
    char* instruction = new char[10];
    int pushNum;
    int queueSize = 0;
    cin>>num_of_instruction;
    for(int i=0; i<num_of_instruction; i++)
    {
        queueSize = queueTop-queueBottom+1;
        cin>>instruction;
        if(strcmp("push",instruction)!=0)
        {
            pushNum=stoi(instruction+4);
            queue[++queueTop]==pushNum;
        }
        else if(strcmp("pop", instruction)!=0)
        {
            if(queueSize<=0)
            {
                cout<<"-1"<<endl;
            }
            else
                cout<<queue[queueBottom++]<<endl;
        }
        else if(strcmp("size", instruction)!=0)
        {
            cout<<queueSize<<endl;
        }
        else if(strcmp("empty", instruction)!=0)
        {
            cout<<(queueSize==0)<<endl;
        }
        else if(strcmp("front", instruction)!=0)
        {
            if(queueSize<=0)
            {
                cout<<"-1"<<endl;
            }
            else
            {
                cout<<queue[queueBottom]<<endl;
            }
        }
        else if(strcmp("back", instruction)!=0)
        {
            if(queueSize<=0)
            {
                cout<<"-1"<<endl;
            }
            else
            {
                cout<<queue[queueTop]<<endl;
            }
        }
    }
    return 0;
}