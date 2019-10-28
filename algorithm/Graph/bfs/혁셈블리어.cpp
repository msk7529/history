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
#include <time.h>
using namespace std;
// sw expert

struct st
{
	int y, x, my, mx;
	st(int y, int x, int my, int mx)
	{
		this->y = y;
		this->x = x;
		this->my = my;
		this->mx = mx;
	}
};

int point[4][2] = { {1,0}, {-1,0},{0,1}, {0,-1} }; // 하, 상, 우, 좌
int T, R, C;
vector<char> vc;
char arr[21][21];
int mem;
vector<pair<int, int>> check[21][21];
queue<st> q;

int bfs()
{
	while (!q.empty())
	{
		int y = q.front().y, x = q.front().x, my = q.front().my, mx = q.front().mx;
		char now = arr[y][x];
		int ny, nx;
		q.pop();

		if (now == '@')
			return 1;
		else if (now == '<')
			my = 0, mx = -1;
		else if (now == '>')
			my = 0, mx = 1;
		else if (now == '^')
			my = -1, mx = 0;
		else if (now == 'v')
			my = 1, mx = 0;
		else if (now == '_')
		{
			if (mem == 0)
				my = 0, mx = 1;
			else
				my = 0, mx = -1;
		}
		else if (now == '|')
		{
			if (mem == 0)
				my = 1, mx = 0;
			else
				my = -1, mx = 0;
		}
		else if (now == '.')
			;
		else if (find(vc.begin(), vc.end(), now) != vc.end())
			mem = now - '0';
		else if (now == '+')
		{
			if (mem == 15)
				mem = 0;
			else
				mem++;
		}
		else if (now == '-')
		{
			if (mem == 0)
				mem = 15;
			else
				mem--;
		}
		
		pair<int, int> p = { mem, 10 * my + mx };
		if (find(check[y][x].begin(), check[y][x].end(), p) != check[y][x].end())
			continue;
		else
			check[y][x].push_back(p);

		if (now != '?')
		{
			ny = y + my, nx = x + mx;
			if (ny == -1)
				ny = R - 1;
			else if (ny == R)
				ny = 0;
			else if (nx == -1)
				nx = C - 1;
			else if (nx == C)
				nx = 0;
			q.push(st(ny, nx, my, mx));
		}
		else
		{
			for (int i = 0; i < 4; i++)
			{
				my = point[i][0], mx = point[i][1];
				ny = y + my, nx = x + mx;
				if (ny == -1)
					ny = R - 1;
				else if (ny == R)
					ny = 0;
				else if (nx == -1)
					nx = C - 1;
				else if (nx == C)
					nx = 0;
				q.push(st(ny, nx, my, mx));
			}
		}
	}
	return 0;
}

int main()
{
	//clock_t before = clock();

	for (int i = 0; i <= 9; i++)
		vc.push_back('0' + i);
	cin >> T;
	for (int i = 1; i <= T; i++)
	{
		cin >> R >> C;
		for (int j = 0; j < R; j++)
		{
			for (int k = 0; k < C; k++)
				check[j][k].clear();
		}
		mem = 0;
		for (int j = 0; j < R; j++)
		{
			for (int k = 0; k < C; k++)
				cin >> arr[j][k];
		}

		q.push(st(0,0,0,1));

		if (bfs())
			cout << "#" << i << " " << "YES" << endl;
		else
			cout << "#" << i << " " << "NO" << endl;

		while (!q.empty())
			q.pop();
	}
	//printf("걸린시간 : %6.5f\n", (double)(clock() - before) / CLOCKS_PER_SEC);

	return 0;
}

