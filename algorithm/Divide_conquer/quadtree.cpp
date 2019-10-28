#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
// algospot

int C;
string s;

string reverse(string::iterator& iter)
{
	string upperleft, upperright, lowerleft, lowerright;

	char head = *iter;
	iter++;

	if (head == 'b')
		return "b";
	if (head == 'w')
		return "w";
	//if (head == 'b' || head == 'w')
	//	return string(1, head);				// 위와 같은 결과.

	if (head == 'x')
	{
		upperleft = reverse(iter);
		upperright = reverse(iter);
		lowerleft = reverse(iter);
		lowerright = reverse(iter);
	}

	return "x" + lowerleft + lowerright + upperleft + upperright;
}

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> C;

	while (C--)
	{
		s.clear();
		cin >> s;

		string::iterator iter = s.begin();
		string result = reverse(iter);
		cout << result << endl;
	}
	return 0;
}