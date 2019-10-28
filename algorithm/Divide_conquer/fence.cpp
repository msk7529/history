#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
// algospot

int C, N;
vector<int> height;

int solve(int left, int right)
{
	if (left == right)
		return height[left];

	int ret = 0;
	int mid = (left + right) / 2;

	ret = max(solve(left, mid), solve(mid + 1, right));

	int lo = mid, ro = mid + 1;
	int h = min(height[lo], height[ro]);

	ret = max(ret, 2 * h);

	while (left<lo || right>ro)
	{
		if (right > ro && (lo == left || height[lo - 1] < height[ro + 1]))
		{
			ro++;
			h = min(h, height[ro]);
		}
		else
		{
			lo--;
			h = min(h, height[lo]);
		}
		ret = max(ret, h*(ro - lo + 1));
	}
	return ret;
}

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> C;

	while (C--)
	{
		height.clear();
		cin >> N;

		for (int i = 0; i < N; i++)
		{
			int h;
			cin >> h;
			height.push_back(h);
		}
		cout << solve(0, N - 1) << endl;
	}
	return 0;
}