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

int N, K, M;
queue<int> q;
int visit[1000001];

int bfs()
{
	while (K--)
	{
		int qsize = q.size();
		memset(visit, 0, sizeof(visit));
		for (int i = 0; i < qsize; i++)
		{
			int num = q.front();
			q.pop();
			string s = to_string(num);
			for (int j = 0; j < M - 1; j++)
			{
				for (int k = j + 1; k < M; k++)
				{
					if (j > 0 || s[k] != '0')
					{
						string tmp = s;
						swap(tmp[j], tmp[k]);
						int next = stoi(tmp);
						if (visit[next] == 0)
						{
							q.push(next);
							visit[next] = 1;
						}
					}
				}
			}
		}
	}
	int result = 0;
	while (!q.empty())
	{
		result = max(result, q.front());
		q.pop();
	}
	
	/*int n = (to_string(result)).length();
	if (n != M)
		return -1;*/
	string n = to_string(result);
	if (n[0] == '0')
		return -1;
	else
		return result;
}

int main()
{
	memset(visit, 0, sizeof(visit));
	cin >> N >> K;
	string s = to_string(N);
	M = s.length();
	q.push(N);

	cout << bfs() << endl;

	return 0;
}