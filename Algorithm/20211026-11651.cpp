// https://www.acmicpc.net/problem/11651

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define index int

// === 선언부 ===
int main();
template <typename T> void QuickSort(vector<T>&, index, index);
int compare(pair<int, int> a, pair<int, int> b);




// === 구현부 ===
int main()
{
    int n;
    vector<pair<int ,int>> points;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        pair<int, int> tmp;
        scanf_s("%d %d", &tmp.first, &tmp.second);
        points.push_back(tmp);
    }

    // stl의 도움을 받지 않고 Quicksort
    QuickSort<pair<int,int>>(points, 0, points.size()-1);

    // 정렬 완료. 출력
    for (int i = 0; i < n; i++)
    {
        printf("%d %d\n", points[i].first, points[i].second);
    }
    return 0;
}

// T == pair<int,int>
template <typename T>
void QuickSort(vector<T>& data, index start, index end)
{
    if (start >= end)
    {
        return;
    }

    index pivot = start;
    index i = pivot + 1;
    index j = end;

    while (i <= j)
    {
        while (i <= end && compare(data[i], data[pivot]) <= 0)
        {
            i++;
        }
        while (j > start && compare(data[j], data[pivot]) >= 0)
        {
            j--;
        }
        if (i > j)
        {
            swap(data[pivot], data[j]);
        }
        else
        {
            swap(data[i], data[j]);
        }
    }

    QuickSort(data, start, j - 1);
    QuickSort(data, j + 1, end);
}

int compare(pair<int, int> a, pair<int, int> b)
{
    if (a.second != b.second)
    {
        return a.second - b.second;
    }
    else
    {
        return a.first - b.first;
    }
}

