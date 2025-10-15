# include <iostream>
const int initcap = 5;
using namespace std;
template <typename T>
class SqList
{
public:
	T* data;
	int capacity;
	int length;
	SqList()
	{
		data = new T[initcap];
		capacity = initcap;
		length = 0;
	}
	SqList(SqList <T>& s)
	{
		capacity = s.capacity;
		length = s.length;
		data = new T[capacity];
		int i = 0;
		for (i = 0; i < length; i++)
		{
			data[i] = s.data[i];
		}
	}
	~SqList()
	{
		delete[] data;
	}
	//改变顺序表容量
	void recap(int newcap)
	{
		if (newcap < 0)
			return;
		T* olddata = data;
		data = new T[newcap];
		capacity = newcap;
		int i = 0;
		for (i = 0; i < length; i++)
		{
			data[i] = olddata[i];
		}
		delete[]olddata;
	}
	//创建顺序表
	void CreateList(T a[], int n)
	{
		int i = 0;
		for (i = 0; i < n; i++)
		{
			if (length == capacity)
			{
				recap(2 * length);
			}
			data[i] = a[i];
			length++;

		}
	}

	//输出顺序表元素
	void DispList()
	{
		int i = 0;
		for (; i < length; i++)
		{
			cout << data[i] << ' ';

		}
		cout << endl;
	}
	//输出顺序表长度
	int Getlength()
	{
		return length;
	}
	//输出顺序表容量
	int GetCapacity()
	{
		return capacity;
	}
	//顺序表末尾插入元素
	void Add(T e)
	{
		if (length == capacity)
		{
			recap(2 * length);
		}
		data[length] = e;
		length++;
	}
	//读取指定位置的元素
	bool GetElem(int i, T& e)
	{
		if (i < 0 || i >= length)
			return false;
		e = data[i];
		return true;
	}
	//设置指定位置的元素值
	bool SetElem(int i, T e)
	{
		if (i < 0 || i >= length)
			return false;
		data[i] = e;
		return true;
	}
	//找出指定元素值的序号
	int GetNo(T e)
	{
		int i = 0;

		for (i = 0; i < length; i++)
		{
			if (data[i] == e)
				return i;

		}
		return -1;
	}
	//指定位置插入元素
	bool Insert(int i, T e)
	{

		if (i < 0 || i >= length)
			return false;
		if (length == capacity)
		{
			recap(2 * length);
		}
		for (int j = length; j > i; j--)
		{
			data[j] = data[j - 1];
		}
		data[i] = e;
		length++;
		return true;
	}
	//删除指定元素
	bool Delete(int i)
	{

		if (i < 0 || i >= length)
			return false;
		for (int j = i; j < length - 1; j++)
		{
			data[j] = data[j + 1];
		}
		length--;
		if (capacity > initcap && length < capacity / 4)
		{
			recap(capacity / 2);
		}
		return true;
	}

};
template <typename T>
//实现顺序表逆置
void Reverse(SqList<T>& L)
{
	int i = 0, j = L.length - 1;
	while (i < j)
	{
		swap(L.data[i], L.data[j]);
		i++;
		j--;
	}
}
//2.设计算法，删除顺序表L中所有值为x的元素；
//(1).整体建表法
template <typename T>
void Deletex1(SqList<T>& L, int x)
{
	int i = 0, k = 0;
	for (i = 0; i < L.length; i++)
	{
		if (L.data[i] != x)
		{
			L.data[k] = L.data[i];
			k++;
		}
	}
	L.length = k;
}
//(2)元素移动法
template <typename T>
void Deletex2(SqList<T>& L, int x)
{
	int k = 0;
	for (int i = 0; i < L.length; i++)
	{
		if (L.data[i] != x)
		{
			L.data[i - k] = L.data[i];
		}
		else
		{
			k++;
		}
	}
	L.length -= k;
}
//(3)区间划分法
template <typename T>
void Deletex3(SqList<T>& L, int x)
{
	int i = -1;
	int j = 0;
	for (j = 0; j < L.length; j++)
	{
		if (L.data[j] != x)
		{
			i++;
			if (i != j)
			{
				swap(L.data[i], L.data[j]);
			}

		}
	}
	L.length = i + 1;
}

//3.设计算法，删除顺序表L中从序号i开始的k个元素
template <typename T>
bool Deletek(SqList<T>& L, int i, int k)
{
	if (i < 0 || k<1 || i + k>L.length || i + k < 1)
		return false;
	int j = 0;
	for (j = i + k; j < L.length; j++)
	{
		L.data[j - k] = L.data[j];
		i++;
	}
	L.length -= k;
	return true;
}

//4.设计算法，合并两个按元素值递增有序的顺序表A和B中的全部元素，得到新的顺序表C
//二路递归
template <typename T>
void Merge2(SqList<T> A, SqList<T> B, SqList<T>& C)
{
	int i = 0, j = 0;
	while (i < A.length && j < B.length)
	{
		if (A.data[i] < B.data[j])
		{
			C.Add(A.data[i]);
			i++;
		}
		else
		{
			C.Add(B.data[j]);
			j++;
		}
	}
		while (i < A.length)
		{
			C.Add(A.data[i]);
			i++;
		}
		while (j < B.length)
		{
			C.Add(B.data[j]);
			j++;
		}
	
}



//5..设计算法，在有序顺序表L中插入元素e，使得该顺序表依然有序
template <typename T>

bool Insert(SqList<T>& L, T e)
{
	if (L.length > L.capacity)
	{
		return false;
	}
	int i = 0;
	while (i<L.length)
	{
		if ( e < L.data[i])
		{
			break;
		}
		i++;
	}
	L.Insert(i,e);
	return true;
}
//6.设计算法，将顺序表L中所有值为奇数的元素移动其他元素的前面。
template <typename T>
void Move(SqList<T>& L)
{
	int count = 0;
	int num = 0;
	for (int i = L.length - 1; i >= count; i--)
	{
		if (L.data[i] % 2 != 0)
		{
			count++;
			num = L.data[i];
			L.Delete(i);
			L.Insert(0, num);
		}
	}
}
