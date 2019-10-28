#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#define MOD 1000000007
using namespace std;
// algospot

int C, n;
int dp[101];
int dp2[101];

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

int solve2(int num)
{
	if (n % 2 == 1 && num == 1)
		return 1;
	if (n % 2 == 0 && num == 2)
		return 2;
	if (n % 2 == 0 && num == 0)
		return 1;
	if (num <= 0)
		return 0;

	int& ret = dp2[num];
	if (ret != -1)
		return ret;
	ret = 0;

	return ret = (solve2(num - 2) + solve2(num - 4)) % MOD;
}

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> C;

	while (C--)
	{
		memset(dp, -1, sizeof(dp));
		memset(dp2, -1, sizeof(dp2));
		cin >> n;
		cout << ((solve(n) + MOD) - solve2(n)) % MOD << endl;
	}
	return 0;
}