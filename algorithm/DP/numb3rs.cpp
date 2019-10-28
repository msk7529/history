#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int c, n, d, p, t, q;
vector<int> adj[51];
double dp[51][101];

double solve(int tg, int td)
{
	if (td == d && tg == q)
		return 1;
	if (td == d && tg != q)
		return 0;

	double& ret = dp[tg][td];
	if (ret != -1)
		return ret;
	ret = 0;

	for (int i = 0; i < adj[tg].size(); i++)
		ret += (double)1 / (double)adj[tg].size() * solve(adj[tg][i], td + 1);	// double로 형변환안할시 답이 0으로 나옴.

	return ret;
}

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> c;

	while (c--)
	{
		cin >> n >> d >> p;
		for (int i = 0; i <= n; i++)
			adj[i].clear();
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				int tmp;
				cin >> tmp;
				if (tmp == 1)
					adj[i].push_back(j);
			}
		}
		cin >> t;
		for (int i = 0; i < t; i++)
		{
			for (int j = 0; j <= n; j++)
			{
				for (int z = 0; z <= d; z++)
					dp[j][z] = -1;
			}
			cin >> q;
			cout.precision(10);				// 이것 안쓰면 오답.
			cout << solve(p, 0) << " ";
		}
		cout << endl;
	}
	return 0;
}