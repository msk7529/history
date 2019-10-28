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

int N;
int arr[101][101];
int visit[101];
int result[101][101];
vector<int> adj[101];

int dfs(int start, int dst , int i)
{
	if (i == 1 && start == dst )
		return 1;

	int ret = 0;

	for (int a : adj[start])
	{
		if (visit[a] == 0)
		{
			visit[a] = 1;
			ret += dfs(a,dst,1);
		}
	}
	return ret;
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 1)
				adj[i].push_back(j);
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			memset(visit, 0, sizeof(visit));
			if (dfs(i, j, 0))
				result[i][j] = 1;
			else
				result[i][j] = 0;
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << result[i][j] << " ";
		cout << endl;
	}
	return 0;
}