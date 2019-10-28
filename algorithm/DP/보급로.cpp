#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <stack>
#include <string>
#include <utility>
#include <cmath>
#include <map>
#include <deque>
using namespace std;
// sw expert

int T, N;
int point[4][2] = { {1,0},{-1,0}, {0,1}, {0,-1} };
int arr[101][101];
int dp[101][101];
int result;
queue<pair<int, int>> q;

void bfs()
{
	dp[0][0] = 0;
	while (!q.empty())
	{
		int y = q.front().first, x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + point[i][0], nx = x + point[i][1];
			if (ny >= 0 && ny < N && nx >= 0 && nx < N )
			{
				if (dp[y][x] + arr[ny][nx] < dp[ny][nx])
				{
					dp[ny][nx] = dp[y][x] + arr[ny][nx];
					q.push({ ny,nx });
				}
			}
		}
	}
 }

int main()
{
	cin >> T;

	for (int a = 1; a <= T; a++)
	{
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				scanf("%1d", &arr[i][j]);
				dp[i][j] = 987654321;
			}
		}
		q.push({ 0,0 });
		bfs();

		cout << "#" << a << " " << dp[N - 1][N - 1] << endl;
	}
	return 0;
}

// dp로 안할시 시간초과. 그냥 bfs로만 할시 메모리초과.