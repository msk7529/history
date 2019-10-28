#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
#include <utility>
#include <map>
#include <set>
#define MAX 987654321
#define MOD 1000000007
using namespace std;
typedef unsigned long long ul;
// baekjoon

int arr[5][9];
char arr2[5][9];
int num[13];

bool check()
{
	int sum = arr[0][4] + arr[1][3] + arr[2][2] + arr[3][1];
	int sum2 = arr[3][1] + arr[3][3] + arr[3][5] + arr[3][7];
	int sum3 = arr[0][4] + arr[1][5] + arr[2][6] + arr[3][7];
	int sum4 = arr[1][1] + arr[1][3] + arr[1][5] + arr[1][7];
	int sum5 = arr[1][1] + arr[2][2] + arr[3][3] + arr[4][4];
	int sum6 = arr[1][7] + arr[2][6] + arr[3][5] + arr[4][4];

	if (sum == sum2 && sum == sum3 && sum == sum4 && sum == sum5 && sum == sum6)
		return true;
	return false;
}

int backtracking(int a, int b)
{
	if (a < 5 && b >= 9)
		return backtracking(a + 1, 0);

	if (a == 5 && b == 0)
	{
		if (check())
			return 1;
		return 0;
	}

	int ret = 0;
	if (arr[a][b] != -1)
		ret += backtracking(a, b + 1);
	else
	{
		for (int i = 1; i <= 12; i++)
		{
			if (num[i] == 0)
			{
				arr[a][b] = i;
				num[i] = 1;
				ret += backtracking(a, b + 1);
				if (ret)
					return 1;
				num[i] = 0;
				arr[a][b] = -1;
			}
		}
	}
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);

	num[0] = 1;

	char a;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> a;
			if (a == '.')
				arr[i][j] = 0;
			else if (a == 'x')
				arr[i][j] = -1;
			else
			{
				int n = a - 'A' + 1;
				arr[i][j] = n;
				num[n] = 1;
			}
		}
	}
	
	backtracking(0, 0);
	
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (arr[i][j] == 0)
				arr2[i][j] = '.';
			else
				arr2[i][j] = 'A' + arr[i][j] - 1;
		}
	}

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 9; j++)
			printf("%c", arr2[i][j]);
		printf("\n");
	}
	return 0;
}