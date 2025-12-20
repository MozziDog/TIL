#include <bits/stdc++.h>
using namespace std;

typedef struct n {
	string str;
	vector<struct n*> children;

	n *getChild(string str)
	{
		for (auto c : children)
		{
			if (c->str.compare(str) == 0)
				return c;
		}
		return nullptr;
	}

	struct n *addChild(string str)
	{
		struct n* newNode = new struct n();
		newNode->str = str;
		children.push_back(newNode);
		return newNode;
	}

	void sortChild()
	{
		sort(children.begin(), children.end(), [](struct n *a, struct n *b) {
			return (a->str.compare(b->str)) < 0;
			});
	}
}node;

node* root;

void insert(string str)
{
	node* curNode = root;
	auto first = str.begin();
	auto second = first;
	while(true)
	{
		second = find(first + 1, str.end(), '\\');

		string substr = string(first, second);
		auto childNode = curNode->getChild(substr);
		if (!childNode)
			childNode = curNode->addChild(substr);
		curNode = childNode;

		if (second != str.end())
			first = second + 1;
		else break;
	}
}

void print(node *n, int depth)
{
	for (int i = 0; i < depth; i++)
		cout << ' ';
	cout << n->str << '\n';
	n->sortChild();
	for (node *c : n->children)
		print(c, depth+1);
}

int N;

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	root = new node();
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string in;
		cin >> in;
		insert(in);
	}

	root->sortChild();
	for(auto c : root->children)
		print(c, 0);

	return 0;
}