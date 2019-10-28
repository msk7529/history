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

string H, N;

int main()
{
	cin >> H >> N;
	
	int nsize = N.length();
	int cnt = 0;
	for (int i = 0; i < H.length(); i++)
	{
		if (H[i] == N[0])
		{
			string tmp = H.substr(i, nsize);
			if (tmp == N)
				cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}