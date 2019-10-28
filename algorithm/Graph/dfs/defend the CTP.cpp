#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <utility>
#include <vector>
#include <map>
#include <queue>
#define MAX 987654321
using namespace std;
// baekjoon

int N, M, X, Y, T, C;
vector<int> adj[100001];
vector<int> adj2[100001];
int visit[100001];
int visit2[100001];

void dfs(int start)
{
	visit[start] = 1;

	for (int next : adj[start])
	{
		if (visit[next] == 0)
			dfs(next);
	}
}

void dfs2(int start)
{
	visit2[start] = 1;

	for (int next : adj2[start])
	{
		if (visit2[next] == 0)
			dfs2(next);
	}
}

int main()
{
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> X >> Y;
		adj[X].push_back(Y);
		adj2[Y].push_back(X);
	}

	memset(visit, 0, sizeof(visit));
	memset(visit2, 0, sizeof(visit2));
	dfs(1);
	dfs2(N);

	cin >> T;

	while (T--)
	{
		cin >> C;
		if (visit[C] && visit2[C])
			printf("Defend the CTP\n");
		else
			printf("Destroyed the CTP\n");
	}
	return 0;
}