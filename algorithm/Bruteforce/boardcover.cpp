#include <iostream>
#include <cstring>
using namespace std;
// algospot

int C, H, W;
int cnt;
char board[21][21];

bool check()							// board�� ��� ���������� �ٲ������ üũ.
{
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (board[i][j] == '.')
				return false;
		}
	}
	return true;
}

int solve(int a, int b)
{
	if (a >= H)
		return check() ? 1 : 0;			// �������. check()�Լ��� ���̸� 1�� ��ȯ, �ƴϸ� 0�� ��ȯ

	if (b >= W)
		return solve(a + 1, 0);

	int ret = 0;

	if (board[a][b] == '#')
		return solve(a, b + 1);
	else
	{
		if (a + 1 < H && b + 1 < W && board[a + 1][b] == '.' && board[a + 1][b + 1] == '.')
		{
			board[a][b] = board[a + 1][b] = board[a + 1][b + 1] = '#';
			ret += solve(a, b + 1);
			board[a][b] = board[a + 1][b] = board[a + 1][b + 1] = '.';
		}
		if (a + 1 < H && b + 1 < W && board[a][b + 1] == '.' && board[a + 1][b] == '.')
		{
			board[a][b] = board[a][b + 1] = board[a + 1][b] = '#';
			ret += solve(a, b + 2);
			board[a][b] = board[a][b + 1] = board[a + 1][b] = '.';
		}
		if (a + 1 < H && b + 1 < W && board[a][b + 1] == '.' && board[a + 1][b + 1] == '.')
		{
			board[a][b] = board[a][b + 1] = board[a + 1][b + 1] = '#';
			ret += solve(a, b + 2);
			board[a][b] = board[a][b + 1] = board[a + 1][b + 1] = '.';
		}
		if (a + 1 < H && b > 0 && board[a + 1][b] == '.' && board[a + 1][b - 1] == '.')
		{
			board[a][b] = board[a + 1][b] = board[a + 1][b - 1] = '#';
			ret += solve(a, b + 1);
			board[a][b] = board[a + 1][b] = board[a + 1][b - 1] = '.';
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
		cnt = 0;
		cin >> H >> W;
		for (int i = 0; i < H; i++)
		{
			for (int j = 0; j < W; j++)
			{
				cin >> board[i][j];
				if (board[i][j] == '.')
					cnt++;
			}
		}

		if (cnt % 3 != 0)
			cout << "0" << endl;
		else
			cout << solve(0, 0) << endl;
	}
}