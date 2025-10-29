# include<string>
# include"Trans.h"
string trans(int d, int r)
{
	int x;
	SqStack <int>st;
	while (d > 0)
	{
		st.push(d % r);
		d /= r;

	}
	string chars = "0123456789ABCDEF";
	string s = "";
	while (!st.empty())
	{
		st.pop(x);

		s += chars[x];
	}
	return s;
}