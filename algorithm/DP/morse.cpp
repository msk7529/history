#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#define M 1000000100
using namespace std;
// algospot

int C, n, m, k;
int bino[202][202];
string s;

string solve(int a, int b, int skip)
{
	if (a == 0)		// 남은 n의 개수가 0이라면 나머지는 전부 "o"으로 채워진다.
		return string(b, 'o');

	if (skip < bino[a + b - 1][a - 1])
		return "-" + solve(a - 1, b, skip);
	else
		return "o" + solve(a, b - 1, skip - bino[a + b - 1][a - 1]);
}

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> C;
	memset(bino, 0, sizeof(bino));
	for (int i = 0; i <= 200; i++)
	{
		bino[i][0] = bino[i][i] = 1;
		for (int j = 1; j < i; j++)
			bino[i][j] = min(M, bino[i - 1][j - 1] + bino[i - 1][j]);
	}
	
	while (C--)
	{
		s = "";
		cin >> n >> m >> k;
		cout << solve(n, m, k-1) << endl;
	}
	return 0;
}