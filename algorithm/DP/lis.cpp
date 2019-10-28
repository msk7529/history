#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
// algospot

int C, N;
int num[501];
int dp[501];

int solve(int n)
{
	if (n == N - 1)
		return 1;

	int& ret = dp[n + 1];
		if (ret != -1)
		return ret;
	ret = 1;

	for (int i = n + 1; i < N; i++)
	{
		if (n == -1 || num[n] < num[i])
			ret = max(ret, 1 + solve(i));
	}
	return ret;
}

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> C;

	while (C--)
	{
		memset(dp, -1, sizeof(dp));
		cin >> N;
		for (int i = 0; i < N; i++)
			cin >> num[i];
		int result = 0;
		/*for (int i = 0; i < N; i++)
			result = max(result, solve(i));*/
		cout << solve(-1) -1  << endl;
	}
}