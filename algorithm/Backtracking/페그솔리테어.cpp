#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <stack>
#include <string>
#include <utility>
#include <cmath>
#include <map>
using namespace std;
// baekjoon

int N;
char arr[15][15];
int visit[15][15];
int point[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };
int ret, ret2;

void backtracking(int pinNum, int cnt)
{
	for (int i = 2; i < 7; i++)
	{
		for (int j = 2; j < 11; j++)
		{
			if (arr[i][j] == 'o')
			{
				for (int k = 0; k < 4; k++)
				{
					int ny = i + point[k][0], nx = j + point[k][1];
					int ny2 = ny + point[k][0], nx2 = nx + point[k][1];
					if (arr[ny][nx] == 'o' && arr[ny2][nx2] == '.')
					{
						arr[i][j] = '.', arr[ny][nx] = '.', arr[ny2][nx2] = 'o';
						backtracking(pinNum - 1, cnt + 1);
						arr[i][j] = 'o', arr[ny][nx] = 'o', arr[ny2][nx2] = '.';
					}
				}
			}
		}
	}

	if (ret > pinNum)
	{
		ret = pinNum;
		ret2 = cnt;
	}
}

int main()
{
	cin >> N;
	while (N--)
	{
		memset(arr, 0, sizeof(arr));
		ret = 987654321, ret2 = 0;
		int pinNum = 0;
		for (int i = 2; i < 7; i++)
		{
			for (int j = 2; j < 11; j++)
			{
				cin >> arr[i][j];
				if (arr[i][j] == 'o')
					pinNum++;
			}
		}
		backtracking(pinNum, 0);
		cout << ret << " " << ret2 << endl;
	}
	return 0;
}