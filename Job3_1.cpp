# include <iostream>
using namespace std;
#include"LinkList.cpp"
int main()
{
	//A. �ɺ�������Ԫ�ص�����ֱ�ʹ��ͷ�巨��β�巨����������A�͵�����B��������������и�Ԫ��ֵ��������ĳ��ȡ�
	int arrA[] = {1,2,3,4};
	int arrB[] = {5,6,7,8};
	LinkList <int> A,B;
	A.CreateListF(arrA, 4);
	B.CreateListR(arrB, 4); 
	cout << "A�ĳ��ȣ�" << A.Getlength() << endl;
	cout << "A�ĸ�Ԫ��ֵ��";
	A.DispList();
	cout << "B�ĳ��ȣ�" << B.Getlength() << endl;
	cout << "B�ĸ�Ԫ��ֵ��";
	B.DispList();

	//B. �ڵ�����ĩβ��������Ԫ�غ�����������и�Ԫ��ֵ��������ĳ��ȡ�
	B.Add(9);
	B.Add(10);
	cout << "ĩβ����Ԫ�غ�B�ĳ��ȣ�" << B.Getlength() << endl;
	cout << "B�ĸ�Ԫ��ֵ��";
	B.DispList();

	//C.�ڵ������ж�ָ��λ�ô���Ԫ��ֵ���ж�ȡ�������������ȡ��ֵ��
	int  e = 0;
	B.GetElem(2, e);
	cout << "��3��Ԫ��ֵΪ��" <<e<<endl;

	//D.�ڵ������ж�ָ��λ�ô���Ԫ��ֵ����д���������������º�ĵ�����
	  e = 4;
	  cout << B.SetElem(2, e) << endl;
	cout << "B�ĳ��ȣ�" << B.Getlength() << endl;
	cout << "B�ĸ�Ԫ��ֵ��";
	B.DispList();
	
	//E.�ڵ������н��в��Ҳ��������ո���ֵ�ڵ������в��ң����ҵ�������Ԫ��������ţ����Ҳ���������ʾ����Ԫ�ز��ڵ������У���
	if (B.GetNo(6) != -1)
	{
		cout << "���Ϊ��" << B.GetNo(6) << endl;
	}
	else
		cout << "��Ԫ�ز��ڵ������У�" << endl;
	//F.�ڵ�����ָ��λ�ý���Ԫ�ز��룬����󣬹۲쵥����Ԫ��ֵ��������ĳ��ȡ�
	B.Insert(5, 8);
	cout << "B�ĳ��ȣ�" << B.Getlength() << endl;
	cout << "B�ĸ�Ԫ��ֵ��";
	B.DispList();
	//G.�ڵ�����ָ��λ�ý���Ԫ��ɾ����ɾ���󣬹۲쵥����Ԫ��ֵ��������ĳ��ȡ�
	B.Delete(6);
	cout << "B�ĳ��ȣ�" << B.Getlength() << endl;
	cout << "B�ĸ�Ԫ��ֵ��";
	B.DispList();
	return 0;
}