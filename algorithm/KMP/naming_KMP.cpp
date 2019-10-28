#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
// algospot

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

int main()
{
	string s1, s2, N;
	cin >> s1 >> s2;
	N = s1 + s2;

	vector<int> pi = getPartialMatched(N);
	vector<int> result;
	
	int k = N.size();
	while (k > 0)
	{
		result.push_back(k);
		k = pi[k - 1];
	}

	sort(result.begin(), result.end());
	for (int i = 0; i < result.size(); i++)
		cout << result[i] << " ";
	cout << endl;

	return 0;
}
