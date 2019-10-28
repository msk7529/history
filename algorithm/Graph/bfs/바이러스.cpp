#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <stack>
#include <utility>
using namespace std;
// baekjoon

int N, M, num1, num2;
int visit[101];
int result = 0;
vector<int> adj[101];
queue<int> q;

//void bfs(int start)
//{
//	visit[start] = 1;
//	q.push(start);
//
//	while (!q.empty())
//	{
//		int next = q.front();
//		q.pop();
//		for (int i : adj[next])
//		{
//			if (visit[i] == 0)
//			{
//				visit[i] = 1;
//				result++;
//				q.push(i);
//			}
//		}
//	}
//}

void dfs(int start)
{
	visit[start] = 1;
	
	for (int i : adj[start])
	{
		if (visit[i] == 0)
		{
			result++;
			dfs(i);
		}
	}
}

int main()
{
	cin >> N >> M;
	memset(visit, 0, sizeof(visit));

	for (int i = 0; i < M; i++)
	{
		cin >> num1 >> num2;
		adj[num1].push_back(num2);
		adj[num2].push_back(num1);	// 양방향 반드시..
	}

	//bfs(1);
	dfs(1);
	cout << result << endl;

	return 0;
}