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

long long a, b;

long long gcd(long long n, long long m)	 // ���� �������
// ��Ŭ���� ȣ�������� �ִ����� ���ϱ�
{
	while (m > 0)
	{
		long long tmp = m;
		m = n % m;
		n = tmp;
	}
	return n;

	// ** sqrt(n) : 1 ~ n ������ ������(=����� ������ Ȧ��)�� ����
}

long long lcm(long long n, long long m)	// �ּ� ����� ���ϱ�
{
	return (n*m) / gcd(n, m);
}

int main()
{
	cin >> a >> b;

	long long up = (int)sqrt(b) - (int)sqrt(a);
	long long down = b - a;

	if (up == 0)
		cout << "0" << endl;
	else
	{
		long long g = gcd(up, down);
		up /= g, down /= g;
		cout << up << "/" << down << endl;
	}
	return 0;
}