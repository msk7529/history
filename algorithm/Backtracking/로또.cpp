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

int k;
int arr[14];
vector<int> v;

void backtracking(int i, int cnt)
{
	if (cnt == 6)
	{
		for (int a = 0; a < 6; a++)
			cout << v[a] << " ";
		cout << endl;
		return;
	}
	if (i >= k)
		return;
	
	v.push_back(arr[i]);
	backtracking(i + 1, cnt+1);
	v.pop_back();

	backtracking(i + 1, cnt);
}

int main()
{
	while (1)
	{
		v.clear();
		cin >> k;
		if (k == 0)
			break;
		for (int i = 0; i < k; i++)
			cin >> arr[i];
		backtracking(0, 0);
		cout << endl;
	}
	return 0;
}