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
	//1.����㷨����������L�е�����Ԫ�����ã�
	cout << "ԭ����";
	l1.DispList();
	Reverse1(l1);
	cout << "��������";
	l1.DispList();
	//2.����㷨��ɾ��������L���������Ԫ��ֵ�Ľ��
	cout << "ԭ����";
	l1.DispList();
	cout << "ɾ�������ֵ������";
	Delmaxnodes(l1);
	l1.DispList();
	//3.����㷨��������������������������A��B�ϲ�����������ĵ�����C��
	l2.CreateListR(arr2, 5);
	l3.CreateListR(arr3, 4);
	Merge2(l2, l3, l4);
	cout << "������������";
	l2.DispList();
	l3.DispList();
	cout << "�ϲ�������";
	l4.DispList();
	//4.����㷨��ɾ��������L������ֵΪe�Ľ��
	cout << "ԭ����Ϊ��";
	l4.DispList();
	cout << "ɾ��Ԫ��ֵΪ3�������";
	Delx(l4, 3);
	l4.DispList();
	//
//5.����㷨����������L�е�������������ƶ�������Ԫ�ص�ǰ��
	cout << "ԭ����Ϊ��";
	l4.DispList();
	cout << "�ƶ�������";
	Move1(l4);
	l4.DispList();
	return 0;
}