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

int N;
string s;
bool finish;
char num[3] = { '1','2','3' };

bool check(string str)
{
	int size = str.length();
	int end = size - 1;
	int cnt = 1;

	while (size >= cnt * 2)
	{
		if (str.substr(end - cnt + 1, cnt) == str.substr(end - cnt - cnt + 1, cnt))
			return false;
		cnt++;
	}
	return true;
}

void solve(int a)
{
	if (a == N)
	{
		cout << s << endl;
		finish = true;
		return;
	}

	for (int i = 0; i < 3; i++)
	{
		if (finish)
			return;

		string tmp = s;
		if (check(s + num[i]))
		{
			s += num[i];
			solve(a + 1);
			s = tmp;
		}
	}

}

int main()
{
	cin >> N;
	s = "";
	finish = false;

	solve(0);

	return 0;
}