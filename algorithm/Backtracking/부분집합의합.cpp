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

int N, S;
int arr[21];
int dp[21][1000001];

int solve(int n, int sum)
{
	if (n== N && sum == S)
		return 1;
	if (n == N)
		return 0;

	int& ret = dp[n][sum];
	if (ret != -1)
		return ret;

	ret = 0;
	ret += solve(n + 1, sum);
	ret += solve(n + 1, sum + arr[n]);

	return ret;
}

int main()
{
	memset(dp, -1, sizeof(dp));
	cin >> N >> S;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	int ret = solve(0, 0);
	if (S == 0)
		cout << ret - 1 << endl;
	else
		cout << ret << endl;

	return 0;
}