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

int T, M, N, K, X, Y;
int arr[51][51];
int visit[51][51];
int point[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };

int dfs(int a, int b)
{
	visit[a][b] = 1;
	for (int i = 0; i < 4; i++)
	{
		int y = a + point[i][0];
		int x = b + point[i][1];

		if (y >= 0 && y < N && x >= 0 && x < M && visit[y][x] == 0 && arr[y][x] == 1)
			dfs(y, x);
	}
	return 1;
}

int main()
{
	cin >> T;
	while (T--)
	{
		int result = 0;
		memset(arr, 0, sizeof(arr));
		memset(visit, 0, sizeof(visit));
		cin >> M >> N >> K;
		while (K--)
		{
			cin >> X >> Y;
			arr[Y][X] = 1;
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (visit[i][j] == 0 && arr[i][j] == 1)
					result += dfs(i, j);
			}
		}
		cout << result << endl;
	}
	return 0;
}