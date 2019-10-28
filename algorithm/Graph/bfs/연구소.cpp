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
#include <deque>
using namespace std;
// baekjoon

int N, M;
int arr[9][9];
int point[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };
int ret = 0;
int visit[9][9];
int origin_v = 0;
int origin_buk = 0;
vector<pair<int, int>> vp;
vector<pair<int, int>> vv;
queue<pair<int, int>> q;

int bfs()
{
	int cnt = 0;
	while (!q.empty())
	{
		int y = q.front().first, x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = y + point[i][0], nx = x + point[i][1];
			if (ny >= 1 && ny <= N && nx >= 1 && nx <= M && visit[ny][nx] == 0 && arr[ny][nx] != 1)
			{
				cnt++;
				visit[ny][nx] = 1;
				q.push({ ny,nx });
			}
		}
	}
	return cnt;
}

int main()
{
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 0)
				vp.push_back({ i,j });
			else if (arr[i][j] == 2)
			{
				vv.push_back({ i,j });
				origin_v++;
			}
			else
				origin_buk++;
		}
	}

	int start = N*M - (origin_buk + 3) - origin_v;

	for (int i = 0; i < vp.size()-2; i++)
	{
		arr[vp[i].first][vp[i].second] = 1;
		for (int j = i + 1; j < vp.size()-1; j++)
		{
			arr[vp[j].first][vp[j].second] = 1;
			for (int k = j + 1; k < vp.size(); k++)
			{
				memset(visit, 0, sizeof(visit));
				for (int z = 0; z < vv.size(); z++)
				{
					q.push({ vv[z].first, vv[z].second });
					visit[vv[z].first][vv[z].second] = 1;
				}
				arr[vp[k].first][vp[k].second] = 1;

				int cnt = bfs();
				ret = max(ret, start - cnt);

				while (!q.empty())
					q.pop();
				arr[vp[k].first][vp[k].second] = 0;
			}
			arr[vp[j].first][vp[j].second] = 0;
		}
		arr[vp[i].first][vp[i].second] = 0;
	}

	cout << ret << endl;

	return 0;
}