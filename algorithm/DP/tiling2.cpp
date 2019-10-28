#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#define MOD 1000000007
using namespace std;
// algospot

int C, n;
int dp[101];

int solve(int num)
{
	if (num == 0)
		return 1;
	if (num < 0)
		return 0;

	int& ret = dp[num];
	if (ret != -1)
		return ret;
	ret = 0;

	return ret = (solve(num - 1) + solve(num - 2)) % MOD;
}

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> C;

	while (C--)
	{
		memset(dp, -1, sizeof(dp));
		cin >> n;
		cout << solve(n) << endl;
	}
	return 0;
}