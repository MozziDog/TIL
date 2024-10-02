// Programmers 코딩테스트 연습 6일차.
// 오랜만에 그래프 다루려니까 조금 힘드네
// 그래도 원트에 클리어

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct s
{
    struct s *left;
    struct s *right;
    int idx, x, y;
} node;

vector<int> forwardResult;
vector<int> backwardResult;

void forwardTour(node *n)
{
    forwardResult.push_back(n->idx);
    if(n->left != 0)
        forwardTour(n->left);
    if(n->right != 0)
        forwardTour(n->right);
}

void backwardTour(node* n)
{
    if(n->left != 0)
        backwardTour(n->left);
    if(n->right != 0)
        backwardTour(n->right);
    backwardResult.push_back(n->idx);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    // 노드 생성
    vector<node> nodes;
    for(int i=0; i<nodeinfo.size(); i++)
    {
        nodes.push_back({0, 0, i+1, nodeinfo[i][0], nodeinfo[i][1]});
    }
    
    // y우선, 동일 y값 내에서는 x기준으로 정렬
    sort(nodes.begin(), nodes.end(), 
         [](node a, node b) { 
             if(a.y == b.y)
                 return a.x < b.x;
             else
                 return a.y > b.y;
    });
    
    // 그래프 그리기
    node *root = &(nodes[0]);
    for(int i = 1; i<nodes.size(); i++)
    {
        node *p = root;
        while(true)
        {
            if(p->left != 0 && p->left->y > nodes[i].y && nodes[i].x < p->x)
                p = p->left;
            else if(p->right != 0 && p->right->y > nodes[i].y && nodes[i].x > p->x)
                p = p->right;
            else if(p->left == 0 && nodes[i].x < p->x)
            {
                p ->left = &(nodes[i]);
                break;
            }
            else if(p->right == 0 && nodes[i].x > p->x)
            {
                p -> right = &(nodes[i]);
                break;
            }
            else
            {
                p = p + 1;
            }
        }
    }
    
    // 그래프에 삽입 다했으면 탐색
    forwardTour(root);
    backwardTour(root);
    
    vector<vector<int>> answer;
    answer.push_back(forwardResult);
    answer.push_back(backwardResult);
    
    return answer;
}