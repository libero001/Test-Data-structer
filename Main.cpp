# include "SqList.cpp"
# include <iostream>
using namespace std;
int main()
{
	//建表
	SqList<int>S, S1,S2,S3;
	int arr[] = { 1,3,4,5 };
	int arr1[] = { 1,6,7,10 };
	int arr0[] = { 2,3,5,8 };
	S1.CreateList(arr, 4);
	S2.CreateList(arr1, 4);
	S.CreateList(arr0, 4);
	cout << "初始顺序表" << endl;
	S1.DispList();
	cout << "逆置后顺序表" << endl;
	Reverse(S1);
	S1.DispList();
	//删除指定元素
	//Deletex1(S1,1);
	//Deletex2(S1, 1);
	Deletex3(S1, 1);
	cout << "删除后顺序表" << endl;
	S1.DispList();
	//3.设计算法，删除顺序表L中从序号i开始的k个元素
	Deletek(S1,1, 1);
	cout << "删除多个元素后顺序表" << endl;
	S1.DispList();
	//4.设计算法，合并两个按元素值递增有序的顺序表A和B中的全部元素，得到新的顺序表C
	Merge2(S, S2, S3);
	cout << "合并后顺序表：" << endl;
	S3.DispList();
	//5..设计算法，在有序顺序表L中插入元素e，使得该顺序表依然有序
	Insert(S3, 9);
	cout << "插入后顺序表" << endl;
	S3.DispList();
	////6.设计算法，将顺序表L中所有值为奇数的元素移动其他元素的前面。
	Move(S3);
	cout << "移动后顺序表" << endl;
	S3.DispList();


	return 0;
}