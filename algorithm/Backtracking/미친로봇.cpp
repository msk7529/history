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
double prob[4];
int point[4][2] = { {0,1}, {0,-1}, {1,0}, {-1,0} }; // µ¿,¼­,³²,ºÏ
int visit[32][32];
double ret;

void backtracking(int cnt, double pro, int y, int x)
{
	if (cnt == N)
	{
		ret += pro;
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int ny = y + point[i][0], nx = x + point[i][1];
		if (visit[ny][nx] == 0 && prob[i] > 0)
		{
			visit[ny][nx] = 1;
			backtracking(cnt + 1, pro*prob[i], ny, nx);
			visit[ny][nx] = 0;
		}
	}
}

int main()
{
	memset(visit, 0, sizeof(visit));
	ret = 0.0;
	cin >> N;
	for (int i = 0; i < 4; i++)
	{
		cin >> prob[i];
		prob[i] /= 100;
	}
	visit[15][15] = 1;

	backtracking(0, 1.0, 15, 15);
	cout.precision(10);
	cout << ret << endl;

	return 0;
}