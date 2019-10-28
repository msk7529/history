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

int T, N, M, D;
int adj[1001][1001];

int dfs(int curr, int parent)
{
	int sum = 0;
	for (int i = 1; i <= N; i++)
	{
		if (adj[i][curr] != 0 && i != parent)
			sum += dfs(i, curr);
	}
	if (sum == 0)
		return adj[curr][parent];
	return min(sum, adj[curr][parent]);
}



int main()
{
	cin >> T;
	while (T--)
	{
		memset(adj, 0, sizeof(adj));
		cin >> N >> M;

		int a, b, c;
		for (int i = 0; i < M; i++)
		{
			cin >> a >> b >> c;
			adj[a][b] = c;
			adj[b][a] = c;
		}

		adj[1][0] = MAX;
		printf("%d\n", dfs(1, 0));
	}
	return 0;
}