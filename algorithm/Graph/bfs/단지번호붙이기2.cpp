#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <stack>
#include <utility>
using namespace std;
// baekjoon

int N;
int arr[26][26];
int visit[26][26];
int point[4][2] = { {1,0},{-1,0}, {0,1}, {0,-1} };
vector<int> result;
queue<pair<int, int>> q;

bool check(pair<int, int> p)
{
	int y = p.first, x = p.second;
	if (y < 0 || y >= N || x < 0 || x >= N || arr[y][x] == 0)
		return false;
	if (arr[y][x] == 1 && visit[y][x] == 0)
		return true;
	return false; // arr[y][x] == 1 && visit[y][x] == 1 인 경우.
}

bool check2()	// 아직 방문하지 않은 집이 있으면 true 리턴.
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (arr[i][j] == 1 && visit[i][j] == 0)
				return true;
		}
	}
	return false;
}

void bfs()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (arr[i][j] == 1 && visit[i][j] == 0)
			{
				q.push({ i,j });
				visit[i][j] = 1;
				break;
			}
		}
		if (!q.empty())
			break;
	}

	int ret = 0;
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		ret++;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			if (check({ y + point[i][0], x + point[i][1] }))
			{
				//ret++;
				visit[y + point[i][0]][x + point[i][1]] = 1;
				q.push({ y + point[i][0], x + point[i][1] });
			}
		}
	}
	result.push_back(ret);

	if (check2())
		bfs();
}


int main()
{
	cin >> N;
	memset(visit, 0, sizeof(visit));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			scanf("%1d", &arr[i][j]);
	}

	bfs();

	sort(result.begin(), result.end());
	cout << result.size() << endl;
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << endl;

	return 0;
}