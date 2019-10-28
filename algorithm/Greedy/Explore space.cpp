#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <utility>
#include <vector>
#include <map>
#include <queue>
#define MAX 987654321
using namespace std;
// baekjoon

struct st
{
	double x1, y1, x2, y2;
};

int N, M;
st layer[100001];
double lazer[100001];

int main()
{
	ios::sync_with_stdio(false);

	cin >> N;
	double a, b, c, d;
	for (int i = 0; i < N; i++)
	{
		cin >> a >> b >> c >> d;
		layer[i] = { a,b,c,d };
	}

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b;
		lazer[i] = (double)b / (double)a;
	}
	sort(&lazer[0], &lazer[M]);

	int ret = N;

	for (int i = 0; i < N; i++)
	{
		double tmp1 = layer[i].y1 / layer[i].x1, tmp2 = layer[i].y2 / layer[i].x2;
		if (tmp1 > tmp2)
			swap(tmp1, tmp2);

		int index = lower_bound(lazer, lazer + M, tmp1) - lazer;
		if (index != M && lazer[index] <= tmp2)
			ret--;
	}

	cout << ret << endl;
	return 0;
}