#ifndef STACK_H  // 防止头文件重复包含
#define STACK_H
#include <iostream>
using namespace std;
template <typename T>
class SqStack
{
public:
	T* data;
	int top;
	const int MaxSize = 100;
	//顺序栈创建与销毁
	SqStack()
	{
		data = new T[MaxSize];
		top = -1;
	}
	~SqStack()
	{
		delete[]data;
	}
	//判断栈是否为空
	bool empty()
	{
		return top == -1;
	}
	//进栈
	bool push(T e)
	{
		if (top == MaxSize - 1)return false;
		top++;
		data[top] = e;
		return true;
	}
	//出栈
	bool pop(T& e)
	{
		if (top == -1)return false;
		e = data[top];
		top--;
	}
	//取栈顶元素
	bool gettop(T& e)
	{
		if (top == -1)return false;
		e = data[top];
		return true;
	}
	//遍历栈输出
	void BianliStack()
	{
		int i = 0;
		for (i = top; i >= 0; i--)
		{
			cout << data[i] << " ";
		}
		cout << endl;
	}
	//清空栈
	void clear()
	{
		top = -1;
	}
};
#endif  // STACK_H
