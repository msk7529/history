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

int arr[101][101];
int visit[101][101];
int dst[101][101];
int point[4][2] = { {0,1},{0,-1}, {1,0}, {-1,0} };
queue<pair<int,int>> q;
int N, M;

bool check(pair<int, int> p)
{
	if (p.first >= 1 && p.first <= N && p.second >= 1 && p.second <= M)
		return true;
	return false;
}

int bfs()
{
	visit[1][1] = 1;
	dst[1][1] = 1;
	q.push({ 1,1 });
	while (!q.empty())
	{
		pair<int, int> p = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			pair<int, int> next;
			next.first = p.first + point[i][0], next.second = p.second + point[i][1];
			if (check(next) && arr[next.first][next.second] == 1 && visit[next.first][next.second] == 0 && dst[next.first][next.second] == 0)
			{
				dst[next.first][next.second] =  dst[p.first][p.second] + 1;
				visit[next.first][next.second] = 1;
				q.push(next);
			}
		}
	}
	return dst[N][M];
}

int main()
{
	memset(dst, 0, sizeof(dst));
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