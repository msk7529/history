#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#define M 123456789
using namespace std;
// algospot

int C;
string s;
int dp[10005];

int nanido(int a)
{
	if (a == s.length())		// 중요
		return 0;

	if (a >= s.length()-2)		// 중요
		return M;

	int& ret = dp[a];
	if (ret != -1)
		return ret;

	ret = M;
	int tmp = s[a] - s[a + 1];
	int num = 2;
	for (int i = a+1; i < a + 4; i++)
	{
		if (s[i] - s[i + 1] == tmp)
			num++;
		else
			break;
	}

	if (num >= 3)
	{
		if (tmp == 0)
		{
			for (int i = 3; i <= num; i++)
				ret = min(ret, 1 + nanido(a + i));
		}
		else if (tmp == 1 || tmp == -1)
		{
			for (int i = 3; i <= num; i++)
				ret = min(ret, 2 + nanido(a + i));
		}
		else
		{
			for (int i = 3; i <= num; i++)
				ret = min(ret, 5 + nanido(a + i));
		}
	}
	else
	{
		int num2 = 2;
		tmp = s[a] - s[a + 1];
		for (int i = a + 1; i < a + 4; i++)
		{
			if (s[i] - s[i + 1] == -tmp)
			{
				num2++;
				tmp = -tmp;
			}
			else
				break;
		}
		if (num2 >= 3)
		{
			for (int i = 3; i <= num2; i++)
				ret = min(ret, 4 + nanido(a + i));
		}
	}

	for (int i = 3; i <= 5; i++)		// 중요 !!! else문에 같이 포함시키면 1213123 <-- 12가 아니고 14가 나옴
		ret = min(ret, 10 + nanido(a + i));

	return ret;
}

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> C;

	while (C--)
	{
		memset(dp, -1, sizeof(dp));
		cin >> s;

		cout << nanido(0) << endl;
	}
	return 0;
}