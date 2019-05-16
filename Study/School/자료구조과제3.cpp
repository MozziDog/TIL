#include<iostream>
using namespace std;

template <class T>
class Chain; // forward declaration

template <class T>
class ChainNode
{
    friend class Chain<T>;
public:
    T getData()
    {
        return data;
    }
private:
    T data;
    ChainNode<T> *link;
};


template <class T>
class Chain
{
public:
    Chain() { first = 0; }; // constructor initializing first to 0
                            // Chain manipulation operations
                            //0번 체인을 가리키는 first에 null 대입 => 공백 체인
    ~Chain()
    {
        ChainNode<T> *toDelete, *i = first;
        while (true)
        {
            toDelete = i;
            if(i->link==0)
            {
                delete toDelete;
                break;
            }
            i=i->link;
            delete toDelete;
        }
    }
    void AddChainAtFirst(T newNodeData)
    {
        ChainNode<T> *tmp = first;
        first = new ChainNode<T>;
        first->data = newNodeData;
        first->link = tmp;
    }
    void AddChainAtLast(T newNodeData)
    {
        if(first == 0)
        {
            AddChainAtFirst(newNodeData);
            return;
        }
        ChainNode<T> *i = first;
        if(i==0)
        {
            first = new ChainNode<T>;
            first->data = newNodeData;
            first->link = 0;
        }
        for (i; i->link != 0; i = i->link)
        {
        }
        i->link = new ChainNode<T>;
        i->link->link = 0;
        i->link->data = newNodeData;
    }
    ChainNode<T> Front()
    {
        return *first;
    }
    ChainNode<T> Back()
    {
        ChainNode<T> *i = first;
        for (i; i->link != 0; i = i->link)
        {
        } //find last node
        return *i;
    }
    ChainNode<T> Get(int i)
    {
        ChainNode<T> *tmp = first;
        for (int j = 0; j < i; j++)
        {
            tmp = tmp->link;
        }
        return *tmp;
    }
    void DeleteChainAtFirst()
    {
        ChainNode<T> *tmp = first->link;
        delete first;
        first = tmp;
    }
    void DeleteChainAtLast()
    {
        ChainNode<T> *i = first;
        for (i; i->link->link != 0; i = i->link)
        {
        } //find node before last
        delete i->link;
        i->link = 0;
    }
    void AddChainAtBackofi(int i, T newNodeData)
    {
        ChainNode<T> *tmp = first;
        for (int j; j < i; j++)
        {
            tmp = tmp->link;
        }
        ChainNode<T> *newNode = new ChainNode<T>;
        newNode->data = newNodeData;
        newNode->link = tmp->link;
        tmp->link = newNode;
    }
    void DeleteChainAti(int i)
    {
        ChainNode<T> *tmp1 = first;
        for(int j=0; j<i-1; j++)
        {
            tmp1 = tmp1->link;
        }
        ChainNode<T> *tmp2 = tmp1->link;//i번째 노드, 삭제대상
        tmp1->link = tmp2->link;
        delete tmp2;
    }
    class ChainIterator
    {
    public:
        // typedefs required by C++ for a forward iterator omitted

        // constructor
        ChainIterator(ChainNode<T>* startNode = 0)
        {
            current = startNode;
        }

        // dereferencing operators
        T &operator*() const { return current->data; }
        T *operator->() const { return &current->data; }

        // increment
        ChainIterator &operator++() // preincrement
        {
            current = current->link;
            return *this;
        }
        ChainIterator operator++(int) // postincrement
        {
            ChainIterator old = *this;
            current = current->link;
            return old;
        }

        // equality testing
        bool operator!=(const ChainIterator right) const
        {
            return current != right.current;
        }
        bool operator==(const ChainIterator right) const
        {
            return current == right.current;
        }

    private:
        ChainNode<T> *current;
    };

    ChainIterator begin()
    {
        return ChainIterator(first);
    }
    ChainIterator end()
    {
        return ChainIterator(0);
    }

    //public 공간 끝
private:
    ChainNode<T> *first;

};

int main()
{
    Chain<int> intChain;
    Chain<int>::ChainIterator iter=intChain.begin();
    for(int i=1; i<10; i++)
    {
        intChain.AddChainAtLast(i);
    }
    cout<<"1. 1부터 9까지의 정수를 갖는 노드 추가함"<<endl;

    cout<<endl<<"2. 전체 노드 출력 : ";
    for(iter = intChain.begin(); iter != intChain.end(); iter++)
    {
        cout<<*iter<<" ";
    }
    cout<<endl;

    cout<<endl<<"3. 0을 맨 앞에 삽입한다."<<endl;
    intChain.AddChainAtFirst(0);

    cout<<endl<<"4. 전체 노드 출력 : ";
    for(iter = intChain.begin(); iter != intChain.end(); iter++)
    {
        cout<<*iter<<" ";
    }
    cout<<endl;

    cout<<endl<<"5. 10을 맨 뒤에 삽입니다."<<endl;
    intChain.AddChainAtLast(10);

    cout<<endl<<"6. 전체 노드 출력 : ";
    for(iter = intChain.begin(); iter != intChain.end(); iter++)
    {
        cout<<*iter<<" ";
    }
    cout<<endl;

    cout<<endl<<"7. Front : "<<intChain.Front().getData()<<endl;

    cout<<endl<<"8. Back : "<<intChain.Back().getData()<<endl;

    cout<<endl<<"9. Get(2) : "<<intChain.Get(2).getData()<<endl;

    cout<<endl<<"10. 맨 앞에 있는 0을 삭제함"<<endl;
    intChain.DeleteChainAtFirst();

    cout<<endl<<"11. 전체 노드 출력 : ";
    for(iter = intChain.begin(); iter != intChain.end(); iter++)
    {
        cout<<*iter<<" ";
    }
    cout<<endl;
    
    cout<<endl<<"12. 맨 뒤에 있는 10을 삭제함"<<endl;
    intChain.DeleteChainAtLast();

    cout<<endl<<"13. 전체 노드 출력 : ";
    for(iter = intChain.begin(); iter != intChain.end(); iter++)
    {
        cout<<*iter<<" ";
    }
    cout<<endl;

    cout<<endl<<"14. 2번째 원소 뒤에 100 삽입"<<endl;
    intChain.AddChainAtBackofi(2, 100);

    cout<<endl<<"15. 전체 노드 출력 : ";
    for(iter = intChain.begin(); iter != intChain.end(); iter++)
    {
        cout<<*iter<<" ";
    }
    cout<<endl;

    cout<<endl<<"16. 6번째 원소 삭제"<<endl;
    intChain.DeleteChainAti(6);

    cout<<endl<<"17. 전체 노드 출력 : ";
    for(iter = intChain.begin(); iter != intChain.end(); iter++)
    {
        cout<<*iter<<" ";
    }
    cout<<endl;

    cout<<endl<<"프로그램 종료"<<endl;
    return 0;
}