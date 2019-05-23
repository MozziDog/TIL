//백준 9375번
//패션왕 신해빈

//아니 뭐가 틀렸다는 거지
//완전 정확하게 작동하는데 
//흠 어딘가 놓친 곳이 있나

#include <iostream>
#include <cstring>
#define ITEM_LENGTH 15
#define CATEGORY_LENGTH 10

class Item
{
public:
    char *category;
    int quantity;
    Item()
    {
        category = new char[CATEGORY_LENGTH];
        quantity = 0;
    }
};

class Closet
{
public:
    Item items[30];
    void push(char *category)
    {
        for (int i = 0; i < 30; i++)
        {
            if (items[i].quantity == 0)
            {
                items[i].quantity += 1;
                strcpy(items[i].category, category);
                return;
            }
            if (strcmp(items[i].category, category) == 0)
            {
                items[i].quantity += 1;
                return;
            }
        }
    }
    void flush() {
        for(int i=0; i<30; i++)
        {
            delete items[i].category;
            items[i].category = new char[CATEGORY_LENGTH];
            items[i].quantity = 0;
        }
    }
};

int main()
{
    Closet *closet = new Closet();
    int numOfTestCase;
    scanf("%d", &numOfTestCase);
    for (int testCase = 0; testCase < numOfTestCase; testCase++)
    {
        closet->flush();
        int numOfItem;
        scanf("%d", &numOfItem);
        for (int itemIdx = 0; itemIdx < numOfItem; itemIdx++)
        {
            char *tmp;
            scanf("%s", tmp);
            char *cat = new char[CATEGORY_LENGTH];
            scanf("%s", cat);
            closet->push(cat);
        }
        int answer = 1;
        for(int i=0; i<30; i++)
        {
            answer *= (closet->items[i].quantity+1);
        }
        printf("%d", answer-1);
    }
}