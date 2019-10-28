#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#define MOD 20091101
using namespace std;
// algospot

int T, N, K;
int Di[100001];
long long Psum[100001];

int solve1(vector<long long>& count)
{
	int ret = 0;
	for (int i = 0; i < K; i++)
	{
		if (count[i] > 1)
			ret = (ret + ((count[i] * (count[i] - 1)) / 2)) % MOD;
	}
	return ret;
}

int solve2()	// 배열을 이용한 dp
{
	vector<int> ret(N + 1, 0);
	vector<int> prev(K, -1);

	for (int i = 0; i <= N; i++)
	{
		if (i > 0)
			ret[i] = ret[i - 1];
		else
			ret[i] = 0;

		int loc = prev[Psum[i]];
		if (loc != -1)
			ret[i] = max(ret[i], ret[loc] + 1);
		prev[Psum[i]] = i;
	}
	return ret.back();
}

int solve3()	// map을 이용한 dp
{
	map<long long, long long> m;
	int ret = 0;
	for (int i = 0; i <= N; i++)
	{
		m[Psum[i]]++;
		if (m[Psum[i]] > 1)
		{
			ret++;
			m.clear();
			m[Psum[i]]++;
		}
	}
	return ret;
}

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> T;

	while (T--)
	{
		Psum[0] = 0;
		cin >> N >> K;
		vector<long long> count(K, 0);
		count[Psum[0]]++;				// 이거 안쓰면 오답... 개빡..

		for (int i = 1; i <= N; i++)
		{
			cin >> Di[i];
			Psum[i] = (Psum[i - 1] + Di[i]) % K;
			count[Psum[i]]++;
		}

		cout << solve1(count) << " " << solve2() << endl;
		count.clear();
	}
	return 0;
}