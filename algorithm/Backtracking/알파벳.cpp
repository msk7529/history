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

int R, C;
int point[4][2] = { {1,0},{-1,0}, {0,1}, {0,-1} };
int visit[21][21];
int used[40];
char arr[21][21];

int dfs(int y, int x)
{
	visit[y][x] = 1;
	used[arr[y][x] - 'A'] = 1;

	int ret = 1;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + point[i][0], nx = x + point[i][1];
		if (ny >= 0 && ny < R && nx >= 0 && nx < C && visit[ny][nx] == 0 && used[arr[ny][nx]-'A'] == 0)
			ret = max(ret, 1 + dfs(ny, nx));
	}

	visit[y][x] = 0;
	used[arr[y][x] - 'A'] = 0;

	return ret;
}

int main()
{
	memset(used, 0, sizeof(used));
	memset(visit, 0, sizeof(visit));
	cin >> R >> C;
	string s;
	for (int i = 0; i < R; i++)
	{
		cin >> s;
		for (int j = 0; j < C; j++)
			arr[i][j] = s[j];
	}

	cout << dfs(0, 0) << endl;

	return 0;
}