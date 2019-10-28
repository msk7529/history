#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
// algospot

int C, n;
int tri[101][101];
int dp[101][101];
int dp2[101][101];

int solve(int a, int b)
{
	if (a == n)
		return 0;

	int& ret = dp[a][b];
	if (ret != -1)
		return ret;
	ret = 0;

	return ret = tri[a][b] + max(solve(a + 1, b), solve(a + 1, b + 1));
}

int solve2(int a, int b)
{
	if (a == n-1)
		return 1;

	int& ret = dp2[a][b];
	if (ret != -1)
		return ret;
	ret = 0;

	if (solve(a + 1, b) > solve(a + 1, b + 1))
		ret = solve2(a + 1, b);
	else if (solve(a + 1, b) < solve(a + 1, b + 1))
		ret = solve2(a + 1, b + 1);
	else
	{
		ret = solve2(a + 1, b) + solve2(a + 1, b + 1);
	}
	return ret;

	/*if (solve(a + 1, b) >= solve(a + 1, b + 1))
		ret += solve2(a + 1, b);
	if (solve(a + 1, b) <= solve(a + 1, b + 1))
		ret += solve2(a + 1, b + 1);

	return ret;*/
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
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j <= i; j++)
				cin >> tri[i][j];
		}
		cout << solve2(0, 0) << endl;

	}
	return 0;
}