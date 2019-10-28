#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
// algospot

int c, n, m;
int price[21];
int priority[21];
int dp[201];	// �ʹ��� ������ �ִ� 20000�̰� 100�� ����̹Ƿ� 100���� ������, �ű�� 1�� ���Ͽ� ������ ũ�⸦ ���Ѵ�.

int solve()
{
	int ret = 0;
	dp[0] = 0;
	for (int budget = 1; budget <= m; budget++)
	{
		int cand = 0;
		for (int dish = 0; dish < n; dish++)
		{
			if(budget >= price[dish])
				cand = max(cand, dp[(budget - price[dish]) % 201] + priority[dish]);
		}
		dp[budget % 201] = cand;
		ret = max(ret, cand);
	}
	return ret;
}

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> c;

	while (c--)
	{
		cin >> n >> m;
		m /= 100;
		for (int i = 0; i < n; i++)
		{
			cin >> price[i] >> priority[i];
			price[i] /= 100;
		}

		cout << solve() << endl;
	}
	return 0;
}