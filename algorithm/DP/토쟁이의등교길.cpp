#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <functional>
#define MAX 987654321
using namespace std;
// baekjoon

int dp[201][201];
int w, h, x, y;

int main()
{
	ios::sync_with_stdio(false);

	cin >> w >> h >> x >> y;

	dp[1][1] = 1;
	for (int i = 1; i <= w; i++)
	{
		for (int j = 1; j <= h; j++)
		{
			if (i == 1 && j == 1)
				continue;
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000007;
		}
	}

	int ret = dp[x][y];
	int next_x = w - x + 1, next_y = h - y + 1;
	ret *= dp[next_x][next_y];
	ret %= 1000007;

	cout << ret << endl;

	return 0;
}