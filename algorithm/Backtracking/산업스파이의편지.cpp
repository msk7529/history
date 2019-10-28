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

int c;
int sosu[10000000];
int visit2[10000000];
int num[10];
string str;
int len;
int cnt;

void primeNumberSieve()
{
	for (int i = 2; i < 10000000; i++)
		sosu[i] = i;
	for (int i = 2; i < 10000000; i++)
	{
		if (sosu[i] == 0)
			continue;
		for (int j = i + i; j < 10000000; j += i)
			sosu[j] = 0;
	}
}

void backtracking(string s)
{
	if (s.length() == len)
		return;

	for (int j = 0; j < len; j++)
	{
		if (num[str[j]-48] == 0)
			continue;

		string next = s + str[j];
		num[str[j] - 48]--;

		int inext = stoi(next);

		if (sosu[inext] && visit2[inext] == 0)
		{
			visit2[inext] = 1;
			cnt++;
		}
		backtracking(next);
		num[str[j] - 48]++;
	}
}

int main()
{
	ios::sync_with_stdio(false);

	cin >> c;
	primeNumberSieve();
	while (c--)
	{
		memset(visit2, 0, sizeof(visit2));
		memset(num, 0, sizeof(num));
		cnt = 0;
		cin >> str;
		for (int i = 0; i < str.length(); i++)
			num[str[i]-48] ++;
		len = str.length();
		backtracking("");
		cout << cnt << endl;
	}
	return 0;
}