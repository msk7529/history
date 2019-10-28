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

int N,arr[12];
vector<int> result;
int sum, sub, mul, dv;

int cal(int now, int a, char c)
{
	if (c == '+')
		return now + arr[a];
	else if (c == '-')
		return now - arr[a];
	else if (c == '*')
		return now * arr[a];
	else
		return now / arr[a];
}

void solve(int now, int a, int cnt)
{
	if (cnt == 0)
	{
		result.push_back(now);
		return;
	}

	int ret = now;
	
	if (sum > 0)
	{
		sum--;
		solve(cal(ret, a + 1, '+'), a+1, cnt - 1);
		sum++;
	}
	if (sub > 0)
	{
		sub--;
		solve(cal(ret, a + 1, '-'), a+1, cnt - 1);
		sub++;
	}	
	if (mul > 0)
	{
		mul--;
		solve(cal(ret, a + 1, '*'), a+1, cnt - 1);
		mul++;
	}
	if (dv > 0)
	{
		dv--;
		solve(cal(ret, a + 1, '/'), a+1, cnt - 1);
		dv++;
	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	cin >> sum >> sub >> mul >> dv;

	solve(arr[0], 0, N - 1);
	sort(result.begin(), result.end());
	cout << result.back() << endl << result.front() << endl;

	return 0;
}