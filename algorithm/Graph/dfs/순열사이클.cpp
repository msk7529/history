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

int T, N;
int visit[1001];
vector<int> adj[1001];
vector<int> order;

int dfs(int start)
{
	visit[start] = 1;

	order.push_back(start);

	for (int i : adj[start])
	{
		if (visit[i] == 0)
			dfs(i);
		else if (visit[i] == 1)
		{
			if (find(order.begin(), order.end(), i) != order.end())
				return 1;
			else
				return 0;
		}
	}
}

int main()
{
	cin >> T;
	while (T--)
	{
		memset(visit, 0, sizeof(visit));
		cin >> N;
		for (int i = 1; i <= N; i++)
		{
			adj[i].clear();
			int num;
			cin >> num;
			adj[i].push_back(num);
		}

		int ret = 0;
		for (int i = 1; i <= N; i++)
		{
			order.clear();
			if (visit[i] == 0)
				ret += dfs(i);
		}
		cout << ret << endl;
	}

	return 0;
}