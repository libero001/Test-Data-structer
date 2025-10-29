#include <iostream>
#include "IsMatch.h";
using namespace std;

bool Ismatch(string str)
{
	SqStack <char> st;
	int i = 0;
	char m;
	while (i < str.length())
	{
		if (str[i] == '(' || str[i] == '[' || str[i] == '{')
			st.push(str[i]);
		else
		{
			if (str[i] == ')')
			{
				if (st.empty()) return false;
				st.pop(m);
				if (m != '(')

					return false;
			}
			if (str[i] == ']')
			{
				if (st.empty()) return false;
				st.pop(m);
				if (m != '[')

					return false;
			}
			if (str[i] == '}')
			{
				if (st.empty()) return false;
				st.pop(m);
				if (m != '{')

					return false;
			}
		}
		i++;
	}
	return st.empty();
}