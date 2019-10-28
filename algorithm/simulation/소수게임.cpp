#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <functional>
#define MAX 987654321
using namespace std;
// baekjoon

map<int, int> m;
int prime[5000000];
int N, a;
unsigned long long ret1, ret2;
priority_queue<unsigned long long> pq1, pq2;

int main()
{
	ret1 = 0, ret2 = 0;
	memset(prime, 1, sizeof(prime));
	for (int i = 2; i < 5000000; i++)
	{
		if (prime[i] == 0)
			continue;
		for (int j = i + i; j < 5000000; j += i)
			prime[j] = 0;
	}
	prime[1] = 0;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> a;
		if (prime[a] == 0)
		{
			if (pq2.size() < 3)
				ret2 += 1000;
			else
			{
				int t1, t2, t3;
				t1 = pq2.top();
				pq2.pop();
				t2 = pq2.top();
				pq2.pop();
				t3 = pq2.top();
				ret2 += t3;
				pq2.push(t1);
				pq2.push(t2);
			}
		}
		else
		{
			if (m[a] == 1)
				ret1 -= 1000;
			else
			{
				m[a] = 1;
				pq1.push(a);
			}
		}

		cin >> a;
		if (prime[a] == 0)
		{
			if (pq1.size() < 3)
				ret1 += 1000;
			else
			{
				int t1, t2, t3;
				t1 = pq1.top();
				pq1.pop();
				t2 = pq1.top();
				pq1.pop();
				t3 = pq1.top();
				ret1 += t3;
				pq1.push(t1);
				pq1.push(t2);
			}
		}
		else
		{
			if (m[a] == 1)
				ret2 -= 1000;
			else
			{
				m[a] = 1;
				pq2.push(a);
			}
		}
	}


	if (ret1 > ret2)
		cout << "소수의 신 갓대웅" << endl;
	else if (ret1 < ret2)
		cout << "소수 마스터 갓규성" << endl;
	else
		cout << "우열을 가릴 수 없음" << endl;

	return 0;
}