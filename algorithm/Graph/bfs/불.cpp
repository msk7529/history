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

int T, h, w;
int visit[1001][1001];
int dst[1001][1001];
char arr[1001][1001];
int point[4][2] = { { 1,0 },{ -1,0 },{ 0,1 },{ 0,-1 } };
queue<pair<int, int>> q;
queue<pair<int, int>> fire;

void spreadFire()
{
	int size = fire.size();
	while (size--)
	{
		int y = fire.front().first, x = fire.front().second;
		visit[y][x] = 1;
		fire.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = y + point[i][0], nx = x + point[i][1];
			if (ny >= 0 && ny < h && nx >= 0 && nx < w && arr[ny][nx] != '*' && arr[ny][nx] != '#')
			{
				visit[ny][nx] = 1;
				arr[ny][nx] = '*';
				fire.push({ ny,nx });
			}
		}
	}
}

int bfs()
{
	dst[q.front().first][q.front().second] = 1;
	visit[q.front().first][q.front().second] = 1;
	while (!q.empty())
	{
		spreadFire();
		int size = q.size();
		while (size--)
		{
			int y = q.front().first, x = q.front().second;
			q.pop();

			if (y == 0 || y == h - 1 || x == 0 || x == w - 1)
				return dst[y][x];

			for (int i = 0; i < 4; i++)
			{
				int ny = y + point[i][0], nx = x + point[i][1];
				if (ny >= 0 && ny < h && nx >= 0 && nx < w && visit[ny][nx] == 0 && arr[ny][nx] == '.')
				{
					visit[ny][nx] = 1;
					dst[ny][nx] = dst[y][x] + 1;
					q.push({ ny,nx });
				}
			}
		}
	}
	return -1;
}


int main()
{
	cin >> T;
	while (T--)
	{
		while (!q.empty())
			q.pop();
		while (!fire.empty())
			fire.pop();
		memset(arr, ' ', sizeof(arr));
		memset(dst, 0, sizeof(dst));
		memset(visit, 0, sizeof(visit));
		cin >> w >> h;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> arr[i][j];
				if (arr[i][j] == '@')
					q.push({ i,j });
				else if (arr[i][j] == '*')
					fire.push({ i,j });
			}
		}

		if (q.front().first == 0 || q.front().second == 0 || q.front().first == h - 1 || q.front().second == w - 1)
		{
			cout << "1" << endl;
			continue;
		}

		int ret = bfs();
		if (ret == -1)
			cout << "IMPOSSIBLE" << endl;
		else
			cout << ret << endl;
	}
	return 0;
}