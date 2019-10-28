#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
// algospot

int C, N;
string W;
int dp[101][101];

int solve(string f, int wi, int fi)
{
	// ���ϵ�ī���� ������ ���� '?'�� ���ϸ��� ������ ���ڿ� �����ǰų�, ���ϸ�� ���ϵ�ī���� ���������ڰ� ���� ������ ��.
	if ((W[wi] == f[fi] || W[wi] == '?') && wi == W.length() - 1 && fi == f.length() - 1)
		return 1;
	
	// ���ϵ�ī���� ������ ���ڰ� '*'�̸� ��.  �� �̿ܿ��� ��� ��͸� ���� �˻��غ�����.
	if (W[wi] == '*' && wi == W.length() - 1)
		return 1;

	int& ret = dp[wi][fi];
	if (ret != -1)
		return ret;
	ret = 0;

	if (W[wi] == f[fi])		// ���ϵ�ī���� wi��° ���ڿ� ���ϸ��� fi��° ���ڰ� ������, ���� ���ڷ� �˻縦 ����.
		ret = solve(f, wi + 1, fi + 1);

	if (W[wi] == '?' && fi < f.length())	// ���ϵ�ī���� wi��° ���ڰ� '?'�̰� fi�� ���ϸ��� ���̺��� ������, �������ڷ� �˻縦 ����
		ret = solve(f, wi + 1, fi + 1);

	if (W[wi] == '*' && wi < W.length() - 1)	//	���ϵ�ī���� wi��° ���ڰ� '*'�̰� �̰��� ���ϵ�ī���� ���������ڰ� �ƴҶ�, ���⿡ ���ϸ��� fi��°���� �����ڱ��� �������Ѻ�.
	{
		for (int z = fi; z < f.length(); z++)
			ret = max(ret, solve(f, wi + 1, z));
	}

	return ret;
}

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> C;

	while (C--)
	{
		cin >> W >> N;
		vector<string> result;
		result.clear();

		for (int i = 0; i < N; i++)
		{
			memset(dp, -1, sizeof(dp));
			string f;
			cin >> f;
			
			if (solve(f, 0, 0))
				result.push_back(f);
		}
		sort(result.begin(), result.end());

		for (int i = 0; i < result.size(); i++)
			cout << result[i] << endl;
	}
	return 0;
}