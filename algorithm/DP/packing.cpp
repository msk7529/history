#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
// algospot

int C, N, W;
string thing[101];
int vupy[101];
int julbak[101];
int choice[101];
vector<string> result;
int dp[101][1001];

int solve(int a, int b)
{
	if (a == N)
		return 0;

	int& ret = dp[a][b];
	if (ret != -1)
		return ret;
	ret = 0;

	ret = solve(a + 1, b);

	if (b - vupy[a] >= 0)
		ret = max(ret, julbak[a] + solve(a + 1, b - vupy[a]));

	return ret;
}

void makeResult(int a, int b)
{
	if (a == N)
		return;

	if (solve(a, b) == solve(a + 1, b))
		makeResult(a + 1, b);
	else
	{
		result.push_back(thing[a]);
		makeResult(a + 1, b - vupy[a]);
	}
}

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> C;

	while (C--)
	{
		memset(dp, -1, sizeof(dp));
		result.clear();
		cin >> N >> W;
		for (int i = 0; i < N; i++)
			cin >> thing[i] >> vupy[i] >> julbak[i];

		solve(0, W);
		makeResult(0, W);
		cout << solve(0, W) << " " << result.size() << endl;
		for (int i = 0; i < result.size(); i++)
			cout << result[i] << endl;
	}
	return 0;
}