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
// baekjoon
typedef unsigned long long ul;
int N, M;
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;
//vector<vector<int>> ret;
int result = MAX;

int distance(pair<int, int> p1, pair<int, int> p2)
{
	return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

int calc(vector<int> v)
{
	int dist = 0;
	for (int i = 0; i < house.size(); i++)
	{
		int tmp = MAX;
		for (int j = 0; j < v.size(); j++)
			tmp = min(tmp, distance(house[i], chicken[v[j]]));
		dist += tmp;
	}
	return dist;
}

void solve(int n, vector<int> v)
{
	if (v.size() == M)
	{
		result = min(result, calc(v));
		//ret.push_back(v);
		return;
	}

	for (int i = n + 1; i < chicken.size(); i++)
	{
		v.push_back(i);
		solve(i, v);
		v.pop_back();
	}
}


int main()
{
	ios::sync_with_stdio(false);

	cin >> N >> M;
	int num;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> num;
			if (num == 1)
				house.push_back({ i,j });
			else if (num == 2)
				chicken.push_back({ i,j });
		}
	}
	//int result = MAX;

	vector<int> tmp;
	solve(-1, tmp);

	//for (int i = 0; i < ret.size(); i++)
		//result = min(result, calc(ret[i]));

	cout << result << endl;

	return 0;
}