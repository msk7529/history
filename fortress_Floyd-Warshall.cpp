#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
// algospot

struct castleWall
{
	int x, y, r;
};

bool comp(const castleWall& a, const castleWall& b)
{
	return a.r < b.r;
}

double distance(const castleWall& a, const castleWall& b)
{
	return pow(((double)(a.x - b.x)), 2) + pow(((double)(a.y - b.y)), 2);
}

castleWall cw[101];
int C, N;
int graph[101][101];

int main()
{
	std::ios::sync_with_stdio(false);
	
	int C, N;

	cin >> C;

	while (C--)
	{
		cin >> N;
		for (int i = 0; i < N; i++)
			cin >> cw[i].x >> cw[i].y >> cw[i].r;
		sort(&cw[0], &cw[N], comp);			// �������� �������� �������� �������� ����.

		for (int i = 0; i < N; i++)			// �׷����� ��� ������ ����ġ�� 12345678
		{
			for (int j = 0; j < N; j++)
			{
				if (i == j)
					graph[i][j] = 0;
				else
					graph[i][j] = 12345678;
			}
		}

		for (int i = 0; i < N-1; i++)
		{
			for (int j = i+1; j < N; j++)
			{
				if (distance(cw[i], cw[j]) < pow((double)cw[j].r, 2))
				{
					// i�� j�� �������� �Ÿ����� j�� �������� ũ�� i�� j�� ���Ѵ�.
					// �� ������ �̾��ְ�, i�� ���̻� �θ� ã�� �ʿ䰡 �����Ƿ�
					// ��� break�Ѵ�. �̷��ԵǸ�, i�� ���� �Ѱ��� �θ� ���ԵǹǷ�
					// ������ �䱸������ ������Ų��.
					graph[i][j] = graph[j][i] = 1;
					break;
				}
			}
		}

		int result = 0;
		for (int b = 0; b < N; b++)		// �÷��̵�-���� �˰���. a : �����, b: ������, c: ������
		{
			for (int a = 0; a < N; a++)
			{
				for (int c = 0; c < N; c++)
				{
					graph[a][c] = min(graph[a][c], graph[a][b] + graph[b][c]);
					if(graph[a][c] != 12345678)
						result = max(result, graph[a][c]);		// ���� �׷����� �̾��� ��ο��� ����ġ�� ���� ���� ū ���� �����Ѵ�.
				}
			}
		}
		cout << result << endl;
	}
	return 0;
}