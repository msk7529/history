#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#define MAX 987654321
using namespace std;
// baekjoon

int arr[10];
int visit[1001];
int K;
int result;
vector<int> card;

int check(int num)
{
	string str = to_string(num);
	int size = str.size();
	bool ch = true;
	for (int i = 0; i < size; i++)
	{
		if (arr[str[i] - 48] == 0)
		{
			ch = false;
			break;
		}
	}
	if (ch == false) return 0;
	

	else return 1;
}

void dynamic(int num2, int cnt)
{
	for (int i = 0; i < card.size(); i++)
	{
		if (card[i] == 0 || card[i] == 1)
			continue;

		if (card[i] > K)
			break;

		if (num2 % card[i] == 0)
		{
			int sub_cnt = cnt + 1;
			int R = num2 / card[i];
			if (check(R) == 1)
				result = min(result, sub_cnt);
			else
				dynamic(R, sub_cnt);
		}
	}
}

void makecard(int curr)
{
	for (int i = 0; i < 10; i++)
	{
		if (arr[i])
		{
			int next = 10 * curr + i;
			if (next <= 1000 && visit[next] == 0)
			{
				visit[next] = 1;
				card.push_back(next);
				makecard(next);
			}
		}
	}
}


int main()
{
	int T, N, M;
	int tmp;
	cin >> T;

	while (T--)
	{
		card.clear();
		memset(visit, 0, sizeof(visit));
		memset(arr, 0, sizeof(arr));
		cin >> N;
		while (N--)
		{
			cin >> tmp;
			arr[tmp] = 1;
		}

		cin >> M;
		makecard(0);
		sort(card.begin(), card.end());

		while (M--)
		{
			result = MAX;
			cin >> K;
			if (check(K) == 1)
				printf("0\n");
			else
			{
				dynamic(K, 0);

				if (result == MAX)
					printf("-1\n");
				else
					printf("%d\n", result);
			}
		}
	}

	return 0;

}