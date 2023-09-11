// 백준 17478번: 재귀함수가 뭔가요?
// 아오 오타;;

#include <bits/stdc++.h>
using namespace std;

int N;

void rec(int i);
void print_with_tab(int tab, string s);

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> N;

	cout << "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n";
	rec(0);
	return 0;
}

void rec(int i)
{
	print_with_tab(i, "\"재귀함수가 뭔가요?\"");
	if (i == N)
	{
		print_with_tab(i, "\"재귀함수는 자기 자신을 호출하는 함수라네\"");
		print_with_tab(i, "라고 답변하였지.");
		return;
	}
	print_with_tab(i, "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.");
	print_with_tab(i, "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.");
	print_with_tab(i, "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"");
	rec(i + 1);
	print_with_tab(i, "라고 답변하였지.");
}

void print_with_tab(int tab, string s)
{
	for (int i = 0; i < tab * 4; i++)
	{
		cout << '_';
	}
	cout << s << '\n';
}