#include <iostream>
#include <cstring>
using namespace std;
// algospot

int C, n, m;
bool matched[10];
bool friPair[10][10];

int solve()
{
	int target = -1;
	int ret = 0;

	for (int i = 0; i < n; i++)
	{
		if (matched[i] == false)
		{
			target = i;
			break;
		}
	}

	if (target == -1)
		return 1;

	for (int i = target + 1; i < n; i++)
	{
		if (matched[i] == false && friPair[target][i] && friPair[i][target])
		{
			matched[i] = matched[target] = true;
			ret += solve();
			matched[i] = matched[target] = false;
		}
	}
	return ret;
}

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> C;

	while (C--)
	{
		for (int i = 0; i < 10; i++)
			matched[i] = false;
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
				friPair[i][j] = false;
		}

		cin >> n >> m;
		for (int i = 0; i < m; i++)
		{
			int st1, st2;
			cin >> st1 >> st2;
			friPair[st1][st2] = friPair[st2][st1] = true;
		}
		cout << solve() << endl;
	}
}