# include "SqList.cpp"
# include <iostream>
using namespace std;
int main()
{
	//����
	SqList<int>S, S1,S2,S3;
	int arr[] = { 1,3,4,5 };
	int arr1[] = { 1,6,7,10 };
	int arr0[] = { 2,3,5,8 };
	S1.CreateList(arr, 4);
	S2.CreateList(arr1, 4);
	S.CreateList(arr0, 4);
	cout << "��ʼ˳���" << endl;
	S1.DispList();
	cout << "���ú�˳���" << endl;
	Reverse(S1);
	S1.DispList();
	//ɾ��ָ��Ԫ��
	//Deletex1(S1,1);
	//Deletex2(S1, 1);
	Deletex3(S1, 1);
	cout << "ɾ����˳���" << endl;
	S1.DispList();
	//3.����㷨��ɾ��˳���L�д����i��ʼ��k��Ԫ��
	Deletek(S1,1, 1);
	cout << "ɾ�����Ԫ�غ�˳���" << endl;
	S1.DispList();
	//4.����㷨���ϲ�������Ԫ��ֵ���������˳���A��B�е�ȫ��Ԫ�أ��õ��µ�˳���C
	Merge2(S, S2, S3);
	cout << "�ϲ���˳���" << endl;
	S3.DispList();
	//5..����㷨��������˳���L�в���Ԫ��e��ʹ�ø�˳�����Ȼ����
	Insert(S3, 9);
	cout << "�����˳���" << endl;
	S3.DispList();
	////6.����㷨����˳���L������ֵΪ������Ԫ���ƶ�����Ԫ�ص�ǰ�档
	Move(S3);
	cout << "�ƶ���˳���" << endl;
	S3.DispList();


	return 0;
}