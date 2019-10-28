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

int N, M, u, v;
vector<int> adj[1001];
int visit[1001];

void dfs(int start)
{
	visit[start] = 1;
	for (int i : adj[start])
	{
		if (visit[i] == 0)
			dfs(i);
	}
}

int main()
{
	int result = 0;
	memset(visit, 0, sizeof(visit));
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 1; i <= N; i++)
	{
		if (visit[i] == 0)
		{
			dfs(i);
			result++;
		}
	}
	cout << result << endl;
	return 0;
}