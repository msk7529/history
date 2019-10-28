#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <queue>
#define MAX 987654321
using namespace std;
// baekjoon

int N, M, n, t;
vector<pair<int, int>> v;	// 주문번호, 테이블번호

bool comp(const pair<int, int>& p1, const pair<int, int>& p2)
{
	if (p1.first == p2.first)
		return p1.second < p2.second;
	return p1.first < p2.first;
}

int main()
{
	cin >> N >> M;
	string s;
	for (int i = 0; i < N; i++)
	{
		cin >> s;
		if (s == "order")
		{
			cin >> n >> t;
			v.push_back({ t,n });

			for (int j = 0; j < v.size(); j++)
				cout << v[j].second << " ";
		}
		else if (s == "sort")
		{
			if (v.empty())
				cout << "sleep";
			else
			{
				sort(v.begin(), v.end(), comp);
				for (int j = 0; j < v.size(); j++)
					cout << v[j].second << " ";
			}
		}
		else
		{
			cin >> n;
			for (vector<pair<int, int>>::iterator iter = v.begin(); iter != v.end(); iter++)
			{
				if (iter->second == n)
				{
					v.erase(iter);
					break;
				}
			}

			if (v.empty())
				cout << "sleep";
			else
			{
				for (int j = 0; j < v.size(); j++)
					cout << v[j].second << " ";
			}
		}
		cout << endl;
	}
	return 0;
}