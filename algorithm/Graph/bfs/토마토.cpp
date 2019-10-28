#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <stack>
#include <utility>
using namespace std;
// baekjoon

struct tomato
{
	int x, y, day;
};

int M, N;
int arr[1001][1001];
int point[4][2] = { {-1,0}, {0,1}, {1,0}, {0,-1} };
int result = 0;
queue<struct tomato> q;

bool check(tomato t)
{
	if (t.x < 0 || t.x >= M || t.y < 0 || t.y >= N)
		return false;
	if (arr[t.y][t.x] == 0)
		return true;
	return false;
}

bool isFinished()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] == 0)
				return false;
		}
	}
	return true;
}

void bfs()
{
	tomato t1, t2;

	while (!q.empty())
	{
		t1 = q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			t2 = { t1.x + point[i][0], t1.y + point[i][1], t1.day + 1 };
			if (check(t2))
			{
				q.push(t2);
				arr[t2.y][t2.x] = 1;
				result = max(result, t2.day);
			}
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> M >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 1)
			{
				tomato a = { j,i,0 };
				q.push(a);
			}
		}
	}

	if (isFinished())
		cout << "0" << endl;
	else
	{
		bfs();
		if (isFinished())
			cout << result << endl;
		else
			cout << "-1" << endl;
	}

	return 0;
}