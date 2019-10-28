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
#include <deque>
using namespace std;
// baekjoon

int N;
pair<int, int> arr[16];

int solve(int i)
{
	if (i > N)
		return 0;

	int ret = 0;
	ret = solve(i + 1);
	if(i+ arr[i].first <= N+1)
		ret = max(ret, arr[i].second + solve(i + arr[i].first));

	return ret;
}

int main()
{
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> arr[i].first >> arr[i].second;

	cout << solve(1) << endl;

	return 0;
}