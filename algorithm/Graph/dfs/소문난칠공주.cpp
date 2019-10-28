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

char mp[5][5];
int dir[4][2] = { { -1,0 },{ 1,0 },{ 0,-1 },{ 0, 1 } };
int ans = 0;
bool c[1 << 25];

void dfs(int cnt, int s, int check)
{
	if (cnt == 7)
	{
		if (s > 3)
			++ans;
		return;
	}

	for (int i = 0; i < 25; i++)
	{
		if ((check&(1 << i)) == 0) continue;
		int y = i / 5;
		int x = i % 5;

		for (int k = 0; k < 4; k++)
		{
			int ny = y + dir[k][0];
			int nx = x + dir[k][1];
			if (ny < 0 || ny >= 5 || nx < 0 || nx >= 5) continue;
			int num = ny * 5 + nx;
			if (c[check | (1 << num)]) continue;

			c[check | (1 << num)] = true;
			if (mp[ny][nx] == 'S')
				dfs(cnt + 1, s + 1, check | (1 << (num)));
			if (mp[ny][nx] == 'Y')
				dfs(cnt + 1, s, check | (1 << (num)));
		}
	}
}

int main(void)
{
	for (int i = 0; i < 5; i++)
		cin >> mp[i];

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			c[1 << (i * 5 + j)] = true;
			dfs(1, mp[i][j] == 'S', 1 << (i * 5 + j));
		}
	}
	cout << ans << endl;
	return 0;
}