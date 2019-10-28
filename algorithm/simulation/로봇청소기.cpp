#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>
#include <utility>
#include <list>
#define MAX 987654321
using namespace std;
typedef unsigned long long ul;
// baekjoon

int N, M, r, c, d;
int arr[51][51];
int ret;
int point[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };

void count(int y, int x)	// ������ġû��
{
	if (arr[y][x] == 0)
	{
		arr[y][x] = 2;		// ���� ������ ���� �ݵ�� 1�� �ƴ� 2�� �ؾ���. ���������� ����.
		ret++;
	}
}

int main()
{
	ios::sync_with_stdio(false);

	cin >> N >> M >> r >> c >> d;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cin >> arr[i][j];
	}

	int y = r, x = c;
	while (1)
	{
		count(y, x);

		int ny, nx;
		bool b = false;
		for (int i = 0; i < 4; i++)		// �ִ� �׹��� Ž��
		{
			d = (d + 3) % 4;
			ny = y + point[d][0], nx = x + point[d][1];
			if (ny >= 0 && ny < N && nx >= 0 && nx < M && arr[ny][nx] == 0)
			{
				b = true;
				break;
			}
		}

		if (b)	// �ѹ����̶� û�Ҵ��� ���� ������ continue
		{
			y = ny, x = nx;
			continue;
		}
		else	// ��� ������ û�ҵǾ��ų� ���ΰ��
		{
			ny = y - point[d][0], nx = x - point[d][1];
			if (ny < 0 || ny >= N || nx < 0 || nx >= M || arr[ny][nx] == 1)		// �ڰ� ���ΰ��ų� ������ �ʰ����� ��� break
				break;
			else	// �ڰ� ���̾ƴѰ��(��, û�ҵȰ����ΰ��)
			{
				y = ny, x = nx;
				continue;
			}
		}
	}
	cout << ret << endl;
	return 0;
}