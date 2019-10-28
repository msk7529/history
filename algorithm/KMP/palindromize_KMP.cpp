#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int C;

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

int solve(const string& H, const string& N)
{
	int n = H.size(), m = N.size();
	vector<int> pi = getPartialMatched(N);

	int begin = 0, matched = 0;

	while (begin < n)
	{
		if (H[begin + matched] == N[matched])
		{
			matched++;
			if (begin + matched == n)
				return matched;
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
	return 0;
}

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> C;

	while (C--)
	{
		string S, reverse_S;
		cin >> reverse_S;
		S = reverse_S;
		reverse(reverse_S.begin(), reverse_S.end());

		int matched = solve(S, reverse_S);
		int tmp = S.size() - matched;
		int result = matched + (2 * tmp);
		cout << result << endl;

	}
	return 0;
}