#include <iostream>
#include<string>
#include "IsMatch.h";
#include "Stack.h";
#include "IsPalindrome.h";
#include "Trans.h";
using namespace std;
int main()
{
	//1.1.	基础操作：

	//(1)	初始化顺序栈，从键盘输入5个字符压入栈中
	SqStack<int> s1;
	s1.push(1);
	s1.push(2);
	s1.push(3);
	s1.push(4);
	s1.push(5);
	//(2)	判断栈是否为空，显示判断结果
	cout << "此时栈";
	s1.empty() ? printf("为空\n") : printf("不为空\n");
	//(3)	获取栈顶元素，并显示出元素的值。
	int e = 0,e2,e3;
	s1.gettop(e);
	cout << "栈顶元素值：" << e << endl;
	//(4)	遍历栈，显示中所有元素的信息。（遍历栈算法需要同学自行补充）
	cout << "遍历栈元素:" << endl;
	s1.BianliStack();
	//(5)	出栈两个字符，显示出栈的两个元素，判断栈是否为空。
	s1.pop(e);
	s1.pop(e2);
	cout << "出栈元素：" << e << ' ' << e2 << ' ';
	cout << "此时栈";
	s1.empty() ? printf("为空\n") : printf("不为空\n");
	//(6)	再出栈三个字符，显示出栈的三个元素，判断栈是否为空。
	s1.pop(e);
	s1.pop(e2);
	s1.pop(e3);
	cout << "出栈元素：" << e << ' ' << e2 << ' '<<e3<<' ';
	cout << "此时栈";
	s1.empty() ? printf("为空\n") : printf("不为空\n");
	//(7)	继续入栈三个字符。清空栈后，显示清空结果。
	s1.push(1);
	s1.push(2);
	s1.push(3);
	cout << "此时栈";
	s1.empty() ? printf("为空\n") : printf("不为空\n");
	cout << "清空栈" << endl;
	s1.clear();
	cout << "此时栈";
	s1.empty() ? printf("为空\n") : printf("不为空\n");
	//2. 括号配对。设计一个算法，利用顺序栈判断用户输入的表达式中的括号是否配对（假设表达式中可能含有圆括号、中括号和大括号），并用相关数据进行测试。
	string str1 = "{()}";
	string str2 = "[(])";
	cout << str1 << ' ';
	Ismatch(str1) ? printf("括号配对\n") : printf("括号不配对\n");
	cout << str2 << ' ';
	Ismatch(str2) ? printf("括号配对\n") : printf("括号不配对\n");
	//3. 回文判断。设计一个算法，利用顺序栈判断用户输入的字符串表达式是否为回文，并用相关数据进行测试。
	string Str1 = "12344321";
	string Str2 = "123431";
	cout << Str1 << " ";
	isPoalindrome(Str1) ? printf("是回文序列\n") : printf("不是回文序列\n");
	cout << Str2 << " ";
	isPoalindrome(Str2) ? printf("是回文序列\n") : printf("不是回文序列\n");

	//4. 数制装换。设计一个算法，利用顺序栈将一个十进制整数d转换为r(2=<r<=16)进制的数，要求r进制数采用字符串string表示。
	cout << "15的二进制" << trans(15, 2) << endl;;
	return 0;
}