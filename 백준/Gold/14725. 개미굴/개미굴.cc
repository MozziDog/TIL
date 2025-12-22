#include <bits/stdc++.h>
using namespace std;

class node {
public:
	string str;
	vector<node*> children;

	node* getChild(string str)
	{
		for (auto c : children)
		{
			if (c->str.compare(str) == 0)
				return c;
		}
		return nullptr;
	}

	node* addChild(string str)
	{
		node* child = new node();
		child->str = str;
		children.push_back(child);
		return child;
	}

	void print(int depth)
	{
		for (int i = 0; i < depth; i++)
			cout << "--";
		if(depth >= 0)
			cout << str << '\n';
		sort(children.begin(), children.end(), [](node* a, node* b) {
			return (a->str.compare(b->str) < 0);
			});
		for (node* c : children)
			c->print(depth + 1);
	}
};

node* root;

int N;

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	root = new node();

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int K; node* cur = root;
		cin >> K;
		for (int j = 0; j < K; j++)
		{
			string str;
			cin >> str;
			node* child = cur->getChild(str);
			if (child == nullptr)
				child = cur->addChild(str);
			cur = child;
		}
	}

	root->print(-1);
	return 0;
}