#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <stack>
#include <string>
#include <utility>
#include <cmath>
using namespace std;
// baekjoon

struct st
{
	int l, r, c;
	st()
	{
		l = r = c = -1;
	}
	st(int l, int r, int c)
	{
		this->l = l;
		this->r = r;
		this->c = c;
	}
};

int L, R, C; // Ãþ, Çà, ¿­
st exitt;
char arr[31][31][31];
int visit[31][31][31];
int point[6][3] = { {-1,0,0}, {1,0,0}, {0,1,0},{0,-1,0},{0,0,1 }, {0,0,-1} };
queue<st> q;

bool check(st next)
{
	if (next.l >= 1 && next.l <= L && next.r >= 1 && next.r <= R && next.c >= 1 && next.c <= C)
		return true;
	return false;
}

void bfs()
{
	st tmp = q.front();
	visit[tmp.l][tmp.r][tmp.c] = 0;

	while (!q.empty())
	{
		tmp = q.front();
		q.pop();
		for (int i = 0; i < 6; i++)
		{
			st next = { tmp.l + point[i][0], tmp.r + point[i][1], tmp.c + point[i][2] };
			if (check(next) && arr[next.l][next.r][next.c] != '#' && visit[next.l][next.r][next.c] == 0)
			{
				visit[next.l][next.r][next.c] = visit[tmp.l][tmp.r][tmp.c] + 1;
				q.push(next);

				if (next.l == exitt.l && next.r == exitt.r && next.c == exitt.c)
					break;
			}
		}
	}
}

int main()
{
	while (1)
	{
		if (!q.empty())
			q.pop();
		memset(visit, 0, sizeof(visit));
		memset(arr, ' ', sizeof(arr));
		string s;
		cin >> L >> R >> C;

		if (L == 0 && R == 0 && C == 0)
			break;

		for (int i = 1; i <= L; i++)
		{
			for (int j = 1; j <= R; j++)
			{
				cin >> s;
				for (int k = 1; k <= C; k++)
				{
					arr[i][j][k] = s[k-1];
					if (arr[i][j][k] == 'S')
						q.push(st(i, j, k));
					else if (arr[i][j][k] == 'E')
						exitt = { i,j,k };
				}
			}
		}

		bfs();
		if (visit[exitt.l][exitt.r][exitt.c])
			cout << "Escaped in " << visit[exitt.l][exitt.r][exitt.c] << " minute(s)." << endl;
		else
			cout << "Trapped!" << endl;
	
		/*int ret = bfs();
		if (ret == -1)
			cout << "Trapped!" << endl;
		else
			cout << "Escaped in " << ret << " minute(s)." << endl;*/
	}

	return 0;
}