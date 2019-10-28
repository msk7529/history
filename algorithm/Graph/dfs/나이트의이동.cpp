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

int T, l;
int arr[301][301];
int visit[301][301];
int point[8][2] = { {-2,1},{2,1}, {-1,2},{1,2}, {-2,-1}, {2,-1}, {-1,-2},{1,-2} };
pair<int, int> start, fin;
queue<pair<int, int>> q;

int bfs()
{
	while (!q.empty())
	{
		int y = q.front().first, x = q.front().second;
		q.pop();
		if (y == fin.first && x == fin.second)
			return visit[y][x];

		for (int i = 0; i < 8; i++)
		{
			int ny = y + point[i][0], nx = x + point[i][1];
			if (ny >= 0 && ny < l && nx >= 0 && nx < l && visit[ny][nx] == 0)
			{
				visit[ny][nx] = visit[y][x] + 1;
				q.push({ ny,nx });
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
		memset(visit, 0, sizeof(visit));
		cin >> l >> start.first >> start.second >> fin.first >> fin.second;
		q.push(start);
		cout << bfs() << endl;
	}
	return 0;
}