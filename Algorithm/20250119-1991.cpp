// 백준 1991번: 트리 순회
#include <bits/stdc++.h>
using namespace std;

int N;
int child[26][2];

void preorder(int node)
{
	if (node == '.' - 'A') return;
	cout << (char)(node + 'A');
	preorder(child[node][0]);
	preorder(child[node][1]);
}

void inorder(int node)
{
	if (node == '.' - 'A') return;
	inorder(child[node][0]);
	cout << (char)(node + 'A');
	inorder(child[node][1]);
}

void postorder(int node)
{
	if (node == '.' - 'A') return;
	postorder(child[node][0]);
	postorder(child[node][1]);
	cout << (char)(node + 'A');
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		char p, l, r;
		cin >> p >> l >> r;
		child[p - 'A'][0] = l - 'A';
		child[p - 'A'][1] = r - 'A';
	}

	preorder(0);
	cout << '\n';
	inorder(0);
	cout << '\n';
	postorder(0);

	return 0;
}