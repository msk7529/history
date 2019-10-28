#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <functional>
#define MAX 987654321
using namespace std;
// baekjoon

int N;
int ret;
int arr[11][11];
int visit[11][11];

void backtracking(int seed, int cost)
{
	if (seed == 3)
	{
		ret = min(cost, ret);
		return;
	}

	for (int i = 1; i < N - 1; i++)
	{
		for (int j = 1; j < N - 1; j++)
		{
			if (!visit[i][j] && !visit[i - 1][j] && !visit[i + 1][j] && !visit[i][j - 1] && !visit[i][j + 1])
			{
				visit[i][j] = visit[i - 1][j] = visit[i + 1][j] = visit[i][j - 1] = visit[i][j + 1] = 1;
				backtracking(seed + 1, cost + arr[i][j] + arr[i - 1][j] + arr[i + 1][j] + arr[i][j - 1] + arr[i][j + 1]);
				visit[i][j] = visit[i - 1][j] = visit[i + 1][j] = visit[i][j - 1] = visit[i][j + 1] = 0;
			}
		}
	}
}

int main()
{
	memset(visit, 0, sizeof(visit));
	ret = MAX;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];
	}

	backtracking(0, 0);

	cout << ret << endl;

	return 0;
}