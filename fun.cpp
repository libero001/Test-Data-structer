# include <iostream>
# include <utility>
using namespace std;
template <class T1>
void fun1(T1 a, T1 b, T1 c)
{
	T1 d;
	d = a > b ? a : b;
	cout <<"最大值为" << (d>c?d:c)<<endl;
	d = a < b ? a : b;
	cout <<"最小值为" <<(d<c?d:c)<<endl;
	cout << "平均值为" << (a + b + c)/3.0 <<endl;
}



//利用函数模板：（a）实现冒泡排序函数，实现对数组中存放的n个值进行由小到大的排序；（b）实现数组元素输出函数。在main函数中用实际数据测试通过上述函数模板。
template <class T2>
void fun2(T2 arr[],int n)
{
	int i, j = 0;
	for (i = 1; i < n; i++)
	{
		for (j = 0; j < n - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
			}

		}
	}
	for (i = 0; i < n; i++)
	{
		cout << arr[i] << ' ';
		
	}
	cout << endl;

}

//T3：【课堂演示】用类模板编程实现一个动态数组Array。要求包含操作：构造函数、析构函数、元素插入、元素输出。在main函数中测试验证上述操作。

template <class T3>
class Array
{
private :
	T3* p;
	int len;
	int n;
public:
	Array(int n)
	{
		
		len = 0;
		p = new T3 [n];
		this->n = n;
	}
	~Array()
	{
		delete[] p;
	}
	void addarr(T3 c)
	{
		p[len] = c;
		len++;
	}
	void getarr()
	{
		for (int i = 0; i < n; i++)
		{
			cout<<p[i]<<' ';
		}
		cout << endl;
	}
};



//T4：【课堂练习】用类模板编程实现一个集合ADT。要求包含操作：构造函数、析构函数、集合求长度、获取指定位置元素、判断元素是否在集合中、元素添加/删除/、集合元素的输出等。

template <class T4>
class ADT
{
private:
	
	T4* p;
	int len;
public:
	ADT(int n=10)
	{
		len = 0;
		p = new T4[n];
	}
	~ADT()
	{
		delete[] p;
	}
	int getlen()
	{
		return len;
	}
	bool Isin(T4 a)
	{
		int i = 0;
		while (a != p[i]&&i<len)
		{
			i++;
		}
		if (i >= len)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	T4 getys(int m)
	{
		if (m >= 0 && m < len)
		{
			return p[m];
		}
		else
			throw "参数i错误";
	}
	void add(T4 e)
	{
		if (!Isin(e))
		{
			p[len] = e;
			len++;
		}
	}
	void dele(T4 e)
	{
		int j = 0;
		while (j < len && p[j] != e)
			j++;
		if (j >= len)return;
		else
		{
			for (int i = j + 1; i < len; i++)
			{
				p[i - 1] = p[i];

			}
		}
		len--;
	}
	void Print()
	{
		for (int i = 0; i < len; i++)
		{
			cout << p[i] << ' ' ;
		}
		cout << endl;
	}
	ADT copy()
	{
		 ADT A1;
		 A1.len = len;
		for (int i = 0; i < len; i++)
		{
			A1.p[i] = p[i];
		}
	
		return A1;
	}
	ADT Union(ADT& A2)  {
		ADT A3 = this->copy(); // 先拷贝A1到A3
		for (int i = 0; i < A2.len; i++) {
			T4 m = A2.p[i]; // 直接访问private成员（同类型类可互访，更高效）
			if (!A3.Isin(m)) {
				A3.add(m); // 向A3添加A2中不存在的元素
			}
		}
		return A3; // 返回新的并集对象
	}
	ADT Inter(ADT& A2)
	{
		 ADT  A3;
		for (int i = 0; i < len; i++)
		{
			T4 m = p[i];
			if (A2.Isin(m))
			{
				A3.add(m);
			}
		}
		return A3;
	}
	ADT Diff(ADT& A2)
	{
		 ADT A3;
		for (int i = 0; i < len ; i++)
		{
			T4 m = p[i];
			if (!A2.Isin(m))
			{
				A3.add(m);
			}
		}
		return A3;
	}
};
int main()
{
	ADT <int>A1;
	ADT<int>A2;
	A1.add(1);
	A1.add(3);
	A1.add(6);
	A1.Print();
	cout << "A1长度 ";
	cout<<A1.getlen();
	cout << endl;
	A2.add(2);
	A2.add(3);
	A2.Print();
	cout << "A1和A2并集:";
	ADT <int>A3=A1.Union(A2);
	A3.Print();
	cout << "A1和A2的差集:";
	ADT <int>A4 = A1.Diff(A2);
	A4.Print();
	cout << "A1和A2的交集:";
	ADT <int>A5 = A1.Inter(A2);
	A5.Print();
	return 0;

}