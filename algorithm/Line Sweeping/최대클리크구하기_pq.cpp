#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
using namespace std;
// baekjoon

int N;
struct click
{
	int start, end, idx;
};

bool comp(const click& a, const click& b)	// sort함수에서 정렬
{
	if (a.start == b.start)
		return a.end < b.end;
	return a.start < b.start;
}

struct comp2
{
	bool operator()(click c1, click c2)	// pq에서 end가 빠른순서대로 정렬.
	{
		return c1.end > c2.end;		// 위에 comp함수와 방향이 반대임을 주의.
	}
};

priority_queue<click, vector<click>, comp2> pq;
click arr[300001];

int main()
{
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i].start >> arr[i].end;
		arr[i].idx = i + 1;
	}

	if (N == 1)
	{
		cout << "1" << endl;
		cout << "1" << endl;
		return 0;
	}

	sort(&arr[0], &arr[N], comp);	// 시작점을 기준으로 정렬

	pq.push(arr[0]);
	int max_size = 1;
	int min_end = arr[0].end; 

	for (int i = 1; i < N; i++)
	{
		if (arr[i].start <= min_end)
		{
			pq.push(arr[i]);
			if (arr[i].end < min_end)
				min_end = arr[i].end;
		}
		else
		{
			while (!pq.empty() && arr[i].start > pq.top().end)
				pq.pop();
			pq.push(arr[i]);
			min_end = pq.top().end;
		}
		max_size = max(max_size, (int)pq.size());
	}

	printf("%d\n", max_size);

	while (!pq.empty())
		pq.pop();
	pq.push(arr[0]);
	min_end = arr[0].end;

	for (int i = 1; i < N; i++)
	{
		if (arr[i].start <= min_end)
		{
			pq.push(arr[i]);
			if (arr[i].end < min_end)
				min_end = arr[i].end;
		}
		else
		{
			while (!pq.empty() && arr[i].start > pq.top().end)
				pq.pop();
			pq.push(arr[i]);
			min_end = pq.top().end;
		}
		if (max_size == (int)pq.size())
		{
			while(!pq.empty())
			{
				printf("%d ", pq.top().idx);
				pq.pop();
			}
			return 0;
		}
	}
	return 0;
}