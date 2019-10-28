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
vector<int> result;

int dfs(int x, int y)
{
	visit[x][y] = 1;
	int ret = 1;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + point[i][0];
		int ny = y + point[i][1];
		if (nx >= 0 && ny >= 0 && nx < N && ny < M && visit[nx][ny] == 0 && arr[nx][ny] == 0)
			ret += dfs(nx, ny);
	}
	return ret;
}


int main()
{
	memset(visit, 0, sizeof(visit));
	memset(arr, 0, sizeof(arr));
	cin >> M >> N >> K;
	int x1, x2, y1, y2;
	while (K--)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i = x1; i < x2; i++)
		{
			for (int j = y1; j < y2; j++)
				arr[i][j] = 1;
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (visit[i][j] == 0 && arr[i][j] == 0)
			{
				int ret = dfs(i, j);
				result.push_back(ret);
			}
		}
	}
	sort(result.begin(), result.end());
	cout << result.size() << endl;
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << " ";
	cout << endl << endl;
	return 0;
}