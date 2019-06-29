//백준 1991번 문제
//트리 순회
//전위 중위 후위 순회 전부 출력하기

//으어어
//정작 트리 구조 만들기나 순회 코드 구성보단
//입력 버퍼 문제 때문에 시간을 많이 썼네

#include <iostream>

class treeNode{
    public:
        char alphabet;
        treeNode* left;
        treeNode* right;

        treeNode(char chara) {alphabet = chara;}

        treeNode* addtoLeft(char chara){
            if(chara == '.')
            {
                left = NULL;
                return NULL;
            }
            left = new treeNode(chara);
            return left;
        }
        treeNode* addtoRight(char chara){
            if(chara == '.')
            {
                right = NULL;
                return NULL;
            }
            right = new treeNode(chara);
            return right;
        }
};

void preorder(treeNode* node){
    if(node == NULL)
        return;
    printf("%c", node->alphabet);
    preorder(node->left);
    preorder(node->right);
}

void inorder(treeNode* node){
    if(node == NULL)
        return;
    inorder(node->left);
    printf("%c", node->alphabet);
    inorder(node->right);
}

void postorder(treeNode* node){
    if(node == NULL)
        return;
    postorder(node->left);
    postorder(node->right);
    printf("%c", node->alphabet);
}

int main()
{
    treeNode* Nodes[26];
    Nodes[0] = new treeNode('A');
    int numOfNode;
    scanf("%d\n", &numOfNode);
    //입력받는 for문
    char parentNode, leftNode, rightNode;
    for(int i=0; i<numOfNode; i++) {
        scanf("%c ", &parentNode);
        scanf("%c ", &leftNode);
        Nodes[leftNode-'A'] = Nodes[parentNode-'A']->addtoLeft(leftNode);
        scanf("%c", &rightNode);
        Nodes[rightNode-'A'] = Nodes[parentNode-'A']->addtoRight(rightNode);
        if(i==numOfNode-1)
            break;
        scanf("\n");
    }
    preorder(Nodes[0]);
    printf("\n");
    inorder(Nodes[0]);
    printf("\n");
    postorder(Nodes[0]);
    return 0;
}