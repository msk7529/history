#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <stack>
#include <utility>
#include <cmath>
using namespace std;
// baekjoon

int N;
int arr[101][101];
long long dp[101][101];

long long dfs(int a, int b)
{
	if (a >= N || b >= N)
		return 0;
	if (a == N - 1 && b == N - 1)
		return 1;

	long long& ret = dp[a][b];
	if (ret != -1)
		return ret;
	ret = 0;

	ret += dfs(a, b + arr[a][b]);
	ret += dfs(a + arr[a][b], b);

	return ret;
}

int main()
{
	cin >> N;
	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];
	}

	cout << dfs(0, 0) << endl;

	return 0;
}