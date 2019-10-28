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
// backjoon

int N;
//int arr[16][16];
//int row[16];
int col[16];
int rightdown[31];
int leftdown[31];
int ret;

void backtracking(int row)
{
	if (row == N)
	{
		ret++;
		return;
	}
	
	for (int j = 0; j < N; j++)
	{
		if (col[j] == 0 && rightdown[N - 1 - (row - j)] == 0 && leftdown[row + j] == 0)
		{
			col[j] = rightdown[N - 1 - (row - j)] = leftdown[row + j] = 1;
			backtracking(row + 1);
			col[j] = rightdown[N - 1 - (row - j)] = leftdown[row + j] = 0;
		}
	}
}


int main()
{
	cin >> N;
	ret = 0;

	backtracking(0);
	cout << ret << endl;
	return 0;
}