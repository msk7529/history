#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
#include <utility>
#define MAX 987654321
#define MOD 1000000007
using namespace std;
typedef unsigned long long ul;
// baekjoon

int K, N, F;
int matched[901][901];
bool f;
vector<int> result;

void dfs(int here)
{
	if (f == true)
		return;

	result.push_back(here);

	if (result.size() == K)
	{
		f = true;
		return;
	}
	else
	{
		for (int next = here + 1; next <= N; next++)
		{
			if (f)
				return;

			bool check = true;
			for (int i = 0; i < result.size(); i++)
			{
				if (matched[result[i]][next] == 0)
				{
					check = false;
					break;
				}
			}
			if (check)
				dfs(next);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	f = false;

	cin >> K >> N >> F;
	int a, b;
	for (int i = 0; i < F; i++)
	{
		cin >> a >> b;
		matched[a][b] = 1;
		matched[b][a] = 1;
	}

	for (int i = 1; i <= N; i++)
	{
		dfs(i);
		if (f)
			break;
	}

	if (!f)
		cout << "-1" << endl;
	else
	{
		for (int i : result)
			printf("%d\n", i);
	}
	return 0;
}