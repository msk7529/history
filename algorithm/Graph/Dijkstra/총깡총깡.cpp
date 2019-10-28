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

int N, M, J, K, X, Y, Z, house;
vector<pair<int,int>> adj[5002];	// (인접정점번호, 가중치)
vector<int> A, B;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

vector<int> dijkstra()
{
	vector<int> dist(N + 1, MAX);
	dist[J] = 0;

	pq.push({ 0,J });

	while (!pq.empty())
	{
		int cost = pq.top().first, here = pq.top().second;
		pq.pop();

		if (dist[here] < cost)
			continue;

		for (int i = 0; i < adj[here].size(); i++)
		{
			int next = adj[here][i].first;
			int nextDist = adj[here][i].second + cost;
			if (dist[next] > nextDist)
			{
				dist[next] = nextDist;
				pq.push({ nextDist, next });
			}
		}
	}
	return dist;
}

int main()
{
	cin >> N >> M >> J >> K;
	for (int i = 0; i < K; i++)
	{
		cin >> house;
		A.push_back(house);
	}
	for (int i = 0; i < K; i++)
	{
		cin >> house;
		B.push_back(house);
	}
	for (int i = 0; i < M; i++)
	{
		cin >> X >> Y >> Z;
		adj[X].push_back({ Y,Z });
		adj[Y].push_back({ X,Z });
	}

	vector<int> dist = dijkstra();
	
	int ret = MAX;
	char C = 'A';

	for (int i = 0; i < K; i++)
	{
		if (dist[B[i]] < ret)
		{
			ret = dist[B[i]];
			C = 'B';
		}
	}

	for (int i = 0; i < K; i++)
	{
		if (dist[A[i]] <= ret)
		{
			ret = dist[A[i]];
			C = 'A';
		}
	}

	if (ret == MAX)
		cout << "-1" << endl;
	else
	{
		cout << C << endl;
		cout << ret << endl;
	}

	return 0;
}