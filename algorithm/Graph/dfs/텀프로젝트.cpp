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

int T, n;
int arr[100001];
int visit[100001];
vector<int> stuNum;

int dfs(int start, int next)
{
	if (stuNum.size() != 0 && start == next)
		return stuNum.size();
	
	int num = arr[next];
	if (visit[num] == 0)
	{
		visit[num] = 1;
		stuNum.push_back(num);
		return dfs(start, num);
	}

	return 0;
}

int main()
{
	cin >> T;
	while (T--)
	{
		int sum = 0;
		memset(visit, 0, sizeof(visit));
		memset(arr, 0, sizeof(arr));
		stuNum.clear();
		cin >> n;
		for (int i = 1; i <= n; i++)
			cin >> arr[i];
		for (int i = 1; i <= n; i++)
		{
			if (visit[i] == 0)
			{
				int result = dfs(i, i);
				if (result == 0)
				{
					for (int j = 0; j < stuNum.size(); j++)
						visit[stuNum[j]] = 0;
					visit[i] = 1;
					stuNum.clear();
				}
				else
				{
					for (int j = 0; j < stuNum.size(); j++)
					{
						visit[stuNum[j]] = 1;
						stuNum.clear();
					}
					sum += result;
				}
			}
		}
		cout << n - sum << endl;
	}
	return 0;
}