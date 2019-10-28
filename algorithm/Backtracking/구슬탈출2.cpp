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

char arr[11][11];
int N, M;
int ret;

pair<int, int> findRed()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] == 'R')
				return{ i,j };
		}
	}
}

pair<int, int> findBlue()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (arr[i][j] == 'B')
				return{ i,j };
		}
	}
}

bool goRight(pair<int, int> p)
{
	int j = p.second + 1;
	for (; j < M; j++)
	{
		if (arr[p.first][j] == 'O')
		{
			arr[p.first][p.second] = '.';
			return true;
		}
		else if (arr[p.first][j] != '.')
			break;
	}
	j--;

	if (arr[p.first][p.second] == 'R')
	{
		arr[p.first][p.second] = '.';
		arr[p.first][j] = 'R';
	}
	else if (arr[p.first][p.second] == 'B')
	{
		arr[p.first][p.second] = '.';
		arr[p.first][j] = 'B';
	}
	return false;
}

bool goLeft(pair<int, int> p)
{
	int j = p.second - 1;
	for (; j < M; j--)
	{
		if (arr[p.first][j] == 'O')
		{
			arr[p.first][p.second] = '.';
			return true;
		}
		else if (arr[p.first][j] != '.')
			break;
	}
	j++;

	if (arr[p.first][p.second] == 'R')
	{
		arr[p.first][p.second] = '.';
		arr[p.first][j] = 'R';
	}
	else if (arr[p.first][p.second] == 'B')
	{
		arr[p.first][p.second] = '.';
		arr[p.first][j] = 'B';
	}
	return false;
}

bool goUp(pair<int, int> p)
{
	int i = p.first - 1;
	for (; i < M; i--)
	{
		if (arr[i][p.second] == 'O')
		{
			arr[p.first][p.second] = '.';
			return true;
		}
		else if (arr[i][p.second] != '.')
			break;
	}
	i++;

	if (arr[p.first][p.second] == 'R')
	{
		arr[p.first][p.second] = '.';
		arr[i][p.second] = 'R';
	}
	else if (arr[p.first][p.second] == 'B')
	{
		arr[p.first][p.second] = '.';
		arr[i][p.second] = 'B';
	}
	return false;
}

bool goDown(pair<int, int> p)
{
	int i = p.first + 1;
	for (; i < M; i++)
	{
		if (arr[i][p.second] == 'O')
		{
			arr[p.first][p.second] = '.';
			return true;
		}
		else if (arr[i][p.second] != '.')
			break;
	}
	i--;

	if (arr[p.first][p.second] == 'R')
	{
		arr[p.first][p.second] = '.';
		arr[i][p.second] = 'R';
	}
	else if (arr[p.first][p.second] == 'B')
	{
		arr[p.first][p.second] = '.';
		arr[i][p.second] = 'B';
	}
	return false;
}

void recover(char tmp_arr[11][11])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			arr[i][j] = tmp_arr[i][j];
	}
}

