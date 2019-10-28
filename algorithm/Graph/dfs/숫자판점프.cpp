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

char arr[5][5];
int isMaked[1000000];
int point[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };
int ret;

void dfs(int y, int x, int cnt, string s)
{
	if (cnt == 6)
	{
		int num = stoi(s);
		if (isMaked[num] == 0)
		{
			isMaked[num] = 1;
			ret++;
		}
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int ny = y + point[i][0], nx = x + point[i][1];
		if (ny >= 0 && ny < 5 && nx >= 0 && nx < 5)
			dfs(ny, nx, cnt + 1, s + arr[ny][nx]);
	}
}

int main()
{
	memset(isMaked, 0, sizeof(isMaked));
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
			cin >> arr[i][j];
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			string s = "";
			dfs(i, j, 1, s + arr[i][j]);
		}
	}
	cout << ret << endl;

	return 0;
}