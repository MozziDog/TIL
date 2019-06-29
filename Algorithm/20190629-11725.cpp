//백준 11725번 문제
//트리의 부모 찾기

//아 자바로 하고 싶다
//2진 트리란 조건이 있으면 단박에 해결인데 그런 조건이 없네...

#include <iostream>
#include <vector>

using namespace std;

vector< vector<bool> > connection;

int* parent;

void findParent(int num){
    for (std::vector<bool>::iterator it = connection[num].begin(); it != v.end(); ++it)
}
int main()
{
    int NumOfNodes;
    scanf("%d", &NumOfNodes);
    for(int i=0; i<NumOfNodes+1; i++){
        vector<bool> row(NumOfNodes+1);
        fill(row.begin, row.begin + NumOfNodes, false);
        connection.push_back(row);
    }
    for (int i = 1; i < NumOfNodes; i++)
    {
        int num1, num2;
        scanf("%d %d", &num1, &num2);
        connection[num1][num2] = true;
        connection[num2][num1] = true;
    }
    for(int i=1; i<NumOfNodes; i++)
    {
        connection.
    }
    return 0;
}