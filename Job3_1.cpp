# include <iostream>
using namespace std;
#include"LinkList.cpp"
int main()
{
	//A. 由含有若干元素的数组分别使用头插法和尾插法创建单链表A和单链表B，并输出单链表中各元素值、单链表的长度。
	int arrA[] = {1,2,3,4};
	int arrB[] = {5,6,7,8};
	LinkList <int> A,B;
	A.CreateListF(arrA, 4);
	B.CreateListR(arrB, 4); 
	cout << "A的长度：" << A.Getlength() << endl;
	cout << "A的各元素值：";
	A.DispList();
	cout << "B的长度：" << B.Getlength() << endl;
	cout << "B的各元素值：";
	B.DispList();

	//B. 在单链表末尾插入若干元素后，输出单链表中各元素值、单链表的长度。
	B.Add(9);
	B.Add(10);
	cout << "末尾插入元素后B的长度：" << B.Getlength() << endl;
	cout << "B的各元素值：";
	B.DispList();

	//C.在单链表中对指定位置处的元素值进行读取操作，并输出读取的值；
	int  e = 0;
	B.GetElem(2, e);
	cout << "第3个元素值为：" <<e<<endl;

	//D.在单链表中对指定位置处的元素值进行写入操作，并输出更新后的单链表；
	  e = 4;
	  cout << B.SetElem(2, e) << endl;
	cout << "B的长度：" << B.Getlength() << endl;
	cout << "B的各元素值：";
	B.DispList();
	
	//E.在单链表中进行查找操作，按照给定值在单链表中查找，若找到给出该元素所在序号；若找不到，则提示“该元素不在单链表中！”
	if (B.GetNo(6) != -1)
	{
		cout << "序号为：" << B.GetNo(6) << endl;
	}
	else
		cout << "该元素不在单链表中！" << endl;
	//F.在单链表指定位置进行元素插入，插入后，观察单链表元素值、单链表的长度。
	B.Insert(5, 8);
	cout << "B的长度：" << B.Getlength() << endl;
	cout << "B的各元素值：";
	B.DispList();
	//G.在单链表指定位置进行元素删除，删除后，观察单链表元素值、单链表的长度。
	B.Delete(6);
	cout << "B的长度：" << B.Getlength() << endl;
	cout << "B的各元素值：";
	B.DispList();
	return 0;
}