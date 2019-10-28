#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
#include <utility>
using namespace std;
// baekjoon

int N, s, e;
vector<pair<int, int>> v;
int check[300001];

bool comp(const pair<int,int>& a, const pair<int,int>& b)
{
	if (a.first == b.first)
		return a.second > b.second;
	return a.first < b.first;
}

int main()
{
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> s >> e;
		v.push_back({ s,i + 1 });
		v.push_back({ e,-i - 1 });
	}

	if (N == 1)
	{
		cout << "1" << endl;
		cout << "1" << endl;
		return 0;
	}
	sort(v.begin(), v.end(), comp);

	int max_size = 0;
	int cnt = 0;
	int pos = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i].second > 0)
		{
			cnt++;
			if (cnt > max_size)
			{
				max_size = cnt;
				pos = i;
			}
		}
		else
			cnt--;
	}

	for (int i = 0; i <= pos; i++)
	{
		if (v[i].second > 0)
			check[v[i].second] = 1;
		else
			check[-v[i].second] = 0;
	}

	cout << max_size << endl;
	for (int i = 1; i <= N; i++)
	{
		if (check[i])
			printf("%d ", i);
	}

	return 0;
}