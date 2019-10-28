#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

int C;
stack<char> st;

int main()
{
	std::ios::sync_with_stdio(false);

	cin >> C;

	while (C--)
	{
		string s;
		cin >> s;

		int i = 0;
		bool result = true;
		while (i < s.length())
		{
			if (s[i] == ')')
			{
				if (!st.empty() && st.top() == '(')
				{
					i++;
					st.pop();
				}
				else
				{
					result = false;
					break;
				}
			}
			else if (s[i] == '}')
			{
				if (!st.empty() && st.top() == '{')
				{
					i++;
					st.pop();
				}
				else
				{
					result = false;
					break;
				}
			}
			else if (s[i] == ']')
			{
				if (!st.empty() && st.top() == '[')
				{
					i++;
					st.pop();
				}
				else
				{
					result = false;
					break;
				}
			}
			else
			{
				st.push(s[i]);
				i++;
			}
		}
		if (st.empty() && result == true)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;

		while (!st.empty())
			st.pop();
	}
	return 0;
}