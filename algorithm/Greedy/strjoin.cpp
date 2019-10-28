#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <queue>
#include <functional>
using namespace std;

int c, n;
priority_queue<int,vector<int>,greater<int>> pq;

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> c;

	while (c--)
	{
		cin >> n;
		int result = 0;
		for (int i = 0; i < n; i++)
		{
			int num;
			cin >> num;
			pq.push(num);
		}

		while (pq.size() != 1)
		{
			int a = pq.top();
			pq.pop();
			int b = pq.top();
			pq.pop();
			result += (a + b);
			pq.push(a + b);
		}
		cout << result << endl;
		pq.pop();
	}
	return 0;
}