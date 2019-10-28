#include <iostream>
#include <cstring>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;
// �����ذ���

int N, a, b, c, d, cd, cnt, ret;
multimap<int, int> P, Q;

void solve(int num1, int num2, int sum, int pq)
// num1 : ������ x��ǥ, num2 : ���� x��ǥ, sum : ��, pq : 1�̸� P�� Ž��, 2�̸� Q�� Ž��
{
	int next_sum = sum + cd + abs(num1 - num2);
	pair<multimap<int, int>::iterator, multimap<int, int>::iterator> pair_iter;
	multimap<int, int>::iterator iter;

	if (pq == 2)
	{
		cnt = Q.count(num2);
		if(cnt > 1)
		{
			pair_iter = Q.equal_range(num2);
			// equal_range : key���� �ش��ϴ� ������ ������ pair��ü�� ��ȯ
			// pair��ü�� first : key���� �ش��ϴ� ������ ù��° �ݺ��� ��ȯ. (lower_bound)
			// pair��ü�� second : key���� �ش��ϴ� ������ ������ ������ "����" �ݺ��ڸ� ��ȯ. (upper_bound)
			for (iter = pair_iter.first; iter != pair_iter.second; iter++)
			{
				if (num1 < iter->second)
					solve(num2, iter->second, next_sum, 1);
			}
		}
	}
	else
	{
		cnt = P.count(num2);
		if (cnt > 1)
		{
			pair_iter = P.equal_range(num2);
			for (iter = pair_iter.first; iter != pair_iter.second; iter++)
			{
				if (num1 < iter->second)
					solve(num2, iter->second, next_sum, 2);
			}
		}
	}
	ret = max(ret, next_sum);
}

int main()
{
	ios::sync_with_stdio(false);

	cin >> N >> c >> d;
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b;
		P.insert({ a,b });
		Q.insert({ b,a });
	}
	cd = abs(c - d);

	for (multimap<int, int>::iterator iter = P.begin(); iter != P.end(); iter++)
		solve(iter->first, iter->second, 0, 2);
	for (multimap<int, int>::iterator iter = Q.begin(); iter != Q.end(); iter++)
		solve(iter->first, iter->second, 0, 1);

	printf("%d\n", ret);

	return 0;
}