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

int L, C;
char arr[16];

int jaum(string s)
{
	int cnt = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] != 'a' && s[i] != 'e' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u')
			cnt++;
		if (cnt == 2)
			break;
	}
	return cnt;
}

int vowel(string s)
{
	int cnt = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
			cnt++;
		if (cnt == 1)
			break;
	}
	return cnt;
}

void dfs(string s, int a)
{
	if (s.length() == L)
	{
		if (jaum(s) >= 2 && vowel(s) >= 1)
			cout << s << endl;
		return;
	}
	if (a >= C)
		return;

	dfs(s + arr[a], a + 1);
	dfs(s, a + 1);
}

int main()
{
	cin >> L >> C;
	for (int i = 0; i < C; i++)
		cin >> arr[i];
	sort(&arr[0], &arr[C]);

	dfs("", 0);

	return 0;
}