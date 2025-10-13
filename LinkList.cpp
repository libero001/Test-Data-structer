# include <iostream>
using namespace std;
template<typename T>
struct LinkNode	//�ڵ���������
{
	//�洢����Ԫ��
	T data;
	//��̽ڵ�ָ��
	LinkNode<T>* next;
	LinkNode():next(NULL){}
	LinkNode(T d):next(NULL),data(d){}
};
template<typename T>

class LinkList
{
public:
	LinkNode<T>* head;
	//���캯��
	LinkList()
	{
		head = new LinkNode<T>();
	}
	//��������
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
	//ͷ�巨����
	void CreateListF(T a[], int n)
	{
		for (int i = 0; i < n; i++)
		{
			LinkNode<T>* s = new LinkNode<T>(a[i]);
			s->next = head->next;
			head->next = s;

		}
	}
	//β�巨
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
	//����������и�Ԫ��ֵ
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
	//������ĳ���
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
	//����ĩβ����Ԫ��
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
	//��ȡָ��λ�õ�ָ��
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
	//��ȡ����ָ��λ��Ԫ��ֵ
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
	//��ָ��λ�ý���д��
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
	//��ȡָ��Ԫ�ص����
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
	//ָ��λ�ò���
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
	//ָ��λ��ɾ��
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