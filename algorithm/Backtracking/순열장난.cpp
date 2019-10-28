#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <stack>
#include <string>
#include <utility>
#include <cmath>
#include <map>
using namespace std;
// baekjoon

int check[51];
int n;
vector<int> v;
string s;
bool finish;

bool check2()
{
	for (int i = 1; i <= n; i++)
	{
		if (check[i] == 0)
			return false;
	}
	return true;
}

void backtracking(int a)
{
	if (a >= s.length())
	{
		if (check2())
		{
			for (int i = 0; i < v.size(); i++)
				cout << v[i] << " ";
			finish = true;
		}
		return;
	}

	string s1 = s.substr(a, 1);
	int a1 = stoi(s1);
	string s2 = s.substr(a, 2);
	int a2 = stoi(s2);

	if (check[a1] == 0 && a1 != 0 && a1 <= n)
	{
		v.push_back(a1);
		check[a1] = 1;
		backtracking(a + 1);
		if (finish)
			return;
		v.pop_back();
		check[a1] = 0;
	}
	if (check[a2] == 0 && a2 != 0 && a1 <= n)
	{
		v.push_back(a2);
		check[a2] = 1;
		backtracking(a + 2);
		if (finish)
			return;
		v.pop_back();
		check[a2] = 0;
	}
}

int main()
{
	cin >> s;
	n = 0;
	finish = false;

	for (int i = 0; i < s.length();)
	{
		++n;
		if (n < 10)
			i++;
		else
			i += 2;
	}

	backtracking(0);
	
	return 0;
}