#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <queue>
#define MAX 987654321
using namespace std;
// baekjoon

int N, K;
int visit[100001];
queue<int> q;

int bfs()
{
	q.push(N);
	visit[N] = 0;

	while (!q.empty())
	{
		int curr = q.front();
		q.pop();

		if (curr == K)
			return visit[K];

		int next1 = curr - 1, next2 = curr + 1, next3 = curr * 2;

		if (next1 >= 0 && visit[next1] == 0)
		{
			q.push(next1);
			visit[next1] = visit[curr] + 1;
		}
		if (next2 <= 100000 && visit[next2] == 0)
		{
			q.push(next2);
			visit[next2] = visit[curr] + 1;
		}
		if (next3 <= 100000 && visit[next3] == 0)
		{
			q.push(next3);
			visit[next3] = visit[curr] + 1;
		}
	}
	return 0;
}


int main()
{
	cin >> N >> K;
	memset(visit, 0, sizeof(visit));

	cout << bfs() << endl;

	return 0;
}