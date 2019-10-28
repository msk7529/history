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

int N, M, X, Y, T, A, K;
int H[101];
int dp[101][501];
vector<int> adj[101];

int solve(int pos, int cnt)
{
	if (cnt == 0)
		return H[pos];

	int& ret = dp[pos][cnt];
	if (ret != -1)
		return ret;

	ret = MAX;
	for (int next : adj[pos])
		ret = min(ret, solve(next, cnt - 1));
	return ret;
}

int main()
{
	memset(dp, -1, sizeof(dp));
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
		cin >> H[i];
	
	for (int i = 1; i <= M; i++)
	{
		cin >> X >> Y;
		adj[X].push_back(Y);
		adj[Y].push_back(X);
	}

	cin >> T;
	while (T--)
	{
		cin >> A >> K;
		int ret = solve(A, K);
		if (ret == MAX)
			printf("-1\n");
		else
			printf("%d\n", ret);
	}
	return 0;
}