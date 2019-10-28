#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
// algospot

int C, N, K, M, L;
int sunsu[13];	// i번째 과목의 선수과목의 집합
int Ri, num;
int hakgi[13];	// i번째 학기에 개설되는 과목의 집합
int Ci;
int dp[11][1 << 13];

int solve(int m, int set)
{
	if (__popcnt(set) >= K && m <= M)	// k개 이상의 과목을 이미 들은경우
		return 0;
	if (m == M)		// m학기가 전부 지난경우
		return 100;


	int& ret = dp[m][set];
	if (ret != -1)
		return ret;
	ret = 100;

	ret = min(ret, solve(m + 1, set));	// 이번학기를 수강하지 않는 경우

	int canTake = (hakgi[m] & ~set);	// 이번학기에 들을 수 있는 과목 중 아직 듣지 않은 과목을 걸러낸다.

	for (int i = 0; i < N; i++)		// canTake에서 선수과목을 다 듣지 않은 과목들을 걸러낸다.
	{
		if ((canTake & (1 << i)) && (set & sunsu[i]) != sunsu[i])
			canTake &= ~(1 << i);  // 차집합.
	}

	for (int i = canTake; i > 0; i = ((i - 1) & canTake))
	{
		if (__popcnt(i) > L)	// 한학기에 L과목까지만 들을 수 있다.
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