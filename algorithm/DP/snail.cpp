#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
// algospot

int C, n, m;
double dp[1001][1001];

double solve(int a, int b)	// a : ���� �칰�� ����, b : ���� �ϼ�
{
	if (a <= 0)
		return 1;
	if (b <= 0)
		return 0;

	double& ret = dp[a][b];
	if (ret != -1)
		return ret;
	ret = 0;

	return ret = 0.75*solve(a - 2, b - 1) + 0.25*solve(a - 1, b - 1);
}

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> C;

	while (C--)
	{
		cin >> n >> m;
		for (int i = 0; i <= n; i++)	// �Ʒ�ó�� solve�Լ��� n,m�� �־�� �ɰ��, �ݵ�� i�� j�� ������ n,m�� ���Խ��Ѿ��Ѵ�.
		{
			for (int j = 0; j <= m; j++)
				dp[i][j] = -1;
		}
		cout.precision(10);
		cout << solve(n, m) << endl;
	}
	return 0;
}