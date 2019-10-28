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

int N;
int visit[101][101];
char arr[101][101];
int point[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };

int dfs(int x, int y)
{
	visit[x][y] = 1;
	int ret = 1;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + point[i][0];
		int ny = y + point[i][1];
		if (nx >= 0 && ny >= 0 && nx < N && ny < N && visit[nx][ny] == 0 && arr[nx][ny] == 0)
			ret += dfs(nx, ny);
	}
	return ret;
}

void dfs(int y, int x, char c)
{
	visit[y][x] = 1;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + point[i][0];
		int nx = x + point[i][1];
		if (ny >= 0 && nx >= 0 && ny < N && nx < N && visit[ny][nx] == 0 && arr[ny][nx] == c)
			dfs(ny, nx, c);
	}
}

void dfs2(int y, int x)
{
	visit[y][x] = 1;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + point[i][0];
		int nx = x + point[i][1];
		if (ny >= 0 && nx >= 0 && ny < N && nx < N && visit[ny][nx] == 0 && (arr[ny][nx] == 'R' || arr[ny][nx] == 'G'))
			dfs2(ny, nx);
	}
}


int main()
{
	memset(visit, 0, sizeof(visit));
	cin >> N;
	string s;
	for (int i = 0; i < N; i++)
	{
		cin >> s;
		for (int j = 0; j < N; j++)
			arr[i][j] = s[j];
	}

	int ret1 = 0, ret2 = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (visit[i][j] == 0)
			{
				dfs(i, j, arr[i][j]);
				ret1++;
			}
		}
	}

	memset(visit, 0, sizeof(visit));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (visit[i][j] == 0 && (arr[i][j] == 'R' || arr[i][j] == 'G'))
			{
				dfs2(i, j);
				ret2++;
			}
			else if (visit[i][j] == 0 && arr[i][j] == 'B')
			{
				dfs(i, j, 'B');
				ret2++;
			}
		}
	}
	cout << ret1 << " " << ret2 << endl;

	return 0;
}