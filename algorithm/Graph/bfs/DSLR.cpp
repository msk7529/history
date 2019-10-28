#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <stack>
#include <string>
#include <utility>
#include <cmath>
using namespace std;
// baekjoon

int T, A, B;
string s[10001];
int visit[10001];
queue<int> q;

int D(int num)
{
	if (num >= 5000)
		return (2 * num) % 10000;
	return 2 * num;
}

int S(int num)
{
	if (num == 0)
		return 9999;
	return num - 1;
}

int L(int num)
{
	int d1 = num / 1000, d2 = (num / 100 - 10 * d1), d3 = (num / 10 - 100 * d1 - 10 * d2), d4 = (num - 1000 * d1 - 100 * d2 - 10 * d3);
	return d2 * 1000 + d3 * 100 + d4 * 10 + d1;
}

int R(int num)
{
	int d1 = num / 1000, d2 = (num / 100 - 10 * d1), d3 = (num / 10 - 100 * d1 - 10 * d2), d4 = (num - 1000 * d1 - 100 * d2 - 10 * d3);
	return d4 * 1000 + d1 * 100 + d2 * 10 + d3;
}

string bfs()
{
	while (!q.empty())
	{
		int num = q.front();
		q.pop();

		if (num == B)
			return s[num];

		int nd = D(num), ns = S(num), nl = L(num), nr = R(num);
		if (visit[nd] == 0)
		{
			visit[nd] = 1;
			s[nd] = s[num] + "D";
			q.push(nd);
		}
		if (visit[ns] == 0)
		{
			visit[ns] = 1;
			s[ns] = s[num] + "S";
			q.push(ns);
		}
		if (visit[nl] == 0)
		{
			visit[nl] = 1;
			s[nl] = s[num] + "L";
			q.push(nl);
		}
		if (visit[nr] == 0)
		{
			visit[nr] = 1;
			s[nr] = s[num] + "R";
			q.push(nr);
		}
	}
}

int main()
{
	cin >> T;
	while (T--)
	{
		while (!q.empty())
			q.pop();
		for (int i = 0; i <= 10000; i++)
			s[i].clear();
		memset(visit, 0, sizeof(visit));
		cin >> A >> B;
		visit[A] = 1;
		q.push(A);

		string ret = bfs();
		cout << ret << endl;
	}
	return 0;
}