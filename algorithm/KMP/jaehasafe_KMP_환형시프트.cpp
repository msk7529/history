#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int C, N;
string s[102];

vector<int> getPartialMatched(const string& N)
{
	int m = N.size();
	vector<int> pi(m, 0);

	int begin = 1, matched = 0;

	while (begin + matched < m)
	{
		if (N[begin + matched] == N[matched])
		{
			matched++;
			pi[begin + matched - 1] = matched;
		}
		else
		{
			if (matched == 0)
				begin++;
			else
			{
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
	return pi;
}

vector<int> kmpSearch(const string& H, const string& N)
{
	int n = H.size(), m = N.size();
	vector<int> pi = getPartialMatched(N);

	int begin = 0, matched = 0;
	vector<int> ret;

	while (begin <= n - m)
	{
		if (matched < m && H[begin + matched] == N[matched])
		{
			matched++;
			if (matched == m)
				ret.push_back(begin);
		}
		else
		{
			if (matched == 0)
				begin++;
			else
			{
				begin += matched - pi[matched - 1];
				matched = pi[matched - 1];
			}
		}
	}
	return ret;
}

int solve(const string& H, const string& N)
// H를 N으로 만들기 위해 환형 시프트를 몇번이나 해야하는지 반환.
{
	return kmpSearch(H + H, N)[0];
}

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> C;

	while (C--)
	{
		cin >> N;
		int result = 0;
		for (int i = 0; i <= N; i++)
			cin >> s[i];
		for (int i = 0; i < N; i++)
		{
			if (i % 2 == 0)		// 시계방향
				result += solve(s[i + 1], s[i]);
			else	// 반시계방향
				result += solve(s[i], s[i + 1]);
		}
		cout << result << endl;
	}
	return 0;
}