#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <utility>
#include <vector>
using namespace std;
// algospot

int T, N;
pair<int, int> lunch[10001];

bool compare(const pair<int,int>& p1, const pair<int,int>& p2)	// eatTime이 큰 것이 맨 앞에 오도록 정렬
{
	return p1.second > p2.second;
}

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> T;

	while (T--)
	{
		cin >> N;
		for (int i = 0; i < N; i++)
			cin >> lunch[i].first;
		for (int i = 0; i < N; i++)
			cin >> lunch[i].second;
		sort(&lunch[0], &lunch[N], compare);

		int cookTime = 0;
		int eatTime = lunch[0].second;
		for (int i = 1; i < N; i++)
		{
			cookTime += lunch[i].first;
			if (eatTime < cookTime + lunch[i].second)
				eatTime = cookTime + lunch[i].second;
		}
		cout << lunch[0].first + eatTime << endl;
	}
	return 0;
}