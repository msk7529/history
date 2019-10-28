#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#define EMPTY -987654321
using namespace std;
// algospot

int C, n;
int board[51];
int dp[51][51];

int solve(int left, int right)	// ���� �����ǿ� ���� ������ state(left�� right�� ����)�� �� �̹� ������ �������� ���� - �ٸ� �������� ������ �ִ�ġ�� ��ȯ
{
	if (left > right)	// ��� ���� �� �������� ��.
		return 0;

	int& ret = dp[left][right];
	if (ret != EMPTY)
		return ret;

	ret = max(board[left] - solve(left + 1, right), board[right] - solve(left, right - 1));		// ���� �������� ���

	if (right - left + 1 >= 2)	// ���� ���ִ� ���
	{
		ret = max(ret, -solve(left + 2, right));
		ret = max(ret, -solve(left, right - 2));
	}
	return ret;
}

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> C;

	while (C--)
	{
		cin >> n;
		for (int i = 0; i <= n; i++)
		{
			for (int j = 0; j <= n; j++)
				dp[i][j] = EMPTY;
		}
		for (int i = 0; i < n; i++)
			cin >> board[i];
		cout << solve(0, n - 1) << endl;
	}
	return 0;
}