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

int point[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };
queue<int> q;
map<int, int> m;

int bfs()
{
	while (!q.empty())
	{
		int num = q.front();
		q.pop();

		if (num == 123456789)
			return m[123456789];

		string s = to_string(num);

		int index = s.find('9');
		int y = index / 3, x = index % 3;
		for (int i = 0; i < 4; i++)
		{
			int ny = y + point[i][0], nx = x + point[i][1];
			if (ny >= 0 && ny < 3 && nx >= 0 && nx < 3)
			{
				int target_index = 3 * ny + nx;
				string tmp = s;
				swap(tmp[index], tmp[target_index]);
				int next = stoi(tmp);
				if (m[next] == 0)
				{
					m[next] = m[num] + 1;
					q.push(next);
				}
			}
		}
	}
	return -1;
}

int main()
{
	int start = 0;
	int num;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> num;
			if (num == 0)
				num = 9;
			start = start * 10 + num;
		}
	}
	m[start] = 0;
	q.push(start);

	cout << bfs() << endl;

	return 0;
}