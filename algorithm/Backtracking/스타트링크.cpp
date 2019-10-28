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

int N;
int arr[21][21];
int visit[21];
int ret;

void comb(int start, int cnt)
{
	if (cnt == N / 2)
	{
		int sum = 0, sum2 = 0;
		vector<int> v, v2;

		for (int i = 0; i < N; i++)
		{
			if (visit[i])
				v.push_back(i);
			else
				v2.push_back(i);
		}


		for (int i = 0; i < v.size() - 1; i++)
		{
			for (int j = i+1; j < v.size(); j++)
			{
				sum += arr[v[i]][v[j]];
				sum += arr[v[j]][v[i]];
			}
		}
		for (int i = 0; i < v2.size() - 1; i++)
		{
			for (int j = i+1; j < v2.size(); j++)
			{
				sum2 += arr[v2[i]][v2[j]];
				sum2 += arr[v2[j]][v2[i]];
			}
		}
		ret = min(ret, abs(sum2 - sum));
		return;
	}

	for (int next = start + 1; next < N; next++)
	{
		visit[next] = 1;
		comb(next, cnt+1);
		visit[next] = 0;

		if (visit[0] == 0)
			break;
	}
}

int main()
{
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];
	}
	ret = MAX;
	comb(-1, 0);

	cout << ret << endl;
	return 0;
}