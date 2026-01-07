#include <bits/stdc++.h>
using namespace std;

const int toLower = 'a' - 'A';

int N;
char B;
string S;

int main()
{
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> B;
	cin >> S;

	sort(S.begin(), S.end()); // 일단 사전 순으로 정렬
	
	if (S[0] == B)	// 맨 앞이 폭탄이면 쉴드 1개를 (있다면) 그 뒤로 배치
	{
		size_t shieldIdx = S.find(B + toLower);
		if (shieldIdx != string::npos)
		{
			size_t bombEnd = S.find_last_of(B) + 1;
			S.erase(shieldIdx, 1);
			S.insert(S.begin() + bombEnd, B + toLower);
		}
	}
	else			// 아니면 폭탄을 두 쉴드 사이에 끼워넣거나 쉴드가 1개 이하라면 뒤쪽으로 뺌
	{
		size_t bombStart = S.find_first_of(B);
		size_t bombEnd = S.find_last_of(B) + 1;
		S.erase(S.begin() + bombStart, S.begin() + bombEnd);

		size_t shieldStart = S.find_first_of(B + toLower);
		size_t shieldEnd = S.find_last_of(B + toLower) + 1;
		int shieldCount = shieldStart == string::npos ? 0 : (shieldEnd - shieldStart);
		if (shieldCount >= 2)
		{
			S.insert(S.begin() + shieldStart + 1, bombEnd - bombStart, B);
		}
		else
		{
			if (shieldCount == 1)
			{
				S.erase(shieldStart, 1);
				S.push_back(B + toLower);
			}
			S.append(bombEnd - bombStart, B);
		}
	}

	cout << S;
	return 0;
}