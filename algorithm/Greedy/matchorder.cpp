#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
// algospot

int C, N;
int russia[101];
int korea[101];
int result;

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> C;

	while (C--)
	{
		result = 0;
		cin >> N;
		for (int i = 0; i < N; i++)
			cin >> russia[i];
		for (int i = 0; i < N; i++)
			cin >> korea[i];
		sort(&russia[0], &russia[N]);
		sort(&korea[0], &korea[N]);

		int j = 0;
		for (int i = 0; i < N; i++)
		{
			if (russia[j] <= korea[i])
			{
				j++;
				result++;
			}
		}
		cout << result << endl;
	}
	return 0;
}