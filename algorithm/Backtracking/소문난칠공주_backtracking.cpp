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
int Connected[5][5];
int visit[25];
int point[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
int ret, cntt;

void isConnected(int y, int x, int checked[5][5])
{
	if (cntt == 7)
	{
		ret++;
		return;
	}
		
	for (int i = 0; i < 4; i++)
	{
		int ny = y + point[i][0], nx = x + point[i][1];
		if (ny >= 0 && ny < 5 && nx >= 0 && nx < 5)
		{
			if (Connected[ny][nx] == 1 && checked[ny][nx] == 0)
			{
				cntt++;
				checked[ny][nx] = 1;
				isConnected(ny, nx, checked);
			}
		}
	}
}

void find()
{
	for (int i = 0; i < 25; i++)
	{
		if (visit[i] == 1)		// i점에서 시작하여 연결요소들이 서로 연결되어있는지.
		{
			int y = i / 5 , x = i % 5;
			int checked[5][5];
			cntt = 1;
			memset(checked, 0, sizeof(checked));
			checked[y][x] = 1;
			isConnected(y, x, checked);
			return;
		}
	}
}

void dfs(int a, int cnt, int total)
{
	if (arr[a / 5][a % 5] == 'S')
		cnt++;

	Connected[a / 5][a % 5] = 1;
	visit[a] = 1;

	if (total == 7)
	{
		if (cnt >= 4)
			find();		// 모든 요소들이 연결되어있는지 확인
	}
	else
	{
		for (int i = a + 1; i < 25; i++)
		{
			if (visit[i] == 0)
				dfs(i, cnt, total + 1);
		}
	}

	Connected[a / 5][a % 5] = 0;
	visit[a] = 0;
}

int main()
{
	ret = 0;
	memset(Connected, 0, sizeof(Connected));
	memset(visit, 0, sizeof(visit));
	string s;
	for (int i = 0; i < 5; i++)
	{
		cin >> s;
		for (int j = 0; j < 5; j++)
			arr[i][j] = s[j];
	}

	for (int i = 0; i < 25; i++)
		dfs(i, 0, 1);

	cout << ret << endl;

	return 0;
}