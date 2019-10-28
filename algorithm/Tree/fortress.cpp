#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
// algospot

int C, N;
int x[101], y[101], r[101];
int longest;

struct TreeNode
{
	vector<TreeNode*> children;
};

int sqr(int x)
{
	return x*x;
}

int distance(int a, int b)
{
	return sqr(y[a] - y[b]) + sqr(x[a] - x[b]);
}

bool encloses(int a, int b)		// 성벽 a가 b를 포함하면 true 리턴.
{
	return r[a] > r[b] && distance(a, b) < sqr(r[a]-r[b]);
}

bool isChild(int parent, int child)		// parent가 child를 직접 포함하고 있으면 true 리턴.
{
	if (!encloses(parent,child))
		return false;
	for (int i = 0; i < N; i++)
	{
		if (i != parent && i != child && encloses(parent, i) && encloses(i, child))
			return false;
	}
	return true;
}

TreeNode* getTree(int root)
{
	TreeNode* ret = new TreeNode();
	for (int i = 0; i < N; i++)
	{
		if (isChild(root, i))
			ret->children.push_back(getTree(i));
	}
	return ret;
}

int height(TreeNode* root)
{
	vector<int> heights;
	
	for (int i = 0; i < root->children.size(); i++)
		heights.push_back(height(root->children[i]));
	if (heights.empty())
		return 0;

	sort(heights.begin(), heights.end());
	
	int size = heights.size();
	if (size >= 2)
		longest = max(longest, 2 + heights[size - 1] + heights[size - 2]);

	return heights[size - 1]+1;
}

int solve(TreeNode* root)
{
	longest = 0;

	int ret = height(root);
	return max(longest, ret);
}

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> C;
	
	while (C--)
	{
		cin >> N;
		for (int i = 0; i < N; i++)
			cin >> x[i] >> y[i] >> r[i];

		TreeNode* T = getTree(0);
		cout << solve(T) << endl;
	}

	return 0;
}