#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define MAX 9999
using namespace std;
// algospot

int C;
vector<int> sc[10];
int clockHour[16];

bool check()
{
	for (int i = 0; i < 16; i++)
	{
		if (clockHour[i] != 12)
			return false;
	}
	return true;
}

//void rotate(int clockNum, int cnt)
//{
//	clockHour[clockNum] = clockHour[clockNum] + (3 * cnt);
//	if (clockHour[clockNum] > 12)
//		clockHour[clockNum] -= 12;
//}

int solve(int scNum)
{
	if (check())
		return 0;

	if (scNum == 10)
		return MAX;

	int ret = MAX;

	for (int i = 1; i <= 4; i++)
	{
		/*for (int j = 0; j < sc[scNum].size(); j++)  .. 이렇게 쓰면 안되는이유 : i가 2인경우, 전체포문을 보면 시계가 2번이 아닌 3번이 돌아가게된다.
			rotate(sc[scNum][j], i);*/

		for (int j = 0; j < sc[scNum].size(); j++)
		{
			clockHour[sc[scNum][j]] += 3;
			if (clockHour[sc[scNum][j]] == 15)
				clockHour[sc[scNum][j]] = 3;
		}
		ret = min(ret, (i%4) + solve(scNum + 1));	// 4번 누르는 것은 처음상태와 같으므로 카운트하지 않는다.
	}

	return ret;
}

int main()
{
	std::ios::sync_with_stdio(false);

	sc[0] = { 0,1,2 };
	sc[1] = { 3,7,9,11 };
	sc[2] = { 4,10,14,15 };
	sc[3] = { 0,4,5,6,7 };
	sc[4] = { 6,7,8,10,12 };
	sc[5] = { 0,2,14,15 };
	sc[6] = { 3,14,15 };
	sc[7] = { 4,5,7,14,15 };
	sc[8] = { 1,2,3,4,5 };
	sc[9] = { 3,4,5,9,13 };

	cin >> C;

	while (C--)
	{
		for (int i = 0; i < 16; i++)
			cin >> clockHour[i];

		int result = solve(0);
		if (result >= MAX)
			cout << "-1" << endl;
		else
			cout << result << endl;
	}

	return 0;
}