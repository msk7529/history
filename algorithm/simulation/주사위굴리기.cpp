#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <deque>
#include <algorithm>
#include <queue>
#include <functional>
#include <utility>
#include <list>
#define MAX 987654321
using namespace std;
typedef unsigned long long ul;
// baekjoon

int N, M, x, y, K, order;
int arr[21][21];
int dice[6] = { 0,0,0,0,0,0 };
int tmp_dice[6];

int main()
{
	ios::sync_with_stdio(false);

	cin >> N >> M >> x >> y >> K;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cin >> arr[i][j];
	}

	while (K--)
	{
		cin >> order;
		for (int i = 0; i < 6; i++)
			tmp_dice[i] = dice[i];
		if (order == 1)
		{
			int nx = x, ny = y + 1;
			if (ny < 0 || ny >= M || nx < 0 || nx >= N)
				continue;

			y = ny, x = nx;
			dice[0] = tmp_dice[1], dice[1] = tmp_dice[5], dice[2] = tmp_dice[0], dice[5] = tmp_dice[2];
			if (arr[nx][ny] == 0)
				arr[nx][ny] = dice[0];
			else
			{
				dice[0] = arr[nx][ny];
				arr[nx][ny] = 0;
			}
			cout << dice[5] << " ";
		}
		else if (order == 2)
		{
			int nx = x, ny = y - 1;
			if (ny < 0 || ny >= M || nx < 0 || nx >= N)
				continue;

			y = ny, x = nx;
			dice[0] = tmp_dice[2], dice[1] = tmp_dice[0], dice[2] = tmp_dice[5], dice[5] = tmp_dice[1];
			if (arr[nx][ny] == 0)
				arr[nx][ny] = dice[0];
			else
			{
				dice[0] = arr[nx][ny];
				arr[nx][ny] = 0;
			}
			cout << dice[5] << " ";
		}
		else if (order == 3)
		{
			int nx = x - 1, ny = y;
			if (ny < 0 || ny >= M || nx < 0 || nx >= N)
				continue;

			y = ny, x = nx;
			dice[0] = tmp_dice[4], dice[3] = tmp_dice[0], dice[4] = tmp_dice[5], dice[5] = tmp_dice[3];
			if (arr[nx][ny] == 0)
				arr[nx][ny] = dice[0];
			else
			{
				dice[0] = arr[nx][ny];
				arr[nx][ny] = 0;
			}
			cout << dice[5] << " ";
		}
		else if (order == 4)
		{
			int nx = x + 1, ny = y;
			if (ny < 0 || ny >= M || nx < 0 || nx >= N)
				continue;

			y = ny, x = nx;
			dice[0] = tmp_dice[3], dice[3] = tmp_dice[5], dice[4] = tmp_dice[0], dice[5] = tmp_dice[4];
			if (arr[nx][ny] == 0)
				arr[nx][ny] = dice[0];
			else
			{
				dice[0] = arr[nx][ny];
				arr[nx][ny] = 0;
			}
			cout << dice[5] << " ";
		}
	}
	return 0;
}