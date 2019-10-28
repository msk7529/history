#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
#include <utility>
typedef long long ll;
#define MAX 987654321
#define MOD 1000000007
using namespace std;
// baekjoon

ll fac[1000001];

ll power(int a, int b)
// pow(a,b)를 O(logb)시간에 계산
{
	if (b == 1)
		return a;
	if (b == 0)
		return 0;

	if (b % 2 == 0)
	{
		ll na = power(a, b / 2) % MOD;
		return (na * na) % MOD;
	}
	else
	{
		ll na = power(a, (b - 1) / 2) % MOD;
		return (((na*na)%MOD) * a) % MOD;
	}
}

int main()
{
	int N, M;
	cin >> N >> M;

	fac[1] = 1;
	for (int i = 2; i <= N; i++)
		fac[i] = (fac[i - 1] * i) % MOD;

	ll ret = (((fac[N] * power(fac[N - M], MOD - 2)) % MOD) * power(fac[M], MOD - 2) % MOD);

	cout << ret << endl;

	return 0;
}