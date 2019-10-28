#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <deque>
#include <algorithm>
#include <queue>
#include <functional>
#include <utility>
#include <list>
#define MAX 987654321
using namespace std;
typedef unsigned long long ul;
// baekjoon

int N, K, L, X, ny, nx, ret;
int arr[101][101];
vector<pair<int, char>> time;
char C;
int point[4][2] = { {0,1}, {1,0}, {0,-1}, {-1,0} };	// ¿ì, ³², ¼­, ºÏ

int main()
{
	ios::sync_with_stdio(false);

	cin >> N >> K;
	int a, b;
	for (int i = 0; i < K; i++)
	{
		cin >> a >> b;
		arr[a][b] = 100;	// apple
	}
	cin >> L;
	for (int i = 0; i < L; i++)
	{
		cin >> X >> C;
		time.push_back({ X,C });
	}

	deque<pair<int, int>> dq;
	dq.push_back({ 1,1 });
	arr[1][1] = -1;
	int dir = 0;

	while (1)
	{
		ret++;
		ny = dq.front().first + point[dir][0], nx = dq.front().second + point[dir][1];
		if (ny <= 0 || ny > N || nx <= 0 || nx > N || arr[ny][nx] == -1)
			break;

		if (arr[ny][nx] == 100)
		{
			arr[ny][nx] = -1;
			dq.push_front({ ny,nx });
		}
		else
		{
			arr[dq.back().first][dq.back().second] = 0;
			for (int i = dq.size() - 1; i > 0; i--)
				dq[i] = dq[i - 1];
			dq[0] = { ny,nx };
			arr[ny][nx] = -1;
		}

		for (int i = 0; i < time.size(); i++)
		{
			if (ret == time[i].first)
			{
				if (time[i].second == 'D')
					dir = (dir + 1) % 4;
				else
					dir = (dir + 3) % 4;
				break;
			}
		}
	}
	cout << ret << endl;
	return 0;
}
