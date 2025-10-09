//# include <iostream>
//# include <cmath>
//using namespace std;
//void get_gen1(double a, double b, double c)
//{
//	double x1, x2;
//	x1 = -b + sqrt(b * b - 4 * a * c) / 2 * a;
//	x2 = -b - sqrt(b * b - 4 * a * c) / 2 * a;
//	cout << x1 << ' ' << x2<<endl;
//}
//void get_gen2(double a, double b, double c)
//{
//	double x1, x2;
//	x1 = -b + sqrt(b * b - 4 * a * c) / 2 * a;
//	x2 = -b - sqrt(b * b - 4 * a * c) / 2 * a;
//	cout << x1 <<endl;
//}
//void get_gen3(double a, double b, double c)
//{
//	
//	cout << "x1" <<'='<<-b/2*a<<'+'<< sqrt(-b * b + 4 * a * c)/2*a<<'i' << endl;
//	cout << "x2" <<'='<<-b/2*a<<'-'<< sqrt(-b * b + 4 * a * c)/2*a << 'i'<<endl;
//}
//
//int main()
//{
//	double  derta;
//	double a, b, c;
//	cin >> a >> b >> c;
//	derta = sqrt(b * b - 4 * a * c);
//	if (derta > 0)
//	{
//		get_gen1(a,b,c);
//	}
//	else if (derta == 0)
//	{
//		get_gen2(a,b,c);
//	}
//	else
//	{
//		get_gen3(a,b,c);
//	}
//	return 0;
//}
//# include <iostream>
//using namespace std;
//void get_ways()
//{
//	int i = 0;
//	int j = 0;
//	for (i = 1; i <= 3; i++)
//	{
//		for (j = 1; j <= 5; j++)
//		{
//			cout << "红球：" << i << ' ' << "白球: " << j << ' ' << "黑球：" << 8 - i - j << endl;
//		}
//	}
//}
//int main ()
//{
//	
//	//函数声明
//	void get_ways();
//	//函数调用
//	get_ways();
//	return 0;
//}

//# include <iostream>
//# include <cmath>
//using namespace std;
//int prime(int m)
//{
//	int i = 0;
//	for (i = 2; i <= sqrt(m); i ++)
//	{
//		if (m % i == 0)
//		{
//			return 0;
//		}
//	}
//	return 1;
//}
//void sal_fac(int m)
//{
//	cout << m << '=';
//	while (prime(m) == 0)
//	{
//		int t = 0;
//		for (t = 2; t <= sqrt(m); t++)
//		{
//			if (prime(t) == 1 && m % t == 0)
//			{
//				m /= t;
//				cout << t << " * ";
//				break;
//			}
//			
//		}
//	}
//	
//		cout << m << endl;
//}
//int main()
//{
//	int m;
//	cin >> m;
//	//函数声明
//	int prime(int m);
//	void sal_fac(int m);
//	if (prime(m) == 0)
//	{
//		sal_fac(m);
//
//	}
//	else
//	{
//		cout << "It is a prime number" << endl;
//	}
//	return 0;
//}

//# include <iostream>
//using namespace std;
//double my_pow(double x, int n)
//{
//	if (n > 0)
//	{
//		return x * my_pow(x, --n);
//	}
//	else
//	{
//		return 1;
//	}
//           
//}
//int main()
//{
//	double x;
//	int n;
//	cin >>x >> n;
//	//函数声明
//	double my_pow(double x, int n);
//	//函数调用
//	int ret = my_pow(x, n);
//	cout << ret << endl;
//	return 0;
//# include <iostream>
//# include <cmath>
//using namespace std;
//int prime(int w)
//{
//	int i = 0;
//	double  m = sqrt(w);
//	for (i = 2; i < m; i++)
//	{
//		if (w % i == 0)
//		{
//			return 0;
//		}
//	}
//	return 1;
//}
//void gotbaha(int n)
//{
//	int j;
//	for (j = 3; j < n; j += 2)
//	{
//		if (prime(j) == 1 && prime(n - j) == 1)
//		{
//			cout << n << "=" << j << "+" << n - j << endl;
//			break;
//		}
//
//	}
//}
//int main()
//{
//	int n = 0;
//	cin >> n;
//	if (n >=6&&n%2==0)
//		gotbaha(n);
//	else
//		cout << "输入错误!" << endl;
//	return 0;
//}
//#include<iostream>
//using namespace std;
//int Fn(int n)
//{
//	if (n > 1)
//	{
//		return n * n + Fn(n - 1);
//	}
//	else if (n==1)
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//int main()
//{
//	int n;
//	cin >> n;
//	if (n < 100)
//	{
//		int Fn(int n);
//		int ret = Fn(n);
//		printf("f(%d)=%d\n", n, ret);
//	}
//	return 0;
//}
//# include <iostream>
//using namespace std;
//void print(int n)
//{
//	
//	if (n <= 0)
//	{
//		return;
//	}
//	else 
//	{
//		print(n - 1);
//		cout<< n<<' ';
//				
//	}
//
//}
//int main()
//{
//	int n;
//	cin >> n;
//	void print(int n);
//	cout << "输出结果：";
//	print(n);
//	cout << endl;
//	return 0;
//}
//# include <iostream>
//using namespace std;
//void print(int m,int n)
//{
//
//	int tem = 0;
//	if (m > n)
//	{
//		tem = m ;
//		m = n;
//		n = tem;
//	}
//	if (n == m)
//	{
//		cout << m<<' ';
//	}
//	else
//	{
//		print(m,n-1);
//		cout << n << ' ';
//	}
//}
//int main()
//{
//	int n,m;
//	cin >> m>>n;
//	void print(int m,int n);
//	cout << "输出结果：";
//	print(m,n);
//	cout << endl;
//	return 0;
//}
# include <iostream>
using namespace std;
int gcd(int x, int y)
{
	int c = x % y;
	if (c == 0)
	{
		return y;
	}
	else
	{
		return gcd(y,c);
	}
}
int main()
{
	int x, y;
	cin >> x >> y;
	int gcd(int x, int y);
	int ret = gcd(x, y);
	printf("gcd(%d,%d)=%d", x, y, ret);
	return 0;
}