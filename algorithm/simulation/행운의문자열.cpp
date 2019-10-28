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

string s;

int main()
{
	cin >> s;

	int cnt = 0;
	int size = s.length();
	string tmp = s;
	do
	{
		bool b = true;
		next_permutation(s.begin(), s.end());
		for (int i = 0; i < size-1; i++)
		{
			if (s[i] == s[i + 1])
			{
				b = false;
				break;
			}
		}

		if (b)
			cnt++;

	} while (s != tmp);
	
	cout << cnt << endl;

	return 0;
}