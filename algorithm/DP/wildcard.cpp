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
	// 와일드카드의 마지막 글자 '?'이 파일명의 마지막 글자와 대응되거나, 파일명과 와일드카드의 마지막글자가 서로 같으면 참.
	if ((W[wi] == f[fi] || W[wi] == '?') && wi == W.length() - 1 && fi == f.length() - 1)
		return 1;
	
	// 와일드카드의 마지막 글자가 '*'이면 참.  이 이외에는 모두 재귀를 통해 검사해봐야함.
	if (W[wi] == '*' && wi == W.length() - 1)
		return 1;

	int& ret = dp[wi][fi];
	if (ret != -1)
		return ret;
	ret = 0;

	if (W[wi] == f[fi])		// 와일드카드의 wi번째 글자와 파일명의 fi번째 글자가 같으면, 다음 글자로 검사를 진행.
		ret = solve(f, wi + 1, fi + 1);

	if (W[wi] == '?' && fi < f.length())	// 와일드카드의 wi번째 글자가 '?'이고 fi가 파일명의 길이보다 작으면, 다음글자로 검사를 진행
		ret = solve(f, wi + 1, fi + 1);

	if (W[wi] == '*' && wi < W.length() - 1)	//	와일드카드의 wi번째 글자가 '*'이고 이것이 와일드카드의 마지막글자가 아닐때, 여기에 파일명의 fi번째부터 끝글자까지 대응시켜봄.
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