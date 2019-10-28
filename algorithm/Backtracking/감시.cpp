#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
#include <utility>
#include <list>
#define MAX 987654321
using namespace std;
typedef unsigned long long ul;
// baekjoon

int N, M;
int arr[9][9];
int cnt_cctv, cnt_bbuk, cnt_ret;
vector<pair<int, int>> cctv;
int ret;

vector<pair<int,int>> watch_up(int y, int x)
{
	vector<pair<int, int>> tmp;
	for (int i = y - 1; i >= 0; i--)
	{
		if (arr[i][x] == 6)
			break;
		if (arr[i][x] == -1)
			tmp.push_back({ i,x });
		if (arr[i][x] == 0)
		{
			arr[i][x] = -1;
			cnt_ret++;
		}
	}
	return tmp;
}

vector<pair<int, int>> watch_down(int y, int x)
{
	vector<pair<int, int>> tmp;
	for (int i = y + 1; i < N; i++)
	{
		if (arr[i][x] == 6)
			break;
		if (arr[i][x] == -1)
			tmp.push_back({ i,x });
		if (arr[i][x] == 0)
		{
			arr[i][x] = -1;
			cnt_ret++;
		}
	}
	return tmp;
}

vector<pair<int, int>> watch_left(int y, int x)
{
	vector<pair<int, int>> tmp;
	for (int i = x - 1; i >= 0; i--)
	{
		if (arr[y][i] == 6)
			break;
		if (arr[y][i] == -1)
			tmp.push_back({ y,i });
		if (arr[y][i] == 0)
		{
			arr[y][i] = -1;
			cnt_ret++;
		}
	}
	return tmp;
}

vector<pair<int, int>> watch_right(int y, int x)
{
	vector<pair<int, int>> tmp;
	for (int i = x + 1; i < M; i++)
	{
		if (arr[y][i] == 6)
			break;
		if (arr[y][i] == -1)
			tmp.push_back({ y,i });
		if (arr[y][i] == 0)
		{
			arr[y][i] = -1;
			cnt_ret++;
		}
	}
	return tmp;
}

void recover_up(int y, int x)
{
	for (int i = y - 1; i >= 0; i--)
	{
		if (arr[i][x] == 6)
			break;
		if (arr[i][x] == -1)
			arr[i][x] = 0;
	}
}

void recover_down(int y, int x)
{
	for (int i = y + 1; i < N; i++)
	{
		if (arr[i][x] == 6)
			break;
		if (arr[i][x] == -1)
			arr[i][x] = 0;
	}
}

void recover_left(int y, int x)
{
	for (int i = x - 1; i >= 0; i--)
	{
		if (arr[y][i] == 6)
			break;
		if (arr[y][i] == -1)
			arr[y][i] = 0;
	}
}

void recover_right(int y, int x)
{
	for (int i = x + 1; i < M; i++)
	{
		if (arr[y][i] == 6)
			break;
		if (arr[y][i] == -1)
			arr[y][i] = 0;
	}
}

