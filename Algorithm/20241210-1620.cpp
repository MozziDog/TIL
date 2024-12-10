// 백준 1620번: 나는야 포켓몬 마스터
// unordered_map에서 key 말고 value로 검색은 안되나?
// key는 해시값으로 바뀌고, value는 그대로 들어가니까... 검색이 안될 것 같지는 않은데
// 근데 그러면 선형 탐색을 해야하니 해시 컨테이너를 사용하는 의미가 없겠구나
// 그럼 이 문제처럼 양방향으로 대응시키려면 해시 컨테이너를 두개 써야 하겠네?
// 도감번호->이름 케이스에서 굳이 해시 컨테이너를 안쓰고 배열로 썼다는 차이점이 있긴 한데 어쨋든 짖는개님도 컨테이너를 2개 써서 풀었다.
// 해시의 특성이라 단방향밖에 안되는 건 어쩔 수 없는 듯

#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    unordered_map<int, string> pokedexNum;
    unordered_map<string, int> pokedexName;
    for(int i = 1; i<=n; i++)
    {
        string pokemon;
        cin >> pokemon;
        pokedexNum.insert({i, pokemon});
        pokedexName.insert({pokemon, i});
    }

    for(int i=0; i<m; i++)
    {
        string query;
        cin >> query;
        // 숫자인지 문자열인지 파악
        auto it = query.begin();
        while(it != query.end() && *it >= '0' && *it <= '9')
            it++;
        if(it == query.end()) // 숫자
        {
            cout << pokedexNum[stoi(query)] << '\n';
        }
        else                    // 문자
        {
            cout << pokedexName[query] << '\n';
        }
    }
    return 0;
}