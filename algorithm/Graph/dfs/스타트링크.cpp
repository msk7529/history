#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <stack>
#include <string>
#include <utility>
#include <cmath>
using namespace std;
// baekjoon

int F, S, G, U, D;
int visit[1000001];

int solve(int curr)
{
	if (curr == G)
		return 0;
	if (visit[curr] == 1)
		return 987654321;

	visit[curr] = 1;
	int ret = 0;
	if (curr < G)
		ret = 1 + solve(curr + U);
	else if (curr > G)
		ret = 1 + solve(curr - D);

	return ret;
}

int main()
{
	cin >> F >> S >> G >> U >> D;
	memset(visit, 0, sizeof(visit));
	int ret = solve(S);
	if (ret >= 987654321)
		cout << "use the stairs" << endl;
	else
		cout << ret << endl;

	return 0;
}