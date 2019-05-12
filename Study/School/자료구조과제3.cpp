#include<iostream>
using namespace std;

template <class T>
class Chain; // forward declaration

template <class T>
class ChainNode
{
    friend class Chain<T>;

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
        ChainNode<T> *toDelete, *i;
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
        ChainNode<T> *i = first;
        for (i; i->link != 0; i = i->link)
        {
        } //find last node
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
    void AddChainAtFrontofi(int i, T newNodeData)
    {
        ChainNode<T> *tmp = first;
        for (int j; j < i - 1; j++)
        {
            tmp = tmp->link;
        }
        ChainNode<T> *newNode = new ChainNode<T>;
        newNode->data = newNodeData;
        newNode->link = tmp->link;
        tmp->link = newNode;
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
    class ChainIterator
    {
    public:
        // typedefs required by C++ for a forward iterator omitted

        // constructor
        ChainIterator(ChainNode<T> *startNode = 0)
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
    for(int i=1; i<10; i++)
    {
        intChain.AddChainAtLast(i);
    }
    Chain<int>::ChainIterator iter=intChain.begin();
    for(iter; iter==intChain.end(); iter++)
    {
        cout<<*iter;
    }
    intChain.AddChainAtFirst(0);
    for(iter = intChain.begin(); iter == intChain.end(); iter++)
    {
        cout<<*iter;
    }

    return 0;
}