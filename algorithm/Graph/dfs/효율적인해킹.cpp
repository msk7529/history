#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <stack>
#include <utility>
#include <cmath>
using namespace std;
// baekjoon

int N, M, num1, num2, ret;
vector<int> adj[10001];
vector<int> result;
int visit[10001];

void dfs(int a)
{
	visit[a] = 1;
	ret++;

	for (int i : adj[a])
	{
		if (visit[i] == 0)
			dfs(i);
	}
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> num1 >> num2;
		adj[num2].push_back(num1);
	}

	int answer = 0;
	for (int i = 1; i <= N; i++)
	{
		ret = 0;
		memset(visit, 0, sizeof(visit));
		dfs(i);
		if (ret > answer)
		{
			result.clear();
			result.push_back(i);
			answer = ret;
		}
		else if (ret == answer)
			result.push_back(i);
	}

	for (int i = 0; i < result.size(); i++)
		cout << result[i] << " ";

	return 0;
}