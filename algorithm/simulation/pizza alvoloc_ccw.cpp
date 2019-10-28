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
// algospot

int ccw(pair<int, int> a, pair<int, int> b, pair<int, int> c)
// ���� a->b->c�� ���� ���⼺�� ���Ѵ�.
{
	int ret = a.first * b.second + b.first * c.second + c.first * a.second;
	ret -= (a.second*b.first + b.second * c.first + c.second*a.first);
	
	if (ret > 0)	// �ݽð����
		return 1;
	else if (ret == 0)	// ����
		return 0;
	else			// �ð����
		return -1;
}

bool isIntersect(pair<int, int> a, pair<int, int> b, pair<int, int> c, pair<int, int> d)
// ������ ������ �ϳ��� �����ϸ� 1�� ����
{
	int ab = ccw(a, b, c) * ccw(a, b, d);
	int cd = ccw(c, d, a) * ccw(c, d, b);

	if (ab == 0 && cd == 0)	// ������ ���
	{
		if (a > b)
			swap(a, b);
		if (c > d)
			swap(c, d);
		return c <= b && a <= d;
	}
	return ab <= 0 && cd <= 0;
}

int main()
{
	pair<int, int> p[4];
	
	for (int i = 0; i < 4; i++)
		cin >> p[i].first >> p[i].second;

	cout << isIntersect(p[0], p[1], p[2], p[3]) << endl;

	if (ccw(p[0], p[1], p[2]) * ccw(p[0], p[1], p[3]) < 0)
		cout << "1" << endl;
	else
		cout << "0" << endl;

	return 0;
}