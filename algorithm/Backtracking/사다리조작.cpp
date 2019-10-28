#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <deque>
#include <algorithm>
#include <queue>
#include <functional>
#include <utility>
#include <list>
#define MAX 987654321
using namespace std;
typedef unsigned long long ul;
// sw expert

int N, M, H, a, b;
int ladder[12][32];
int ret = MAX;

int goDown(int n, int h)
{
	if (h == H + 1)
		return n;

	if (ladder[n][h] == 1)
		return goDown(n + 1, h + 1);
	else if (ladder[n][h] == -1)
		return goDown(n - 1, h + 1);
	else
		return goDown(n, h + 1);
}

bool check()
{
	for (int i = 1; i <= N; i++)
	{
		if (goDown(i, 1) != i)
			return false;
	}
	return true;
}

//void backtracking(int cnt, int sh, int sn)
//{
//	if (cnt == 3 || cnt >= ret)
//		return;
//
//	int tn, th;
//	for (th = sh; th <= H; th++)
//	{
//		for (tn = sn; tn < N; tn++)
//		{
//			if (ladder[tn][th] != 1 && ladder[tn][th] != -1 && ladder[tn+1][th] != -1 && ladder[tn+1][th] != 1)
//			{
//				ladder[tn][th] = 1;
//				ladder[tn + 1][th] = -1;
//				if (check())
//				{
//					ret = min(ret, cnt + 1);
//					ladder[tn][th] = 0;
//					ladder[tn + 1][th] = 0;
//					return;
//				}
//				else
//				{
//					if (tn == N - 1)
//						backtracking(cnt + 1, th + 1, 1);
//					else
//						backtracking(cnt + 1, th, tn + 1);
//					ladder[tn][th] = 0;
//					ladder[tn + 1][th] = 0;
//				}
//			}
//		}
//	}
//}

int main()
{
	ios::sync_with_stdio(false);

	cin >> N >> M >> H;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		ladder[b][a] = 1;		//  ¿À¸¥ÂÊ
		ladder[b + 1][a] = -1;	//  ¿ÞÂÊ
	}
	
	if (check())
		cout << "0" << endl;
	else
	{
		vector<pair<int, int>> v1;
		for (int h = 1; h <= H; h++)
		{
			for (int n = 1; n < N; n++)
				v1.push_back({ n,h });
		}

		for (int i = 0; i < v1.size(); i++)
		{
			if (ladder[v1[i].first][v1[i].second] != 1 && ladder[v1[i].first][v1[i].second] != -1 && ladder[v1[i].first + 1][v1[i].second] != 1 && ladder[v1[i].first + 1][v1[i].second] != -1)
			{
				ladder[v1[i].first][v1[i].second] = 1;
				ladder[v1[i].first + 1][v1[i].second] = -1;
				if (check())
				{
					cout << "1" << endl;
					return 0;
				}
				ladder[v1[i].first][v1[i].second] = 0;
				ladder[v1[i].first + 1][v1[i].second] = 0;
			}
		}

		for (int i = 0; i < v1.size() - 1; i++)
		{
			for (int j = i + 1; j < v1.size(); j++)
			{
				if (ladder[v1[i].first][v1[i].second] != 1 && ladder[v1[i].first][v1[i].second] != -1 && ladder[v1[i].first + 1][v1[i].second] != 1 && ladder[v1[i].first + 1][v1[i].second] != -1
					&& ladder[v1[j].first][v1[j].second] != 1 && ladder[v1[j].first][v1[j].second] != -1 && ladder[v1[j].first + 1][v1[j].second] != 1 && ladder[v1[j].first + 1][v1[j].second] != -1)
				{
					ladder[v1[i].first][v1[i].second] = 1;
					ladder[v1[i].first + 1][v1[i].second] = -1;
					ladder[v1[j].first][v1[j].second] = 1;
					ladder[v1[j].first + 1][v1[j].second] = -1;
					if (check())
					{
						cout << "2" << endl;
						return 0;
					}
					ladder[v1[i].first][v1[i].second] = 0;
					ladder[v1[i].first + 1][v1[i].second] = 0;
					ladder[v1[j].first][v1[j].second] = 0;
					ladder[v1[j].first + 1][v1[j].second] = 0;
				}
			}
		}

		for (int i = 0; i < v1.size() - 2; i++)
		{
			for (int j = i + 1; j < v1.size() - 1; j++)
			{
				for (int k = j + 1; k < v1.size(); k++)
				{
					if (ladder[v1[i].first][v1[i].second] != 1 && ladder[v1[i].first][v1[i].second] != -1 && ladder[v1[i].first + 1][v1[i].second] != 1 && ladder[v1[i].first + 1][v1[i].second] != -1
						&& ladder[v1[j].first][v1[j].second] != 1 && ladder[v1[j].first][v1[j].second] != -1 && ladder[v1[j].first + 1][v1[j].second] != 1 && ladder[v1[j].first + 1][v1[j].second] != -1
						&& ladder[v1[k].first][v1[k].second] != 1 && ladder[v1[k].first][v1[k].second] != -1 && ladder[v1[k].first + 1][v1[k].second] != 1 && ladder[v1[k].first + 1][v1[k].second] != -1)
					{
						ladder[v1[i].first][v1[i].second] = 1;
						ladder[v1[i].first + 1][v1[i].second] = -1;
						ladder[v1[j].first][v1[j].second] = 1;
						ladder[v1[j].first + 1][v1[j].second] = -1;
						ladder[v1[k].first][v1[k].second] = 1;
						ladder[v1[k].first + 1][v1[k].second] = -1;
						if (check())
						{
							cout << "3" << endl;
							return 0;
						}
						ladder[v1[i].first][v1[i].second] = 0;
						ladder[v1[i].first + 1][v1[i].second] = 0;
						ladder[v1[j].first][v1[j].second] = 0;
						ladder[v1[j].first + 1][v1[j].second] = 0;
						ladder[v1[k].first][v1[k].second] = 0;
						ladder[v1[k].first + 1][v1[k].second] = 0;
					}
				}
			}
		}
		cout << "-1" << endl;
	}
	return 0;
}