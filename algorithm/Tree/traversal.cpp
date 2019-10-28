#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
// algospot

int C, N, num;

vector<int> slice(vector<int> v, int a, int b)
{
	return vector<int>(v.begin() + a, v.begin() + b);
}

void solve(vector<int> preorder, vector<int> inorder)
{
	if (preorder.empty())
		return;

	int root = preorder[0];
	int L = find(inorder.begin(), inorder.end(), root) - inorder.begin();
	int size = preorder.size();

	solve(slice(preorder, 1, L + 1), slice(inorder, 0, L));
	solve(slice(preorder, L + 1, size), slice(inorder, L + 1, size));

	cout << root << " ";
}

int main()
{
	std::ios::sync_with_stdio(false);
	vector<int> preorder;
	vector<int> inorder;

	cin >> C;

	while (C--)
	{
		preorder.clear();
		inorder.clear();
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			cin >> num;
			preorder.push_back(num);
		}
		for (int i = 0; i < N; i++)
		{
			cin >> num;
			inorder.push_back(num);
		}
		solve(preorder, inorder);
	}
	return 0;
}