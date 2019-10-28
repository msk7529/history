#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <stack>
#include <string>
#include <utility>
#include <cmath>
#include <map>
using namespace std;
// baekjoon

int R, C;
char arr[10001][501];
int visit[10001][501];
int point[3][2] = { {-1,1}, {0,1},{1,1} };	// 우상단으로 가는것이 최대 해를 구할수있음.
bool fin;
int ret;

void dfs(int y, int x)
{
	if (x == C - 1)
	{
		ret++;
		fin = true;
		return;
	}

	for (int i = 0; i < 3; i++)
	{
		int ny = y + point[i][0], nx = x + point[i][1];
		if (ny >= 0 && ny < R && nx > 0 && nx < C && visit[ny][nx] == 0 && arr[ny][nx] == '.')
		{
			visit[ny][nx] = 1;
			dfs(ny, nx);
			if (fin)
				return;
			//visit[ny][nx] = 0;   --> 추가시 시간초과. 한번 들린곳은 더이상 갈 필요가없음.
		}
	}
}

int main()
{
	memset(visit, 0, sizeof(visit));
	cin >> R >> C;
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
			cin >> arr[i][j];
	}
	for (int i = 0; i < R; i++)
	{
		fin = false;
		visit[i][0] = 1;
		dfs(i, 0);
	}
	cout << ret << endl;


	return 0;
}