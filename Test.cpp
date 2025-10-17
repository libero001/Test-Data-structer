#include"Linklist_tuozhan.cpp"

#include<iostream>
using namespace std;
int main()
{
	LinkList <int> l1,l2,l3,l4;
	int arr1[] = { 1,2,5,3,4,5 };
	int arr2[] = { 1,2,3,4,5 };
	int arr3[] = { 3,6,7,9 };
	l1.CreateListR(arr1, 6);
	//1.设计算法，将单链表L中的所有元素逆置；
	cout << "原链表：";
	l1.DispList();
	Reverse1(l1);
	cout << "逆置链表：";
	l1.DispList();
	//2.设计算法，删除单链表L中所有最大元素值的结点
	cout << "原链表：";
	l1.DispList();
	cout << "删除后最大值后链表：";
	Delmaxnodes(l1);
	l1.DispList();
	//3.设计算法，将两个递增有序整数单链表A和B合并到递增有序的单链表C中
	l2.CreateListR(arr2, 5);
	l3.CreateListR(arr3, 4);
	Merge2(l2, l3, l4);
	cout << "两个有序链表：";
	l2.DispList();
	l3.DispList();
	cout << "合并后链表：";
	l4.DispList();
	//4.设计算法，删除单链表L中所有值为e的结点
	cout << "原链表为：";
	l4.DispList();
	cout << "删除元素值为3后的链表：";
	Delx(l4, 3);
	l4.DispList();
	//
//5.设计算法，将单链表L中的所有奇数结点移动到其他元素的前面
	cout << "原链表为：";
	l4.DispList();
	cout << "移动后链表：";
	Move1(l4);
	l4.DispList();
	return 0;
}