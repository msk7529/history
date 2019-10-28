#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
#include <utility>
#include <list>
#define MAX 987654321
using namespace std;
typedef unsigned long long ul;
// baekjoon

int N, M, r, c, d;
int arr[51][51];
int ret;
int point[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };

void count(int y, int x)	// 현재위치청소
{
	if (arr[y][x] == 0)
	{
		arr[y][x] = 2;		// 벽과 구분을 위해 반드시 1이 아닌 2로 해야함. 후진조건을 위해.
		ret++;
	}
}

int main()
{
	ios::sync_with_stdio(false);

	cin >> N >> M >> r >> c >> d;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cin >> arr[i][j];
	}

	int y = r, x = c;
	while (1)
	{
		count(y, x);

		int ny, nx;
		bool b = false;
		for (int i = 0; i < 4; i++)		// 최대 네방향 탐색
		{
			d = (d + 3) % 4;
			ny = y + point[d][0], nx = x + point[d][1];
			if (ny >= 0 && ny < N && nx >= 0 && nx < M && arr[ny][nx] == 0)
			{
				b = true;
				break;
			}
		}

		if (b)	// 한방향이라도 청소덜된 곳이 있으면 continue
		{
			y = ny, x = nx;
			continue;
		}
		else	// 모든 방향이 청소되었거나 벽인경우
		{
			ny = y - point[d][0], nx = x - point[d][1];
			if (ny < 0 || ny >= N || nx < 0 || nx >= M || arr[ny][nx] == 1)		// 뒤가 벽인경우거나 범위를 초과했을 경우 break
				break;
			else	// 뒤가 벽이아닌경우(즉, 청소된공간인경우)
			{
				y = ny, x = nx;
				continue;
			}
		}
	}
	cout << ret << endl;
	return 0;
}