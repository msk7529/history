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
int visit[26][26];
int arr[26][26];
int point[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };
vector<int> result;

int dfs(int a, int b)
{
	int ret = 1;
	visit[a][b] = 1;
	for (int i = 0; i < 4; i++)
	{
		int y = a + point[i][0];
		int x = b + point[i][1];
		if (x >= 0 && x < N && y >= 0 && y < N && visit[y][x] == 0 && arr[y][x] == 1)
			ret += dfs(y, x);
	}
	return ret;
}

int main()
{
	memset(visit, 0, sizeof(visit));
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			scanf("%1d", &arr[i][j]);
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (visit[i][j] == 0 && arr[i][j] == 1)
			{
				int ret = dfs(i, j);
				result.push_back(ret);
			}
		}
	}
	cout << result.size() << endl;
	sort(result.begin(), result.end());
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << endl;

	return 0;
}