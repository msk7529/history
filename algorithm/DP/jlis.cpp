#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
// algospot

int c, n, m;
int A[101];
int B[101];
int dp[101][101];
const long long NEGINF = numeric_limits<long long>::min();

int solve(int a, int b)
{
	int& ret = dp[a][b];
	if (ret != -1)
		return ret;
	ret = 2;

	long long aa = (a == -1 ? NEGINF : A[a]);
	long long bb = (b == -1 ? NEGINF : B[b]);
	long long maxElement = max(aa, bb);
	
	for (int i = a + 1; i < n; i++)
	{
		if (maxElement < A[i])
			ret = max(ret, solve(i, b) + 1);
	}
	for (int j = b + 1; j < m; j++)
	{
		if (maxElement < B[j])
			ret = max(ret, solve(a, j) + 1);
	}
	return ret;
}

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> c;

	while (c--)
	{
		memset(dp, -1, sizeof(dp));
		cin >> n >> m;
		for (int i = 0; i < n; i++)
			cin >> A[i];
		for (int j = 0; j < m; j++)
			cin >> B[j];

		cout << solve(-1, -1) - 2 << endl;
	}
	return 0;
}