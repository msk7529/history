#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <utility>
using namespace std;
// algospot

int C, N;
char board[5][5];
string word[11];
int dp[11][5][5];

vector<pair<int, int>> findFirstchar(string s)	// 게임판에서 s의 첫번째 단어의 위치를 찾아 index쌍들을 리턴한다.
{
	vector<pair<int, int>> p;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (s[0] == board[i][j])
				p.push_back({ i,j });
		}
	}
	return p;
}

int solve(string s, int i, int a, int b)
{
	if (a >= 5 || b >= 5 || a < 0 || b < 0)
		return 0;
	if (i == s.length() - 1 && board[a][b] == s[i])
		return 1;

	int& ret = dp[i][a][b];
	if (ret != -1)
		return ret;
	ret = 0;

	if(s[i] == board[a][b])
		 ret += solve(s, i+1, a - 1, b) || solve(s, i+1, a - 1, b + 1) || solve(s, i+1, a, b + 1) || solve(s, i+1, a + 1, b + 1) || solve(s, i+1, a + 1, b) || solve(s, i+1, a + 1, b - 1) || solve(s, i+1, a, b - 1) || solve(s, i+1, a - 1, b - 1);
	
	return ret;
}

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> C;

	while (C--)
	{
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
				cin >> board[i][j];
		}
		cin >> N;
		for (int i = 0; i < N; i++)
			cin >> word[i];

		for (int i = 0; i < N; i++)
		{
			memset(dp, -1, sizeof(dp));		// 반드시 여기에 들어가야함.
			vector<pair<int, int>> p;
			p.clear();
			p = findFirstchar(word[i]);
			if (p.empty())	// 게임판에서 찾고자 하는 단어의 첫번째 글자가 게임판에 존재하지 않는경우.
			{
				cout << word[i] << " " << "NO" << endl;
				continue;
			}
			else
			{
				bool tmp = false;
				for (int j = 0; j < p.size(); j++)
				{
					if (solve(word[i], 0, p[j].first, p[j].second) > 0)
					{
						cout << word[i] << " " << "YES" << endl;
						tmp = true;
						break;
					}
				}
				if (tmp == false)
					cout << word[i] << " " << "NO" << endl;
			}
		}
	}
	return 0;
}