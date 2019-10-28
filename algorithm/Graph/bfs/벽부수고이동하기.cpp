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

struct st
{
	int y, x, cnt;
	st(int y, int x, int cnt)
	{
		this->y = y, this->x = x, this->cnt = cnt;
	}
};

int arr[1001][1001];
int visit[1001][1001][2];	// 마지막 값은 벽을 부쉈는지 안부쉈는지.
int point[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };
queue<st> q;
int N, M;

int bfs()
{
	visit[1][1][0] = 1;
	q.push(st(1, 1, 0));
	
	while (!q.empty())
	{
		int y = q.front().y, x = q.front().x, cnt = q.front().cnt;
		q.pop();

		if (y == N && x == M)
			return visit[y][x][cnt];

		for (int i = 0; i < 4; i++)
		{
			int ny = y + point[i][0], nx = x + point[i][1];
			if (ny >= 1 && ny <= N && nx >= 1 && nx <= M && visit[ny][nx][cnt] == 0)
			{
				if (cnt == 0 && arr[ny][nx] == 0)
				{
					visit[ny][nx][cnt] = visit[y][x][cnt] + 1;
					q.push(st(ny, nx, 0));
				}
				else if (cnt == 0 && arr[ny][nx] == 1)
				{
					visit[ny][nx][1] = visit[y][x][cnt] + 1;
					q.push(st(ny, nx, 1));
				}
				else if (cnt == 1 && arr[ny][nx] == 0)
				{
					visit[ny][nx][cnt] = visit[y][x][cnt] + 1;
					q.push(st(ny, nx, 1));
				}
			}
		}
	}
	return -1;
}

int main()
{
	memset(visit, 0, sizeof(visit));
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
			scanf("%1d", &arr[i][j]);
	}

	cout << bfs() << endl;

	return 0;
}