#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;
// baekjoon

double W, L, D;
double ret[5];
double dp[21][21][21][21];

int main()
{
	for (int i = 0; i <= 20; i++)
	{
		for (int j = 0; j <= 20; j++)
		{
			for (int k = 0; k <= 20; k++)
			{
				for (int z = 0; z <= 20; z++)
					dp[i][j][k][z] = 1;
			}
		}
	}

	ios::sync_with_stdio(false);

	cin >> W >> L >> D;

	for (int i = 1; i <= 20; i++)
	{
		for (int w = 0; w <= i; w++)
		{
			for (int l = 0; w + l <= i; l++)
			{
				int d = i - w - l;
				double a = 0, b = 0, c = 0;
				if (w != 0)
					a = dp[i - 1][w - 1][l][d];
				if (l != 0)
					b = dp[i - 1][w][l - 1][d];
				if (d != 0)
					c = dp[i - 1][w][l][d - 1];
				dp[i][w][l][d] = W*a + L*b + D*c;
			}
		}
	}

	for (int i = 0; i <= 20; i++)
	{
		for (int j = 0; i + j <= 20; j++)
		{
			int k = 20 - i - j;
			int score = 2000 + (50 * i) - (50 * j);
			double tmp = dp[20][i][j][k];

			if (score >= 1000 && score < 1500)
				ret[0] += tmp;
			else if (score >= 1500 && score < 2000)
				ret[1] += tmp;
			else if (score >= 2000 && score < 2500)
				ret[2] += tmp;
			else if (score >= 2500 && score < 3000)
				ret[3] += tmp;
			else if (score >= 3000 && score < 3500)
				ret[4] += tmp;
		}
	}

	for (int i = 0; i < 5; i++)
		printf("%.8f\n", ret[i]);

	return 0;
}