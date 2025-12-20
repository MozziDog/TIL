#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long long

class BigNum
{
private:
	string str;
public :
	BigNum(string str) : str(str) {}

	void make_double()
	{
		int carry = 0;
		for (auto it = str.rbegin(); it != str.rend(); it++)
		{
			int curNum = *it - '0';
			curNum *= 2;
			curNum += carry;
			carry = curNum / 10;
			curNum %= 10;
			*it = curNum + '0';
		}
		if (carry != 0)
		{
			str.insert(str.begin(), carry + '0');
		}
	}
	
	BigNum operator << (int p)
	{
		BigNum newNum = BigNum(str);
		for (int i = 0; i < p; i++)
			newNum.make_double();
		return newNum;
	}

	BigNum operator-- ()
	{
		auto it = str.rbegin();
		while (it != str.rend())
		{
			if (*it > '0')
			{
				*it -= 1;
				break;
			}
			else
				*it = '9';
		}
		return *this;
	}

	void print()
	{
		cout << str;
	}
};

int N;

void rec(int count, int src, int dst)
{
	if (count == 1)
	{
		cout << src << ' ' << dst << '\n';
		return;
	}
	int point = 6 - src - dst;
	rec(count - 1, src, point);
	cout << src << ' ' << dst << '\n';
	rec(count - 1, point, dst);
}

int main()
{
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	auto b = BigNum("1");
	b = b << N;
	--b;
	b.print();

	if (N <= 20)
	{
		cout << '\n';
		rec(N, 1, 3);
	}
	return 0;
}