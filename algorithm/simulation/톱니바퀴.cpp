#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
#include <utility>
#include <list>
#define MAX 987654321
using namespace std;
typedef unsigned long long ul;
// sw expert

int arr[5][8];
int K, num, d;
int visit[5];
int change[5];

void effect(int n)
{
	if (n == 1)
	{
		if(!visit[2])
		{
			visit[2] = 1;
			if ((arr[1][2] ^ arr[2][6]))
			{
				change[2] = -1 * change[1];
				effect(2);
			}
		}
	}
	else if (n == 2)
	{
		if (!visit[1])
		{
			visit[1] = 1;
			if ((arr[1][2] ^ arr[2][6]))
				change[1] = -1 * change[2];
		}
		if (!visit[3])
		{
			visit[3] = 1;
			if ((arr[2][2] ^ arr[3][6]))
			{
				change[3] = -1 * change[2];
				effect(3);
			}
		}
	}
	else if (n == 3)
	{
		if (!visit[2])
		{
			visit[2] = 1;
			if ((arr[2][2] ^ arr[3][6]))
			{
				change[2] = -1 * change[3];
				effect(2);
			}
		}
		if (!visit[4])
		{
			visit[4] = 1;
			if ((arr[3][2] ^ arr[4][6]))
				change[4] = -1 * change[3];
		}
	}
	else if (n == 4)
	{
		if (!visit[3])
		{
			visit[3] = 1;
			if ((arr[3][2] ^ arr[4][6]))
			{
				change[3] = -1 * change[4];
				effect(3);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);

	char c;
	for (int i = 1; i < 5; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cin >> c;
			arr[i][j] = c - '0';
		}
	}
	cin >> K;
	while (K--)
	{
		cin >> num >> d;
		memset(visit, 0, sizeof(visit));
		memset(change, 0, sizeof(change));
		visit[num] = 1;
		change[num] = d;
		effect(num);

		int tmp_arr[5][8];
		for (int i = 1; i <= 4; i++)
		{
			for (int j = 0; j < 8; j++)
				tmp_arr[i][j] = arr[i][j];
		}

		for (int i = 1; i <= 4; i++)
		{
			if (visit[i])
			{
				if (change[i] == 1)
				{
					int tmp = arr[i][7];
					for (int j = 1; j <= 7; j++)
						arr[i][j] = tmp_arr[i][j - 1];
					arr[i][0] = tmp;
				}
				else if (change[i] == -1)
				{
					int tmp = arr[i][0];
					for (int j = 0; j <= 6; j++)
						arr[i][j] = tmp_arr[i][j + 1];
					arr[i][7] = tmp;
				}
			}
		}
	}
	
	int score = 0;
	for (int i = 1; i <= 4; i++)
	{
		if (arr[i][0])
			score += pow(2, i - 1);
	}
	cout << score << endl;
	return 0;
}