#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
using namespace std;
// baekjoon

int N, M, w, c;
map<int, int> m;
map<int, int> m2;

bool comp(const pair<int, int>& p1, const pair<int, int>& p2)
{
	if (p1.second == p2.second)
		return p1.first > p2.first;
	return p1.second < p2.second;
}

int main()
{
	int ret = 2147483647;
	int b = false;

	vector<pair<int, int>> v;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> w >> c;
		m[c]++;
		v.push_back({ w,c });
	}
	sort(v.begin(), v.end(), comp);

	int i = 0;
	int weight_sum = 0;
	while (1)
	{
		int cnt = m[v[i].second];
		int cost_sum = 0;
		while (cnt--)
		{
			weight_sum += v[i].first;	// 무게
			cost_sum += v[i].second;	// 가격

			if(m2[cost_sum] == 0)
				m2[cost_sum] = weight_sum;
			else if(m2[cost_sum] < weight_sum)
				m2[cost_sum] = weight_sum;
			i++;
		}

		if (i == N)
			break;
	}

	for (map<int, int>::iterator iter = m2.begin(); iter != m2.end(); iter++)
	{
		if (iter->second >= M)
		{
			ret = min(ret, iter->first);
			b = true;
		}
	}

	if (!b)
		cout << "-1" << endl;
	else
		cout << ret << endl;

	return 0;
}