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
        ChainNode<T>* toDelete, i;
        while(true)
        {
            toDelete = i;
            i = i->link;
            delete toDelete;
            if(i==nullptr)
                break;
        }
    }
    void AddChainAtFirst(T newNodeData)
    {
        ChainNode<T>* tmp=first;
        first=new ChainNode<T>;
        first->data=newNodeData;
        first->link=tmp;
    }
    void AddChainAtLast(T newNodeData)
    {
        ChainNode<T>* i=first;
        for(i; i->link != 0; i=i->link){}//find last node
        i->link = new ChainNode<T>;
        i->link->link=0;
        i->link->data=newNodeData;
    }
    ChainNode<T> Front()
    {
        return *first;
    }
    ChainNode<T> Back()
    {
        ChainNode<T>* i=first;
        for(i; i->link!=0; i=i->link){} //find last node
        return *i;
    }
    ChainNode<T> Get(int i)
    {
        ChainNode<T>* tmp=first;
        for(int j=0; j<i; j++)
        {
            tmp=tmp->link;
        }
        return *tmp;
    }
    void DeleteChainAtFirst()
    {
        ChainNode<T>* tmp = first->link;
        delete first;
        first = tmp;
    }
    void DeleteChainAtLast()
    {
        ChainNode<T>* i = first;
        for(i; i->link->link!=0; i=i->link){}//find node before last
        delete i->link;
        i->link = nullptr;
    }
    
private:
    ChainNode<T> *first;
};
