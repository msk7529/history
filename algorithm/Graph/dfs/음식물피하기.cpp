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

int N, M, K;
int visit[101][101];
int arr[101][101];
int point[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };

int dfs(int a, int b)
{
	visit[a][b] = 1;
	int ret = 1;
	for (int i = 0; i < 4; i++)
	{
		int y = a + point[i][0];
		int x = b + point[i][1];
		if (x >= 1 && y >= 1 && x <= M && y <= N && arr[y][x] == 1 && visit[y][x] == 0)
			ret += dfs(y, x);
	}

	return ret;
}

int main()
{
	memset(visit, 0, sizeof(visit));
	memset(arr, 0, sizeof(arr));
	cin >> N >> M >> K;
	int u, v;
	while (K--)
	{
		cin >> u >> v;
		arr[u][v] = 1;
	}
	int result = 0;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			if (visit[i][j] == 0 && arr[i][j] == 1)
				result = max(result, dfs(i, j));
		}
	}
	cout << result << endl;
	return 0;
}