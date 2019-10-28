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

int N;
string s[11];
map<char, int> mp;
vector<pair<char, int>> v;
vector<char> ch;

bool compare(const pair<char, int>& p1, const pair<char, int>& p2)
{
	return p1.second > p2.second;
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> s[i];
		int tmp = s[i].length()-1;
		for (int j = 0; j <= tmp; j++)
		{
			if (find(ch.begin(), ch.end(), s[i][j]) == ch.end())
				ch.push_back(s[i][j]);
			mp[s[i][j]] += pow(10, tmp - j);
		}
	}

	for (int i = 0; i < ch.size(); i++)
		v.push_back({ ch[i], mp[ch[i]] });
	sort(v.begin(), v.end(), compare);

	int num = 9, ret = 0;
	for (int i = 0; i < v.size(); i++)
	{
		mp[v[i].first] *= num;
		ret += mp[v[i].first];
		num--;
	}
	cout << ret << endl;
	return 0;
}