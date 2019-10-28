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
// baekjoon

int cn, bn, target;		// 추의개수, 구슬의 개수, 구슬의 무게
int arr[31];
int dp[31][15001];

int solve(int n, int sum)
{
	if (sum == target)
		return 1;
	if (n == cn)
		return 0;

	int& ret = dp[n][sum];
	if (ret != -1)
		return ret;

	ret = 0;
	ret += solve(n + 1, sum + arr[n]);
	if (ret)
		return 1;
	ret += solve(n + 1, abs(sum - arr[n]));
	if (ret)
		return 1;
	ret += solve(n + 1, sum);

	return ret;
}

int main()
{
	ios::sync_with_stdio(false);

	cin >> cn;
	for (int i = 0; i < cn; i++)
		cin >> arr[i];
	cin >> bn;
	for (int i = 0; i < bn; i++)
	{
		memset(dp, -1, sizeof(dp));
		cin >> target;
		if (target > 15000)
		{
			printf("N ");
			continue;
		}
		int ret = solve(0, 0);
		if (ret)
			printf("Y ");
		else
			printf("N ");
	}
	return 0;
}