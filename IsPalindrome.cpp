# include"IsPalindrome.h"
# include <iostream>
using namespace std;
bool isPoalindrome(string str)
{
	SqStack <char>st;
	char e;
	int i = 0;
	while (i < str.length() / 2)
	{
		st.push(str[i]);
		i++;
	}
	if (str.length() % 2 == 1)
	{
		i++;
	}
	while (i < str.length())
	{
		if (st.empty()) return false;
		st.pop(e);
		if (e != str[i])return false;
		i++;
	}
	return true;
}