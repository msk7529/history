#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
#include <utility>
#define MAX 987654321
using namespace std;
// baekjoon

int N, M, A, B;
int visit[100001];
int parent[100001];
vector<int> adj[100001];

void dfs(int here)
{
	visit[here] = 1;
	
	for (int next : adj[here])
	{
		if (visit[next] == 0)
			dfs(next);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	memset(parent, -1, sizeof(parent));

	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> A >> B;
		adj[A].push_back(B);
		parent[B] = A;
	}

	int ret = 0;
	vector<int> v;
	for (int i = 0; i < N; i++)
	{
		if (visit[i] == 0)
		{
			if (parent[i] == -1)
			{
				dfs(i);
				ret++;
			}
			else
				v.push_back(i);
		}
	}

	for (int i = 0; i < v.size(); i++)
	{
		if (visit[v[i]] == 0)
		{
			dfs(v[i]);
			ret++;
		}
	}
	cout << ret << endl;
	return 0;
}
