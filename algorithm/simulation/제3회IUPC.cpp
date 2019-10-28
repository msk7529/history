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
#define MAX 987654321
using namespace std;
// baekjoon

int N, A, B, C;
set<vector<int>> s;

vector<int> getPrime(int n)
{
	vector<int> ret;

	for (int i = 2; i <= sqrt(n); i++)
	{
		while (n%i == 0)
		{
			ret.push_back(i);
			n /= i;
		}
	}
	if (n != 1)
		ret.push_back(n);

	sort(ret.begin(), ret.end());
	return ret;
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A >> B >> C;
		vector<int> fa = getPrime(A);
		vector<int> fb = getPrime(B);
		vector<int> fc;

		s.insert(fa);
		
		while(C--)
		{
			fc.resize(fa.size() + fb.size());
			merge(fa.begin(), fa.end(), fb.begin(), fb.end(), fc.begin());
			s.insert(fc);
			fa = fc;
			fc.clear();
		}
	}
	cout << s.size() << endl;

	return 0;
}



