#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
// algospot

int C, N, K, M, L;
int sunsu[13];	// i��° ������ ���������� ����
int Ri, num;
int hakgi[13];	// i��° �б⿡ �����Ǵ� ������ ����
int Ci;
int dp[11][1 << 13];

int solve(int m, int set)
{
	if (__popcnt(set) >= K && m <= M)	// k�� �̻��� ������ �̹� �������
		return 0;
	if (m == M)		// m�бⰡ ���� �������
		return 100;


	int& ret = dp[m][set];
	if (ret != -1)
		return ret;
	ret = 100;

	ret = min(ret, solve(m + 1, set));	// �̹��б⸦ �������� �ʴ� ���

	int canTake = (hakgi[m] & ~set);	// �̹��б⿡ ���� �� �ִ� ���� �� ���� ���� ���� ������ �ɷ�����.

	for (int i = 0; i < N; i++)		// canTake���� ���������� �� ���� ���� ������� �ɷ�����.
	{
		if ((canTake & (1 << i)) && (set & sunsu[i]) != sunsu[i])
			canTake &= ~(1 << i);  // ������.
	}

	for (int i = canTake; i > 0; i = ((i - 1) & canTake))
	{
		if (__popcnt(i) > L)	// ���б⿡ L��������� ���� �� �ִ�.
			continue;
		ret = min(ret, 1 + solve(m + 1, set | i));
	}
	return ret;
}

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> C;

	while (C--)
	{
		memset(sunsu, 0, sizeof(sunsu));
		memset(dp, -1, sizeof(dp));
		memset(hakgi, 0, sizeof(hakgi));
		cin >> N >> K >> M >> L;
		for (int i = 0; i < N; i++)
		{
			cin >> Ri;
			for (int j = 0; j < Ri; j++)
			{
				cin >> num;
				sunsu[i] |= (1 << num);
			}
		}
		for (int i = 0; i < M; i++)
		{
			cin >> Ci;
			for (int j = 0; j < Ci; j++)
			{
				cin >> num;
				hakgi[i] |= (1 << num);
			}
		}

		int result = solve(0, 0);
		if (result < 100)
			cout << result << endl;
		else
			cout << "IMPOSSIBLE" << endl;
	}
	return 0;
}