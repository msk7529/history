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

int N, x, y, d, g;
int visit[200][200];

int main()
{
	ios::sync_with_stdio(false);

	cin >> N;
	while (N--)
	{
		vector<int> dist;
		cin >> x >> y >> d >> g;
		visit[x][y] = 1;
		
		if (d == 0)
			x++;
		else if (d == 1)
			y--;
		else if (d == 2)
			x--;
		else
			y++;
		visit[x][y] = 1;
		dist.push_back(d);

		while (g--)
		{
			int before_size = dist.size();
			for (int i = before_size - 1; i >= 0; i--)
			{
				if (dist[i] == 0)
				{
					y--;
					visit[x][y] = 1;
					dist.push_back(1);
				}
				else if (dist[i] == 1)
				{
					x--;
					visit[x][y] = 1;
					dist.push_back(2);
				}
				else if (dist[i] == 2)
				{
					y++;
					visit[x][y] = 1;
					dist.push_back(3);
				}
				else
				{
					x++;
					visit[x][y] = 1;
					dist.push_back(0);
				}
			}
		}
		dist.clear();
	}

	int ret = 0;
	for (int i = 0; i <= 99; i++)
	{
		for (int j = 0; j <= 99; j++)
		{
			if (visit[i][j] && visit[i][j + 1] && visit[i + 1][j] && visit[i + 1][j + 1])
				ret++;
		}
	}
	cout << ret << endl;
	return 0;
}