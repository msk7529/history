#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <functional>
#define MAX 987654321
using namespace std;
// baekjoon

int T;
string N, M;

int main()
{
	cin >> T;
	while (T--)
	{
		cin >> N >> M;

		int n1 = 0, m1 = 0, ret = 0, cnt = 0;
		for (int i = 0; i < N.length(); i++)
		{
			if (N[i] == '1')
				n1++;
			if (M[i] == '1')
				m1++;
			if (N[i] - M[i] != 0)
				cnt++;
		}

		ret = abs(m1 - n1);
		cnt -= ret;
		cnt /= 2;
		ret += cnt;
		cout << ret << endl;
	}
	return 0;
}