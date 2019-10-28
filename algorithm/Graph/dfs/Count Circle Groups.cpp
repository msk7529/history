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

struct army
{
	int x, y, r;
};

int T, N;
int visit[3001];
army ar[3001];
vector<int> adj[3001];

bool isCommunicatable(army a, army b)
{
	double distance = pow(a.x - b.x, 2.0) + pow(a.y - b.y, 2.0);
	double R = pow(a.r + b.r, 2.0);

	if (distance <= R)
		return true;
	return false;
}

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
	cin >> T;
	while (T--)
	{
		int result = 0;
		memset(visit, 0, sizeof(visit));
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			cin >> ar[i].x >> ar[i].y >> ar[i].r;
			adj[i].clear();
		}
		adj[N].clear();

		for (int i = 0; i < N - 1; i++)
		{
			for (int j = i + 1; j < N; j++)
			{
				if (isCommunicatable(ar[i], ar[j]))
				{
					adj[i].push_back(j);
					adj[j].push_back(i);
				}
			}
		}

		for (int i = 0; i < N; i++)
		{
			if (visit[i] == 0)
			{
				dfs(i);
				result++;
			}
		}
		cout << result << endl;
	}
	return 0;
}