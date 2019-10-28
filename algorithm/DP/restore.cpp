#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#define MAX 987654321
using namespace std;
// algospot

int C, k;
int dp[1 << 17][17];
int overlap[17][17];	// overlap[i][j] : s[i]뒤에 s[j]를 겹친다고 할때, 겹쳐지는 최대 글자수
int curr[17];			// 주어지는 글자들중 s 벡터에 푸쉬여부를 결정. curr[i]값이 0이면 푸쉬.
string arr[17];
vector<string> s;

int getOverlap(string s1, string s2)
{
	int length = min(s1.length(), s2.length());
	for (int i = length; i > 0; i--)
	{
		if (s1.substr(s1.length() - i) == s2.substr(0, i))
			return i;
	}
	return 0;
}

int solve(int state, int last)
{
	if (state == (1 << k) - 1)
		return 0;

	int& ret = dp[state][last];
	if (ret != -1)
		return ret;
	ret = 0;

	for (int next = 0; next < k; next++)
	{
		if ((state & (1 << next)) == 0)
			ret = max(ret, overlap[last][next] + solve(state + (1 << next), next));
	}
	return ret;
}

string reconstruct(int state, int last)
{
	if (state == (1 << k) - 1)
		return "";

	for (int next = 0; next < k; next++)
	{
		if ((state & (1 << next)) == 0)
		{
			int used = solve(state, last);
			int ifUsed = overlap[last][next] + solve(state + (1 << next), next);

			if (used == ifUsed)
				return s[next].substr(overlap[last][next]) + reconstruct(state + (1 << next), next);
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> C;

	while (C--)
	{
		memset(curr, 0, sizeof(curr));
		memset(overlap, 0, sizeof(overlap));
		memset(dp, -1, sizeof(dp));
		s.clear();
		cin >> k;
		for (int i = 0; i < k; i++)
			cin >> arr[i];

		for (int i = 0; i < k; i++)
		{
			for (int j = 0; j < k; j++)
			{
				if (i != j && curr[i] == 0 && arr[i].find(arr[j]) != -1)
					curr[j] = -1;
			}
		}

		for (int i = 0; i < k; i++)
		{
			if (curr[i] == 0)
				s.push_back(arr[i]);
		}
		k = s.size();
		s.push_back("");

		for (int i = 0; i <= k; i++)
		{
			for (int j = 0; j <= k; j++)
				overlap[i][j] = getOverlap(s[i], s[j]);
		}

		//cout << reconstruct(0, k) << endl;
		cout << getOverlap(s[0], s[1]) << endl;
	}
	return 0;
}

