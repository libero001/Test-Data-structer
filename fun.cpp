# include <iostream>
# include <utility>
using namespace std;
template <class T1>
void fun1(T1 a, T1 b, T1 c)
{
	T1 d;
	d = a > b ? a : b;
	cout <<"���ֵΪ" << (d>c?d:c)<<endl;
	d = a < b ? a : b;
	cout <<"��СֵΪ" <<(d<c?d:c)<<endl;
	cout << "ƽ��ֵΪ" << (a + b + c)/3.0 <<endl;
}



//���ú���ģ�壺��a��ʵ��ð����������ʵ�ֶ������д�ŵ�n��ֵ������С��������򣻣�b��ʵ������Ԫ�������������main��������ʵ�����ݲ���ͨ����������ģ�塣
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

//T3����������ʾ������ģ����ʵ��һ����̬����Array��Ҫ��������������캯��������������Ԫ�ز��롢Ԫ���������main�����в�����֤����������

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



//T4����������ϰ������ģ����ʵ��һ������ADT��Ҫ��������������캯�������������������󳤶ȡ���ȡָ��λ��Ԫ�ء��ж�Ԫ���Ƿ��ڼ����С�Ԫ�����/ɾ��/������Ԫ�ص�����ȡ�

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
			throw "����i����";
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
		ADT A3 = this->copy(); // �ȿ���A1��A3
		for (int i = 0; i < A2.len; i++) {
			T4 m = A2.p[i]; // ֱ�ӷ���private��Ա��ͬ������ɻ��ã�����Ч��
			if (!A3.Isin(m)) {
				A3.add(m); // ��A3���A2�в����ڵ�Ԫ��
			}
		}
		return A3; // �����µĲ�������
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
	cout << "A1���� ";
	cout<<A1.getlen();
	cout << endl;
	A2.add(2);
	A2.add(3);
	A2.Print();
	cout << "A1��A2����:";
	ADT <int>A3=A1.Union(A2);
	A3.Print();
	cout << "A1��A2�Ĳ:";
	ADT <int>A4 = A1.Diff(A2);
	A4.Print();
	cout << "A1��A2�Ľ���:";
	ADT <int>A5 = A1.Inter(A2);
	A5.Print();
	return 0;

}