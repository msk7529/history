#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
// algospot

int C, n;
int triangle[101][101];
int dp[101][101];

int solve(int i, int j)
{
	if (i == n)
		return 0;

	int& ret = dp[i][j];
	if (ret != -1)
		return ret;

	return ret = max(triangle[i][j] + solve(i + 1, j), triangle[i][j] + solve(i + 1, j + 1));
}

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> C;

	while (C--)
	{
		memset(dp, -1, sizeof(dp));
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j <= i; j++)
				cin >> triangle[i][j];
		}
		cout << solve(0, 0) << endl;
	}
	return 0;
}