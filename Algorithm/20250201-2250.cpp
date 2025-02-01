// 백준 2250번: 트리의 높이와 너비
// 아 루트 노드가 1이 아닐 수 있구나
// 중위 순회가 생각이 안나서 힌트 보고 풀었음.
// 그리고서는 틀렸길래 왜틀렸지? 하다가 루트 노드가 1이 아닐 수 있다는 힌트 또 보고 풀었음.
// 이 문제는 나중에 다시 한 번 풀어봐야겠다.

#include <bits/stdc++.h>
using namespace std;

int N;
int lc[10001], rc[10001], parent[10001];
int x[10001];
int leftend[10001], rightend[10001];

int inorder(int cur, int depth, int offset)	// offset은 서브트리 전체의 offset. 서브트리의 가장 왼쪽의 좌표 -1.
{
	int sizeOfSubtree = 0;
	if (lc[cur] != -1)
		sizeOfSubtree += inorder(lc[cur], depth + 1, offset);
	sizeOfSubtree += 1;
	x[cur] = sizeOfSubtree + offset;
	if (leftend[depth] == 0 || leftend[depth] > x[cur])
		leftend[depth] = x[cur];
	if (rightend[depth] == 0 || rightend[depth] < x[cur])
		rightend[depth] = x[cur];
	if (rc[cur] != -1)
		sizeOfSubtree += inorder(rc[cur], depth + 1, sizeOfSubtree + offset);
	return sizeOfSubtree;			// 리턴 값은 cur를 루트로 삼는 서브트리의 크기
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int p, l, r;
		cin >> p >> l >> r;
		lc[p] = l;
		rc[p] = r;
		parent[l] = p;
		parent[r] = p;
	}

	// 루트 노드 찾기
	int root = 0;
	for (int i = 1; i <= N; i++)
	{
		if (parent[i] == 0)
		{
			root = i;
			break;
		}
	}

	inorder(root, 1, 0);

	int ansWidth = 0, ansDepth;
	for(int i=1; i<=N; i++)
	{
		int w = rightend[i] - leftend[i] + 1;
		if (w > ansWidth)
		{
			ansWidth = w;
			ansDepth = i;
		}
	}
	
	cout << ansDepth << ' ' << ansWidth;
	return 0;
}