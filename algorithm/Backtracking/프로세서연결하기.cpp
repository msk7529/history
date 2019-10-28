#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
#include <utility>
#define MAX 987654321
#define MOD 1000000007
using namespace std;
typedef unsigned long long ul;
// sw expert

int N, T;
int arr[14][14];
vector<pair<int, int>> v;
int ret_sum, ret_complete;

void backtracking(int cnt, int complete, int sum)
{
	if (cnt == v.size())
	{
		/*if (complete >= ret_complete)
		{
			ret_complete = complete;
			ret_sum = min(sum, ret_sum);
		}*/
		if (complete > ret_complete)
		{
			ret_complete = complete;
			ret_sum = sum;
		}
		else if (complete == ret_complete)
			ret_sum = min(ret_sum, sum);
		return;
	}

	int here_i = v[cnt].first - 1, here_j = v[cnt].second;

	for (; here_i > 0; here_i--)
	{
		if (arr[here_i][here_j])
			break;
	}

	if (here_i == 0)
	{
		for (int i = 1; i < v[cnt].first; i++)
			arr[i][here_j] = 1;
		backtracking(cnt + 1, complete + 1, sum + v[cnt].first - 1);
		for (int i = v[cnt].first - 1; i > 0; i--)
			arr[i][here_j] = 0;
	}

	here_i = v[cnt].first + 1;

	for (; here_i <= N; here_i++)
	{
		if (arr[here_i][here_j])
			break;
	}

	if (here_i == N + 1)
	{
		for (int i = v[cnt].first + 1; i <= N; i++)
			arr[i][here_j] = 1;
		backtracking(cnt + 1, complete + 1, sum + (N - v[cnt].first));
		for (int i = v[cnt].first + 1; i <= N; i++)
			arr[i][here_j] = 0;
	}

	here_i = v[cnt].first, here_j = v[cnt].second - 1;

	for (; here_j > 0; here_j--)
	{
		if (arr[here_i][here_j])
			break;
	}

	if (here_j == 0)
	{
		for (int j = 1; j <= v[cnt].second - 1; j++)
			arr[here_i][j] = 1;
		backtracking(cnt + 1, complete + 1, sum + v[cnt].second - 1);
		for (int j = 1; j <= v[cnt].second - 1; j++)
			arr[here_i][j] = 0;
	}

	here_j = v[cnt].second + 1;

	for (; here_j <= N; here_j++)
	{
		if (arr[here_i][here_j])
			break;
	}

	if (here_j == N + 1)
	{
		for (int j = v[cnt].second + 1; j <= N; j++)
			arr[here_i][j] = 1;
		backtracking(cnt + 1, complete + 1, sum + (N - v[cnt].second));
		for (int j = v[cnt].second + 1; j <= N; j++)
			arr[here_i][j] = 0;
	}

	backtracking(cnt + 1, complete, sum);
}

int main()
{
	ios::sync_with_stdio(false);

	cin >> T;
	for (int t = 1; t <= T; t++)
	{
		memset(arr, 0, sizeof(arr));
		ret_sum = MAX;
		ret_complete = 0;
		v.clear();
		cin >> N;
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				cin >> arr[i][j];
				if (arr[i][j])
				{
					if (i > 1 && i < N && j>1 && j < N)
						v.push_back({ i,j });
				}
			}
		}

		if (v.empty())
			printf("#%d 0\n", t);
		else
		{
			backtracking(0, 0, 0);
			printf("#%d %d\n", t, ret_sum);
		}
	}
	return 0;
}