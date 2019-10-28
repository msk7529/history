#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <stack>
#include <utility>
#define MAX 123456789
using namespace std;
// baekjoon

int N, M;
int arr[101][101];
int visit[101][101];
int dp[101][101];
int point[4][2] = { {-1,0}, {1,0}, {0, -1}, {0,1} };

bool check(int a, int b)
{
	if (a < 0 || a >= N || b < 0 || b >= M || arr[a][b] == 0 || visit[a][b] == 1)
		return false;
	return true;
}

int dfs(int a, int b)
{
	if (a == N - 1 && b == M - 1)
		return 1;

	int& ret = dp[a][b];
	if (ret != -1)
		return ret;

	ret = MAX;
	visit[a][b] = 1;

	for (int i = 0; i < 4; i++)
	{
		if (check(a + point[i][0], b + point[i][1]))
		{
			//visit[a + point[i][0]][b + point[i][1]] = 1;
			ret = min(ret, 1 + dfs(a + point[i][0], b + point[i][1]));
			//visit[a + point[i][0]][b + point[i][1]] = 0;
		}
	}
	visit[a][b] = 0;

	return ret;
}


int main()
{
	//std::ios::sync_with_stdio(false);
	memset(visit, 0, sizeof(visit));
	memset(arr, 0, sizeof(arr));
	memset(dp, -1, sizeof(dp));

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			scanf("%1d", &arr[i][j]);
	}

	cout << dfs(0, 0) << endl;

	return 0;
}