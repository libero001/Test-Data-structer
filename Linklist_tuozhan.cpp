# include"Linklist.cpp"
# include<iostream>
using namespace std;
//1.设计算法，将单链表L中的所有元素逆置
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

//2.设计算法，删除单链表L中所有最大元素值的结点;
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

//3.设计算法，将两个递增有序整数单链表A和B合并到递增有序的单链表C中
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
//4.设计算法，删除单链表L中所有值为e的结点
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
	// 空链表直接返回（处理head为nullptr或无有效节点的情况）
	if (L.head == nullptr || L.head->next == nullptr) {
		return;
	}

	// 临时指针：分别指向奇数链、偶数链的头和尾
	LinkNode<T>* oddHead = nullptr;  // 奇数链头
	LinkNode<T>* oddTail = nullptr;  // 奇数链尾
	LinkNode<T>* evenHead = nullptr; // 偶数链头
	LinkNode<T>* evenTail = nullptr; // 偶数链尾

	LinkNode<T>* p = L.head->next;   // 遍历原链表
	LinkNode<T>* nextNode = nullptr; // 保存下一个节点，防止断链

	while (p != nullptr) {
		nextNode = p->next;  // 提前保存下一个节点
		p->next = nullptr;   // 断开当前节点与原链表的联系

		if (p->data % 2 != 0) { // 奇数节点：加入奇数链
			if (oddHead == nullptr) {
				oddHead = p;    // 第一个奇数节点作为链头
				oddTail = p;
			}
			else {
				oddTail->next = p; // 挂载到奇数链尾部
				oddTail = p;       // 更新尾部指针
			}
		}
		else { // 偶数节点：加入偶数链
			if (evenHead == nullptr) {
				evenHead = p;    // 第一个偶数节点作为链头
				evenTail = p;
			}
			else {
				evenTail->next = p; // 挂载到偶数链尾部
				evenTail = p;       // 更新尾部指针
			}
		}

		p = nextNode; // 遍历下一个节点
	}

	// 拼接奇数链和偶数链，并挂载到原链表
	if (oddHead != nullptr) {
		// 奇数链存在：原链表头指向奇数链头，奇数链尾连接偶数链头
		L.head->next = oddHead;
		oddTail->next = evenHead;
	}
	else {
		// 奇数链为空：原链表直接指向偶数链
		L.head->next = evenHead;
	}
}