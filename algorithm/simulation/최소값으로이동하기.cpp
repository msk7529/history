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
#include <deque>
#include <time.h>
using namespace std;
// sw expert

int T, W, H, N;
int x, y, nx, ny;
pair<int, int> p[1001];

int main()
{
	//clock_t before = clock();

	cin >> T;
	for (int i = 1; i <= T; i++)
	{
		cin >> W >> H >> N;
		for (int j = 1; j <= N; j++)
			cin >> p[j].first >> p[j].second;

		int ret = 0;
		for (int i = 2; i <= N; i++)
		{
			x = p[i - 1].first, y = p[i - 1].second, nx = p[i].first, ny = p[i].second;
			if (x > nx && y > ny || x < nx && y < ny)
				ret += max(abs(x - nx), abs(y - ny));
			else
				ret += abs(x - nx) + abs(y - ny);
		}

		cout << "#" << i << " " << ret << endl;
	}


	//printf("걸린시간 : %6.5f\n", (double)(clock() - before) / CLOCKS_PER_SEC);

	return 0;
}

