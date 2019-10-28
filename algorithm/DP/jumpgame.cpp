#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
// algospot

int C, n;
int gameboard[101][101];
int dp[101][101];

int solve(int i, int j)
{
	if (i >= n || j >= n)
		return 0;
	if (i == n - 1 && j == n - 1)
		return 1;

	int& ret = dp[i][j];
	if (ret != -1)
		return ret;

	int jumpNum = gameboard[i][j];

	ret = max(solve(i + jumpNum, j), solve(i, j + jumpNum));

	return ret;
}

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> C;

	while (C--)
	{
		cin >> n;
		memset(dp, -1, sizeof(dp));

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				cin >> gameboard[i][j];
		}
		if (solve(0, 0))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}