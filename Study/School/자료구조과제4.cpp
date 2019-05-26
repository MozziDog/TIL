#include <iostream>

template <class K, class E>
class pair
{
public:
    K first;
    E second;
    pair(K first, E second)
    {
        this->first = first;
        this->second = second;
    }
    pair() {}
};

template <class K, class E>
class BST; // forward declaration

template <class K, class E>
class TreeNode
{
    friend class BST<K, E>;

public:
    TreeNode(const pair<K, E> p)
    {
        data.first = p.first;
        data.second = p.second;
        leftChild = 0;
        rightChild = 0;
    }

private:
    pair<K, E> data;
    TreeNode<K, E> *leftChild;
    TreeNode<K, E> *rightChild;
};

template <class K, class E>
class BST
{
public:
    BST();
    bool IsEmpty() const;
    // return true iff the dictionary is empty
    pair<K, E> *Get(const K &) const;
    pair<K, E> *Get(TreeNode<K, E> *, const K &) const;
    // return pointer to the pair with specified key; return 0 if no such pair
    void Insert(const pair<K, E> &);
    // insert the given pair; if key is a duplicate update associated element
    void Delete(const K &);
    void Delete(TreeNode<K, E> *, TreeNode<K, E> *);
    // delete pair with specified key
    void Inorder();
    void Inorder(TreeNode<K, E> *);
    // Inorder traversal
    void Visit(TreeNode<K, E> *);

private:
    TreeNode<K, E> *root;
};

template <class K, class E>
BST<K, E>::BST()
{
    root = 0;
}

template <class K, class E>
bool BST<K, E>::IsEmpty() const
{
    if (root)
        return false;
    return true;
}

template <class K, class E> // Driver
pair<K, E> *BST<K, E>::Get(const K &k) const
{ // Search the binary search tree (*this) for a pair with key k.
    // If such a pair is found, return a pointer to this pair; otherwise, return 0.
    return Get(root, k);
}

template <class K, class E> // Workhorse
pair<K, E> *BST<K, E>::Get(TreeNode<K, E> *p, const K &k) const
{
    if (!p)
        return 0;
    if (k < p->data.first)
        return Get(p->leftChild, k);
    if (k > p->data.first)
        return Get(p->rightChild, k);
    return &p->data;
}

template <class K, class E>
void BST<K, E>::Insert(const pair<K, E> &thePair)
{ // Insert thePair into the binary search tree.
    // search for thePair.first, pp is parent of p
    TreeNode<K, E> *p = root, *pp = 0;
    while (p)
    {
        pp = p;
        if (thePair.first < p->data.first)
            p = p->leftChild;
        else if (thePair.first > p->data.first)
            p = p->rightChild;
        else //  duplicate, update associated element
        {
            p->data.second = thePair.second;
            return;
        }
    }

    // perform insertion
    p = new TreeNode<K, E>(thePair);
    if (root) // tree not empty
        if (thePair.first < pp->data.first)
            pp->leftChild = p;
        else
            pp->rightChild = p;
    else
        root = p;
}

template <class K, class E>
void BST<K, E>::Delete(const K &k)
{
    TreeNode<K, E> *p = root, *pp = 0;
    while (p)
    {
        if (k < p->data.first)
        {
            pp = p;
            printf("p->leftChild\n", k);
            p = p->leftChild;
        }
        else if (k > p->data.first)
        {
            pp = p;
            printf("set parent's leftChild 0");
            p = p->rightChild;
        }
        else
        {
            // perform delete
            if (root) // tree not empty
            {
                printf("Delete : %d, %d\n", p->data.first, pp->data.first);
                Delete(p, pp);
            }
            else
                break;
            return;
        }
    }
    std::cout << "삭제 오류" << std::endl;
}

