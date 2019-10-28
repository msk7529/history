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
// backjoon

int N, M, u, v, d, ret, cnt;
char sex[1001];
vector<pair<int, pair<int, int>>> edges;

struct DisjointSet
{
	vector<int> parent, rank;

	DisjointSet(int n) : parent(n + 1), rank(n + 1, 1)
	{
		for (int i = 1; i <= n; i++)
			parent[i] = i;
	}

	int find(int u)
	{
		if (u == parent[u])
			return u;
		return parent[u] = find(parent[u]);
	}

	void merge(int u, int v)
	{
		u = find(u), v = find(v);
		
		if (u == v)
			return;

		if (rank[u] > rank[v])
			swap(u, v);

		parent[u] = v;
		if (rank[u] == rank[v])
			rank[v]++;
	}
};

void kruskal()
{
	DisjointSet sets(N);

	for (int i = 0; i < edges.size(); i++)
	{
		int cost = edges[i].first, u = edges[i].second.first, v = edges[i].second.second;
		
		if (sets.find(u) == sets.find(v) || sex[u] == sex[v])
			continue;

		sets.merge(u, v);
		ret += cost;
		cnt++;
	}
}

int main()
{
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		cin >> sex[i];
	for (int i = 0; i < M; i++)
	{
		cin >> u >> v >> d;
		edges.push_back({ d, {u,v} });
	}
	sort(edges.begin(), edges.end());

	kruskal();

	if (cnt != N - 1)
		cout << "-1" << endl;
	else
		cout << ret << endl;
	return 0;
}
