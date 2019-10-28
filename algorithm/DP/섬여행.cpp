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

int dp[101][501][101];
//int adj[101][101];
vector<int> adj[101];
int N, M, X, Y, T, A, K;
int H[101];

int main()
{
	cin >> N >> M;
	//memset(adj, 0, sizeof(adj));

	for (int i = 1; i <= N; i++)
	{
		for (int j = 0; j <= 500; j++)
		{
			for (int k = 1; k <= N; k++)
				dp[i][j][k] = MAX;
		}
	}

	for (int i = 1; i <= N; i++)
	{
		cin >> H[i];
		dp[i][0][i] = H[i];
	}
	for (int i = 1; i <= M; i++)
	{
		cin >> X >> Y;
		adj[X].push_back(Y);
		adj[Y].push_back(X);
		//adj[X][Y] = adj[Y][X] = 1;
	}
	for (int i = 1; i <= N; i++)
	{
		for (int k = 1; k <= 500; k++)
		{
			for (int j = 1; j <= N; j++)
			{
				if (dp[i][k-1][j] == MAX)
					continue;

				for (int next : adj[j])
					dp[i][k][next] = min(dp[i][k][next], H[next]);
			}
		}
	}

	cin >> T;
	while (T--)
	{
		cin >> A >> K;
		int ret = MAX;
		for (int i = 1; i <= N; i++)
			ret = min(ret, dp[A][K][i]);
		if (ret == MAX)
			printf("-1\n");
		else
			printf("%d\n", ret);
	}
	return 0;
}