template <class K, class E>
void BST<K, E>::Delete(TreeNode<K, E> *DeleteNode, TreeNode<K, E> *ParentNode)
{
    if ((DeleteNode->leftChild) && (DeleteNode->rightChild))
    {
        printf("Delete 2-way branch node %d\n", DeleteNode->data.first);
        //find Largest element in left subTree;
        TreeNode<K, E> *p = DeleteNode->leftChild, *pp = DeleteNode;
        while (p->rightChild)
        {
            pp = p;
            p = p->rightChild;
        }
        DeleteNode->data = p->data;
        Delete(p, pp);
        return;
    }
    if (DeleteNode->leftChild)
    {
        printf("Delete left-way branch node %ed\n", DeleteNode->data.first);
        if (DeleteNode == root)
        {
            root = DeleteNode->leftChild;
            delete DeleteNode;
            return;
        }
        if (DeleteNode == ParentNode->leftChild)
            ParentNode->leftChild = DeleteNode->leftChild;
        else
            ParentNode->rightChild = DeleteNode->leftChild;
        delete DeleteNode;
        return;
    }
    if (DeleteNode->rightChild)
    {
        printf("Delete right-way branch node %ed\n", DeleteNode->data.first);
        if (DeleteNode == root)
        {
            root = DeleteNode->rightChild;
            delete DeleteNode;
            return;
        }
        if (DeleteNode == ParentNode->leftChild)
            ParentNode->leftChild = DeleteNode->rightChild;
        else
            ParentNode->rightChild = DeleteNode->rightChild;
        delete DeleteNode;
        return;
    }
    printf("Delete leaf Node %d\n", DeleteNode->data.first);
    printf("ParentNode = Ndode %d\n", ParentNode->data.first);
    if (DeleteNode->data.first < ParentNode->data.first)
    {
        ParentNode->leftChild = 0;
        printf("set parent's leftChild 0\n");
    }
    else //if(DeleteNode->data.first > ParentNode->data.first)
    {
        ParentNode->rightChild = 0;
        printf("set parent's rightChild 0\n");
    }
    delete DeleteNode;
}

template <class K, class E>
void BST<K, E>::Inorder()
{ // Driver calls workhorse for traversal of entire tree.  The driver is
    // declared as a public member function of Tree.
    Inorder(root);
}

template <class K, class E>
void BST<K, E>::Inorder(TreeNode<K, E> *currentNode)
{ // Workhorse traverses the subtree rooted at currentNode.
    // The workhorse is declared as a private member function of Tree.
    if (currentNode)
    {
        Inorder(currentNode->leftChild);
        Visit(currentNode);
        Inorder(currentNode->rightChild);
    }
}

template <class K, class E>
void BST<K, E>::Visit(TreeNode<K, E> *currentNode)
{
    std::cout << currentNode->data.second << std::endl;
}

int main()
{
    BST<int, int> *binarySearchTree = new BST<int, int>();
    binarySearchTree->Insert(pair<int, int>(8, 88));
    binarySearchTree->Insert(pair<int, int>(4, 44));
    binarySearchTree->Insert(pair<int, int>(9, 99));
    binarySearchTree->Insert(pair<int, int>(2, 22));
    binarySearchTree->Insert(pair<int, int>(1, 11));
    binarySearchTree->Insert(pair<int, int>(6, 66));
    binarySearchTree->Insert(pair<int, int>(3, 33));
    binarySearchTree->Insert(pair<int, int>(5, 55));
    binarySearchTree->Insert(pair<int, int>(7, 77));
    //1. 이원 탐색 트리의 노드는 다음과 같은 순서로 추가된다. (insert 함수 사용)
    std::cout << "노드 추가, 중위 순회 실행 :" << std::endl;
    binarySearchTree->Inorder();
    //2. 중위 순회를 수행하여 노드의 second값을 출력한다. (inorder 함수 사용)
    binarySearchTree->Delete(4);
    //3. 노드 4를 삭제한다. (delete 함수 사용)
    std::cout << "노드 4 삭제, 중위 순회 실행 :" << std::endl;
    binarySearchTree->Inorder();
    //4. 중위 순회를 수행하여 노드의 second값을 출력한다. (inorder 함수 사용)
    binarySearchTree->Delete(5);
    //5. 노드 5를 삭제한다. (delete 함수 사용)
    std::cout << "노드 5 삭제, 중위 순회 실행 :" << std::endl;
    binarySearchTree->Inorder();
    //6. 중위 순회를 수행하여 노드의 second값을 출력한다. (inorder 함수 사용)
    binarySearchTree->Delete(2);
    //7. 노드 2를 삭제한다.(delete 함수 사용)
    std::cout << "노드 2 삭제, 중위 순회 실행 :" << std::endl;
    binarySearchTree->Inorder();
    //8. 중위 순회를 수행하여 노드의 second값을 출력한다. (inorder 함수 사용)
    if (binarySearchTree->Get(2))
    {
        std::cout << std::endl
                  << "Get(2)의 값 :";
        std::cout << binarySearchTree->Get(2)->second << std::endl;
    }
    else
        std::cout << "노드 2가 존재하지 않음";
    //9. 노드 2가 있는지 확인하여 second 결과를 출력한다. (get 함수 사용)
    if (binarySearchTree->Get(9))
    {
        std::cout << std::endl
                  << "Get(9)의 값 :";
        std::cout << binarySearchTree->Get(9)->second << std::endl;
    }
    else
    {
        std::cout << "노드 9가 존재하지 않음";
    }

    //10. 노드 9가 있는지 확인하여 second 결과를 출력한다. (get 함수 사용)
    return 0;
}