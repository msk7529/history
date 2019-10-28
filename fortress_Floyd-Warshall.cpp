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
		sort(&cw[0], &cw[N], comp);			// 성벽들을 반지름을 기준으로 오름차순 정렬.

		for (int i = 0; i < N; i++)			// 그래프상 모든 간선의 가중치는 12345678
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
					// i와 j의 중점간의 거리보다 j의 반지름이 크면 i는 j에 속한다.
					// 두 정점을 이어주고, i는 더이상 부모를 찾을 필요가 없으므로
					// 즉시 break한다. 이렇게되면, i는 오직 한개의 부모만 갖게되므로
					// 문제의 요구조건을 만족시킨다.
					graph[i][j] = graph[j][i] = 1;
					break;
				}
			}
		}

		int result = 0;
		for (int b = 0; b < N; b++)		// 플로이드-워셜 알고리즘. a : 출발지, b: 경유지, c: 도착지
		{
			for (int a = 0; a < N; a++)
			{
				for (int c = 0; c < N; c++)
				{
					graph[a][c] = min(graph[a][c], graph[a][b] + graph[b][c]);
					if(graph[a][c] != 12345678)
						result = max(result, graph[a][c]);		// 실제 그래프가 이어진 경로에서 가중치의 합이 가장 큰 값을 저장한다.
				}
			}
		}
		cout << result << endl;
	}
	return 0;
}