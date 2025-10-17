# include"Linklist.cpp"
# include<iostream>
using namespace std;
//1.����㷨����������L�е�����Ԫ������
template<typename T>
void Reverse1(LinkList<T>& L)
{
	LinkNode<T>* p = L.head->next, * q;
	L.head->next = NULL;
	while (p != NULL)
	{
		q = p;
		p = p->next;
		q->next = L.head->next;
		L.head->next = q;
		
	}

}

//2.����㷨��ɾ��������L���������Ԫ��ֵ�Ľ��;
template<typename T>
void Delmaxnodes(LinkList<T>& L)
{
	LinkNode<T>* p = L.head->next, * q;
	int max = p->data;
	while (p != NULL)
	{
		if (p->data > max)
		{
			max = p->data;
		}
		p = p->next;
	}
	p = L.head->next;
	q = L.head;
	while (p != NULL)
	{
		if (p->data == max)
		{
			q->next = p->next;
		}
		else
		{
			q = q->next;
		}
		p = p->next;
	}

}

//3.����㷨��������������������������A��B�ϲ�����������ĵ�����C��
template<typename T>

void Merge2(LinkList<T>& A, LinkList<T>& B, LinkList<T>& C)
{
	LinkNode<T>* p = A.head->next, * q = B.head->next;
	while (p != NULL && q != NULL)
	{
		if (p->data > q->data)
		{
			C.Add(q->data);
			q = q->next;
		}
		else if(p->data==q->data)
		{
			C.Add(p->data);
			C.Add(q->data);
			p = p->next;
			q = q->next;

		}
		else
		{
			C.Add(p->data);
			p = p->next;

		}
	}
	while (p != NULL)
	{
		C.Add(p->data);
		p = p->next;
	}
	while (q != NULL)
	{
		C.Add(q->data);
		q = q->next;

	}
}
//4.����㷨��ɾ��������L������ֵΪe�Ľ��
template<typename T>

void Delx(LinkList<T>& L, T e)
{
	LinkNode<T>* p = L.head->next, * q;
	q = L.head;
	while (p != NULL)
	{
		if (p->data == e)
		{
			q->next = p->next;
		}
		else
		{
			q = q->next;
		}
		p = p->next;
	}
}
template<typename T>
void Move1(LinkList<T>& L) {
	// ������ֱ�ӷ��أ�����headΪnullptr������Ч�ڵ�������
	if (L.head == nullptr || L.head->next == nullptr) {
		return;
	}

	// ��ʱָ�룺�ֱ�ָ����������ż������ͷ��β
	LinkNode<T>* oddHead = nullptr;  // ������ͷ
	LinkNode<T>* oddTail = nullptr;  // ������β
	LinkNode<T>* evenHead = nullptr; // ż����ͷ
	LinkNode<T>* evenTail = nullptr; // ż����β

	LinkNode<T>* p = L.head->next;   // ����ԭ����
	LinkNode<T>* nextNode = nullptr; // ������һ���ڵ㣬��ֹ����

	while (p != nullptr) {
		nextNode = p->next;  // ��ǰ������һ���ڵ�
		p->next = nullptr;   // �Ͽ���ǰ�ڵ���ԭ�������ϵ

		if (p->data % 2 != 0) { // �����ڵ㣺����������
			if (oddHead == nullptr) {
				oddHead = p;    // ��һ�������ڵ���Ϊ��ͷ
				oddTail = p;
			}
			else {
				oddTail->next = p; // ���ص�������β��
				oddTail = p;       // ����β��ָ��
			}
		}
		else { // ż���ڵ㣺����ż����
			if (evenHead == nullptr) {
				evenHead = p;    // ��һ��ż���ڵ���Ϊ��ͷ
				evenTail = p;
			}
			else {
				evenTail->next = p; // ���ص�ż����β��
				evenTail = p;       // ����β��ָ��
			}
		}

		p = nextNode; // ������һ���ڵ�
	}

	// ƴ����������ż�����������ص�ԭ����
	if (oddHead != nullptr) {
		// ���������ڣ�ԭ����ͷָ��������ͷ��������β����ż����ͷ
		L.head->next = oddHead;
		oddTail->next = evenHead;
	}
	else {
		// ������Ϊ�գ�ԭ����ֱ��ָ��ż����
		L.head->next = evenHead;
	}
}