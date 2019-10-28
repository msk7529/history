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
// baekjoon

int N, L;
int arr[101][101];
int add[101][101];
int ret;

int main()
{
	ios::sync_with_stdio(false);

	cin >> N >> L;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cin >> arr[i][j];
	}

	for (int i = 0; i < N; i++)		// 행검사
	{
		bool b = true;
		int now = arr[i][0];
		int j;
		for (j = 1; j < N; j++)
		{
			if (arr[i][j] > now)	// 지금도착한 블럭이 now보다 크면, 이전 L블럭을 탐색
			{
				if (arr[i][j] > now + 1)
				{
					b = false;
					break;
				}
				else
				{
					if (j - 1 - L < -1)
					{
						b = false;
						break;
					}

					for (int k = j - 1; k > j - 1 - L; k--)
					{
						if (add[i][k] || arr[i][k] != now)
						{
							b = false;
							break;
						}
					}
					if (!b)
						break;
					now = arr[i][j];
				}
			}
			else if (arr[i][j] < now)	// 지금도착한 블럭이 now보다 작으면, 지금블럭 포함 L블럭을 탐색
			{
				if (arr[i][j] < now - 1)
				{
					b = false;
					break;
				}
				else
				{
					if (j + L - 1 >= N)
					{
						b = false;
						break;
					}

					for (int k = j; k < j + L; k++)
					{
						if (arr[i][k] != now - 1)
						{
							b = false;
							break;
						}
						add[i][k] = 1;
					}
					if (!b)
						break;
					now = arr[i][j + L - 1];
					j += (L - 1);
				}
			}
		}
		if (b)
			ret++;
	}

	memset(add, 0, sizeof(add));

	for (int i = 0; i < N; i++)
	{
		bool b = true;
		int now = arr[0][i];
		int j;
		for (j = 1; j < N; j++)
		{
			if (arr[j][i] > now)	// 지금도착한 블럭이 now보다 크면, 이전 L블럭을 탐색
			{
				if (arr[j][i] > now + 1)
				{
					b = false;
					break;
				}
				else
				{
					if (j - 1 - L < -1)
					{
						b = false;
						break;
					}

					for (int k = j - 1; k > j - 1 - L; k--)
					{
						if (add[k][i] || arr[k][i] != now)
						{
							b = false;
							break;
						}
					}
					if (!b)
						break;
					now = arr[j][i];
				}
			}
			else if (arr[j][i] < now)	// 지금도착한 블럭이 now보다 작으면, 지금블럭 포함 L블럭을 탐색
			{
				if (arr[j][i] < now - 1)
				{
					b = false;
					break;
				}
				else
				{
					if (j + L - 1 >= N)
					{
						b = false;
						break;
					}

					for (int k = j; k < j + L; k++)
					{
						if (arr[k][i] != now - 1)
						{
							b = false;
							break;
						}
						add[k][i] = 1;
					}
					if (!b)
						break;
					now = arr[j + L - 1][i];
					j += (L - 1);
				}
			}
		}
		if (b)
			ret++;
	}

	cout << ret << endl;

	return 0;
}