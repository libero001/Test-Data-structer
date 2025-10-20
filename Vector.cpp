# include <iostream>
# include <vector>
using namespace std;
//输出vector中的元素
void PrintVectr(const vector<int> &vec)
{
	cout << "vector元素：";
	for (int num : vec)
	{
		cout << num << ' ';
	}
	cout << endl;
}
int main()
{
	vector<int> vec;
	//1.动态添加元素（自动扩容）
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	PrintVectr(vec);
	//2.用at来判断是否越界
	try
	{
		vec.at(5) = 10;
	}
	catch (const out_of_range& e)
	{
		cout << "出现错误:" << e.what() << endl;
	}
	//3.插入\删除元素
	vec.insert(vec.begin() + 1, 91);//begin指向vector中第一个元素
	PrintVectr(vec);
	vec.erase(vec.end() - 1);//end指向vector中最后一个元素的下一位
	PrintVectr(vec);
	//vector自动释放内存 ,new只能自动释放栈上的内存 不能自动释放堆上的内存，只能通过delete释放
	return 0;
}