void backtracking(int cnt)
{
	if (cnt == 10)
		return;

	char tmp_arr[11][11];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			tmp_arr[i][j] = arr[i][j];
	}

	pair<int, int> red = findRed();
	pair<int, int> blue = findBlue();

	if (red.first == blue.first)
	{
		if (red.second > blue.second)
		{
			bool b1 = goRight(red);
			bool b2 = goRight(blue);
			if (b1 && !b2)
			{
				ret = min(ret, cnt + 1);
				return;
			}
			if(!b1 && !b2)
				backtracking(cnt + 1);
			recover(tmp_arr);

			b1 = goLeft(blue);
			b2 = goLeft(red);
			if (!b1 && b2)
			{
				ret = min(ret, cnt + 1);
				return;
			}
			if (!b1 && !b2)
				backtracking(cnt + 1);
			recover(tmp_arr);
		}
		else
		{
			bool b1 = goRight(blue);
			bool b2 = goRight(red);
			if (!b1 && b2)
			{
				ret = min(ret, cnt + 1);
				return;
			}
			if (!b1 && !b2)
				backtracking(cnt + 1);
			recover(tmp_arr);

			b1 = goLeft(red);
			b2 = goLeft(blue);
			if (b1 && !b2)
			{
				ret = min(ret, cnt + 1);
				return;
			}
			if (!b1 && !b2)
				backtracking(cnt + 1);
			recover(tmp_arr);
		}
		bool b1 = goUp(red);
		bool b2 = goUp(blue);
		if (b1 && !b2)
		{
			ret = min(ret, cnt + 1);
			return;
		}
		if (!b1 && !b2)
			backtracking(cnt + 1);
		recover(tmp_arr);

		b1 = goDown(red);
		b2 = goDown(blue);
		if (b1 && !b2)
		{
			ret = min(ret, cnt + 1);
			return;
		}
		if (!b1 && !b2)
			backtracking(cnt + 1);
		recover(tmp_arr);
	}	
	else if(red.second == blue.second)
	{
		if (red.first > blue.first)
		{
			bool b1 = goDown(red);
			bool b2 = goDown(blue);
			if (b1 && !b2)
			{
				ret = min(ret, cnt + 1);
				return;
			}
			if (!b1 && !b2)
				backtracking(cnt + 1);
			recover(tmp_arr);

			b1 = goUp(blue);
			b2 = goUp(red);
			if (!b1 && b2)
			{
				ret = min(ret, cnt + 1);
				return;
			}
			if (!b1 && !b2)
				backtracking(cnt + 1);
			recover(tmp_arr);
		}
		else
		{
			bool b1 = goDown(blue);
			bool b2 = goDown(red);
			if (!b1 && b2)
			{
				ret = min(ret, cnt + 1);
				return;
			}
			if (!b1 && !b2)
				backtracking(cnt + 1);
			recover(tmp_arr);

			b1 = goUp(red);
			b2 = goUp(blue);
			if (b1 && !b2)
			{
				ret = min(ret, cnt + 1);
				return;
			}
			if (!b1 && !b2)
				backtracking(cnt + 1);
			recover(tmp_arr);
		}
		bool b1 = goLeft(red);
		bool b2 = goLeft(blue);
		if (b1 && !b2)
		{
			ret = min(ret, cnt + 1);
			return;
		}
		if (!b1 && !b2)
			backtracking(cnt + 1);
		recover(tmp_arr);

		b1 = goRight(red);
		b2 = goRight(blue);
		if (b1 && !b2)
		{
			ret = min(ret, cnt + 1);
			return;
		}
		if (!b1 && !b2)
			backtracking(cnt + 1);
		recover(tmp_arr);
	}
	else
	{
		bool b1, b2;
		b1 = goUp(red);
		b2 = goUp(blue);
		if (b1 && !b2)
		{
			ret = min(ret, cnt + 1);
			return;
		}
		if (!b1 && !b2)
			backtracking(cnt + 1);
		recover(tmp_arr);

		b1 = goRight(red);
		b2 = goRight(blue);
		if (b1 && !b2)
		{
			ret = min(ret, cnt + 1);
			return;
		}
		if (!b1 && !b2)
			backtracking(cnt + 1);
		recover(tmp_arr);

		b1 = goDown(red);
		b2 = goDown(blue);
		if (b1 && !b2)
		{
			ret = min(ret, cnt + 1);
			return;
		}
		if (!b1 && !b2)
			backtracking(cnt + 1);
		recover(tmp_arr);

		b1 = goLeft(red);
		b2 = goLeft(blue);
		if (b1 && !b2)
		{
			ret = min(ret, cnt + 1);
			return;
		}
		if (!b1 && !b2)
			backtracking(cnt + 1);
		recover(tmp_arr);
	}
}

int main()
{
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cin >> arr[i][j];
	}
	ret = MAX;

	backtracking(0);
	if (ret == MAX)
		cout << "-1" << endl;
	else
		cout << ret << endl;
	return 0;
}