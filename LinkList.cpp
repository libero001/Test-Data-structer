# include <iostream>
using namespace std;
template<typename T>
struct LinkNode	//节点数据类型
{
	//存储数据元素
	T data;
	//后继节点指针
	LinkNode<T>* next;
	LinkNode():next(NULL){}
	LinkNode(T d):next(NULL),data(d){}
};
template<typename T>

class LinkList
{
public:
	LinkNode<T>* head;
	//构造函数
	LinkList()
	{
		head = new LinkNode<T>();
	}
	//析构函数
	~LinkList()
	{
		LinkNode<T> *p, *pre;
		pre = head;
		p = pre->next;
		while (p != NULL)
		{
			delete pre;
			pre = p;
			p = p->next;
		}
		delete pre;
	}
	//头插法建表
	void CreateListF(T a[], int n)
	{
		for (int i = 0; i < n; i++)
		{
			LinkNode<T>* s = new LinkNode<T>(a[i]);
			s->next = head->next;
			head->next = s;

		}
	}
	//尾插法
	void CreateListR(T a[], int n)
	{
		LinkNode<T>* r=head, *s;
		for (int i = 0; i < n; i++)
		{
			s = new LinkNode<T>(a[i]);
			r->next = s;
			r = s;

		}
		r->next = NULL;
	}
	//输出单链表中各元素值
	void DispList()
	{
		LinkNode<T>* p = head->next;
		while (p != NULL)
		{
			cout<<p->data << " ";
			p = p->next;
		}
		cout << endl;
	}
	//单链表的长度
	int Getlength()
	{
		LinkNode<T>* p = head;
		int count = 0;
		while (p->next != NULL)
		{
			count++;
			p = p->next;
		}
		return count;
	}
	//链表末尾插入元素
	void Add(T e)
	{
		LinkNode<T> *s=new LinkNode<T>(e);
		LinkNode<T> *p = head;
		while (p->next != NULL)
		{
			p = p->next;
		}
		p->next = s;
	}
	//读取指定位置的指针
	LinkNode <T>* Geti(int i)
	{
		if (i < -1) return NULL;
		LinkNode<T>* p = head;
		int j = -1;
		while (j < i && p != NULL)
		{
			j++;
			p = p->next;
		}
		return p;
	}
	//读取链表指定位置元素值
	bool GetElem(int i, T& e)
	{
		if (i < 0)return false;
		LinkNode<T>* p=Geti(i);
		if (p != NULL)
		{
			e = p->data;
			return true;
		}
		else
		{
			return false;
		}

	}
	//在指定位置进行写入
	bool SetElem(int i, T e)
	{
		if (i < 0)return false;
		LinkNode<T>* p = Geti(i);
		if (p != NULL)
		{
			 p->data =e;
			return true;
		}
		else
		{
			return false;
		}
	}
	//读取指定元素的序号
	int GetNo(T e)
	{
		int j = 0;
		LinkNode <T>* p = head->next;
		while (p != NULL && p->data != e)
		{
			j++;
			p = p->next;
		}
		if (p != NULL)
		{
			return j;
		}
		else
			return -1;
	}
	//指定位置插入
	bool Insert(int i, T e)
	{
		if (i < 0)
		{
			return false;
		}
		LinkNode <T>* p = Geti(i-1);
		if (p != NULL)
		{
			LinkNode <T>* s = new LinkNode<T>(e);
			s->next = p->next;
			p->next = s;
		}
		else
		{
			return false;
		}

	}
	//指定位置删除
	bool Delete(int i)
	{
		if (i < 0)
		{
			return false;
		}
		LinkNode <T>* p = Geti(i - 1);
		if (p != NULL)
		{
			LinkNode <T>* q = p->next;
			if (q != NULL)
			{
				p->next = q->next;
				delete q;
				return true;
			}
			else
				return false;
		}
		else
			return false;
	}
};