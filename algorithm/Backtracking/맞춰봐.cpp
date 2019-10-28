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

int N;
char S[12][12];
int A[12];
bool fin;

int qSum(int a, int b)
{
	int sum = 0;
	for (int i = a; i <= b; i++)
		sum += A[i];
	return sum;
}

bool check(int n)
{
	int sum = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
		{
			int qs = qSum(i, j);
			if (qs < 0 && S[i][j] != '-' || qs > 0 && S[i][j] != '+' || qs == 0 && S[i][j] != '0')
				return false;
		}
	}
	return true;
}

void backtracking(int n)
{
	if (n == N + 1)
	{
		fin = true;
		return;
	}

	for (int i = -10; i <= 10; i++)
	{
		A[n] = i;
		if (check(n))
			backtracking(n + 1);
		if (fin)
			return;
	}
}

int main()
{
	cin >> N;
	string s;
	cin >> s;
	int tmp = 0, fin = false;
	for (int i = 1; i <= N; i++)
	{
		for (int j = i; j <= N; tmp++,j++)
			S[i][j] = s[tmp];
	}

	backtracking(1);
	for (int i = 1; i <= N; i++)
		cout << A[i] << " ";

	return 0;
}