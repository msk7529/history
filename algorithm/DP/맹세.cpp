#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
#include <utility>
#include <map>
#include <set>
#define MAX 987654321
#define MOD 1000000007
using namespace std;
typedef unsigned long long ul;
// baekjoon

string s1[14] = { "h", "b", "c", "n", "o", "f", "p", "s", "k", "v", "y", "i", "w", "u" };
string s2[100] = { "ba", "ca" , "ga", "la", "na", "pa", "ra", "ta", "db", "nb", "pb", "rb", "sb", "tb", "yb", "ac",
"sc", "tc", "cd", "gd", "md", "nd", "pd", "be", "ce", "fe", "ge", "he", "ne", "re", "se", "te",
"xe", "cf", "hf", "rf", "ag", "hg", "mg", "rg", "sg", "bh", "rh", "th", "bi", "li", "ni", "si",
"ti", "bk", "al", "cl", "fl", "tl", "am", "cm", "fm", "pm", "sm", "tm", "cn", "in", "mn", "rn",
"sn", "zn", "co", "ho", "mo", "no", "po", "np", "ar", "br", "cr", "er", "fr", "ir", "kr", "lr",
"pr", "sr", "zr", "as", "cs", "ds", "es", "hs", "os", "at", "mt", "pt", "au", "cu", "eu", "lu",
"pu", "ru", "lv", "dy" };

set<string> s;
string target;
int T, len;
int dp[50001];

int solve(int here)
{
	if (here >= len)
		return 1;

	int& ret = dp[here];
	if (ret != -1)
		return ret;

	ret = 0;

	string tmp = target.substr(here, 1);
	if (s.find(tmp) != s.end())
		ret += solve(here + 1);

	/*if (ret)
		return 1;*/

	tmp = target.substr(here, 2);
	if (s.find(tmp) != s.end())
		ret = max(ret, solve(here + 2));
	
	/*if (ret)
		return 1;*/
	return ret;
}

int main()
{
	ios::sync_with_stdio(false);

	for (int i = 0; i < 14; i++)
		s.insert(s1[i]);
	for (int i = 0; i < 100; i++)
		s.insert(s2[i]);

	cin >> T;

	while (T--)
	{
		memset(dp, -1, sizeof(dp));
		cin >> target;
		len = target.length();
		if (solve(0))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}