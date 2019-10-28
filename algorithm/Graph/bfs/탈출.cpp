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

char arr[51][51];
int visit[51][51];
int point[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };
queue<pair<int, int>> q;
queue<pair<int, int>> water;
int R, C;
pair<int, int> D;

void spreadWater()
{
	int wsize = water.size();
	while (wsize--)
	{
		int y = water.front().first, x = water.front().second;
		water.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = y + point[i][0], nx = x + point[i][1];
			if (ny >= 0 && ny < R && nx >= 0 && nx < C && (arr[ny][nx] == '.' || arr[ny][nx] == 'S'))
			{
				arr[ny][nx] = '*';
				water.push({ ny,nx });
			}
		}
	}
}

int bfs()
{
	while (!q.empty())
	{
		int qsize = q.size();
		spreadWater();
		while (qsize--)
		{
			if (q.front() == D)
				return visit[D.first][D.second];

			int y = q.front().first, x = q.front().second;
			q.pop();

			for (int i = 0; i < 4; i++)
			{
				int ny = y + point[i][0], nx = x + point[i][1];
				if (ny >= 0 && ny < R && nx >= 0 && nx < C && visit[ny][nx] == 0 && (arr[ny][nx] == '.' || arr[ny][nx] == 'D'))
				{
					visit[ny][nx] = visit[y][x] + 1;
					q.push({ ny,nx });
				}
			}
		}
	}
	return -1;
}

int main()
{
	memset(visit, 0, sizeof(visit));
	cin >> R >> C;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 'D')
				D = { i,j };
			else if (arr[i][j] == 'S')
				q.push({ i,j });
			else if (arr[i][j] == '*')
				water.push({ i,j });
		}
	}
	int ret = bfs();
	if (ret == -1)
		cout << "KAKTUS" << endl;
	else
		cout << ret << endl;

	return 0;
}