void backtracking(int idx)
{
	if (idx == cnt_cctv)
	{
		ret = max(ret, cnt_ret);
		return;
	}

	int y = cctv[idx].first, x = cctv[idx].second;
	int tmp_cnt = cnt_ret;
	vector<pair<int, int>> v, v2, v3, v4;

	if (arr[y][x] == 1)
	{
		v = watch_up(y, x);
		backtracking(idx + 1);
		cnt_ret = tmp_cnt;
		recover_up(y, x);
		for (int i = 0; i < v.size(); i++)
			arr[v[i].first][v[i].second] = -1;
		v.clear();

		v = watch_down(y, x);
		backtracking(idx + 1);
		cnt_ret = tmp_cnt;
		recover_down(y, x);
		for (int i = 0; i < v.size(); i++)
			arr[v[i].first][v[i].second] = -1;
		v.clear();

		v = watch_left(y, x);
		backtracking(idx + 1);
		cnt_ret = tmp_cnt;
		recover_left(y, x);
		for (int i = 0; i < v.size(); i++)
			arr[v[i].first][v[i].second] = -1;
		v.clear();

		v = watch_right(y, x);
		backtracking(idx + 1);
		cnt_ret = tmp_cnt;
		recover_right(y, x);
		for (int i = 0; i < v.size(); i++)
			arr[v[i].first][v[i].second] = -1;
		v.clear();
	}
	else if (arr[y][x] == 2)
	{
		v = watch_up(y, x);
		v2 = watch_down(y, x);
		backtracking(idx + 1);
		cnt_ret = tmp_cnt;
		recover_up(y, x);
		recover_down(y, x);
		for (int i = 0; i < v.size(); i++)
			arr[v[i].first][v[i].second] = -1;
		for (int i = 0; i < v2.size(); i++)
			arr[v2[i].first][v2[i].second] = -1;
		v.clear();
		v2.clear();

		v = watch_left(y, x);
		v2 = watch_right(y, x);
		backtracking(idx + 1);
		cnt_ret = tmp_cnt;
		recover_left(y, x);
		recover_right(y, x);
		for (int i = 0; i < v.size(); i++)
			arr[v[i].first][v[i].second] = -1;
		for (int i = 0; i < v2.size(); i++)
			arr[v2[i].first][v2[i].second] = -1;
		v.clear();
		v2.clear();
	}
	else if (arr[y][x] == 3)
	{
		v = watch_up(y, x);
		v2 = watch_right(y, x);
		backtracking(idx + 1);
		cnt_ret = tmp_cnt;
		recover_up(y, x);
		recover_right(y, x);
		for (int i = 0; i < v.size(); i++)
			arr[v[i].first][v[i].second] = -1;
		for (int i = 0; i < v2.size(); i++)
			arr[v2[i].first][v2[i].second] = -1;
		v.clear();
		v2.clear();

		v = watch_right(y, x);
		v2 = watch_down(y, x);
		backtracking(idx + 1);
		cnt_ret = tmp_cnt;
		recover_right(y, x);
		recover_down(y, x);
		for (int i = 0; i < v.size(); i++)
			arr[v[i].first][v[i].second] = -1;
		for (int i = 0; i < v2.size(); i++)
			arr[v2[i].first][v2[i].second] = -1;
		v.clear();
		v2.clear();

		v = watch_down(y, x);
		v2 = watch_left(y, x);
		backtracking(idx + 1);
		cnt_ret = tmp_cnt;
		recover_down(y, x);
		recover_left(y, x);
		for (int i = 0; i < v.size(); i++)
			arr[v[i].first][v[i].second] = -1;
		for (int i = 0; i < v2.size(); i++)
			arr[v2[i].first][v2[i].second] = -1;
		v.clear();
		v2.clear();

		v = watch_left(y, x);
		v2 = watch_up(y, x);
		backtracking(idx + 1);
		cnt_ret = tmp_cnt;
		recover_left(y, x);
		recover_up(y, x);
		for (int i = 0; i < v.size(); i++)
			arr[v[i].first][v[i].second] = -1;
		for (int i = 0; i < v2.size(); i++)
			arr[v2[i].first][v2[i].second] = -1;
		v.clear();
		v2.clear();
	}
	else if (arr[y][x] == 4)
	{
		v = watch_up(y, x);
		v2 = watch_right(y, x);
		v3 = watch_down(y, x);
		backtracking(idx + 1);
		cnt_ret = tmp_cnt;
		recover_up(y, x);
		recover_right(y, x);
		recover_down(y, x);
		for (int i = 0; i < v.size(); i++)
			arr[v[i].first][v[i].second] = -1;
		for (int i = 0; i < v2.size(); i++)
			arr[v2[i].first][v2[i].second] = -1;
		for (int i = 0; i < v3.size(); i++)
			arr[v3[i].first][v3[i].second] = -1;
		v.clear();
		v2.clear();
		v3.clear();

		v = watch_left (y, x);
		v2 = watch_right(y, x);
		v3 = watch_down(y, x);
		backtracking(idx + 1);
		cnt_ret = tmp_cnt;
		recover_left(y, x);
		recover_right(y, x);
		recover_down(y, x);
		for (int i = 0; i < v.size(); i++)
			arr[v[i].first][v[i].second] = -1;
		for (int i = 0; i < v2.size(); i++)
			arr[v2[i].first][v2[i].second] = -1;
		for (int i = 0; i < v3.size(); i++)
			arr[v3[i].first][v3[i].second] = -1;
		v.clear();
		v2.clear();
		v3.clear();

		v = watch_left(y, x);
		v2 = watch_up(y, x);
		v3 = watch_down(y, x);
		backtracking(idx + 1);
		cnt_ret = tmp_cnt;
		recover_left(y, x);
		recover_up(y, x);
		recover_down(y, x);
		for (int i = 0; i < v.size(); i++)
			arr[v[i].first][v[i].second] = -1;
		for (int i = 0; i < v2.size(); i++)
			arr[v2[i].first][v2[i].second] = -1;
		for (int i = 0; i < v3.size(); i++)
			arr[v3[i].first][v3[i].second] = -1;
		v.clear();
		v2.clear();
		v3.clear();

		v = watch_left(y, x);
		v2 = watch_up(y, x);
		v3 = watch_right(y, x);
		backtracking(idx + 1);
		cnt_ret = tmp_cnt;
		recover_left(y, x);
		recover_up(y, x);
		recover_right(y, x);
		for (int i = 0; i < v.size(); i++)
			arr[v[i].first][v[i].second] = -1;
		for (int i = 0; i < v2.size(); i++)
			arr[v2[i].first][v2[i].second] = -1;
		for (int i = 0; i < v3.size(); i++)
			arr[v3[i].first][v3[i].second] = -1;
		v.clear();
		v2.clear();
		v3.clear();
	}
	else if (arr[y][x] == 5)
	{
		v = watch_up(y, x);
		v2 = watch_right(y, x);
		v3 = watch_down(y, x);
		v4 = watch_left(y, x);
		backtracking(idx + 1);
		cnt_ret = tmp_cnt;
		recover_up(y, x);
		recover_right(y, x);
		recover_down(y, x);
		recover_left(y, x);
		for (int i = 0; i < v.size(); i++)
			arr[v[i].first][v[i].second] = -1;
		for (int i = 0; i < v2.size(); i++)
			arr[v2[i].first][v2[i].second] = -1;
		for (int i = 0; i < v3.size(); i++)
			arr[v3[i].first][v3[i].second] = -1;
		for (int i = 0; i < v4.size(); i++)
			arr[v4[i].first][v4[i].second] = -1;
		v.clear();
		v2.clear();
		v3.clear();
		v4.clear();
	}
}

int main()
{
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] >= 1 && arr[i][j] <= 5)
			{
				cctv.push_back({ i,j });
				cnt_cctv++;
			}
			else if (arr[i][j] == 6)
				cnt_bbuk++;
		}
	}
	ret = cnt_ret = 0;

	backtracking(0);
	int result = N*M - cnt_cctv - cnt_bbuk - ret;
	cout << result << endl;

	return 0;
}