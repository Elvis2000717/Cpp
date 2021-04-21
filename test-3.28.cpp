#include <iostream>
#include <string>
using namespace std;

//void f(int) {
//	cout << "f(int)" << endl;
//}
//void f(int*) {
//	cout << "f(int*)" << endl;
//}
//int main()
//{
//	f(0);
//	f(NULL);
//	f((int*)NULL);
//	return 0;
//}

//int main()
//{
//	int array[] = { 1, 2, 3, 4, 5 };
//	for (auto& e : array)
//		e *= 2;
//
//	for (auto e : array)
//		cout << e << " ";
//
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	cout << typeid(a).name() << endl;
//	auto b = a;
//	cout << typeid(b).name() << endl;
//
//	return 0;
//}

//int& fun(int a, int b)
//{
//	int value = a + b;
//	return value;
//}
//
//void main()
//{
//	int &result = fun(10, 20);
//	cout << "result" << result << endl;
//	fun(100, 200);
//	cout << "result" << result << endl;
//}
//int& Count()
//{
//	static int n = 0;
//	n++;
//	// ...
//	return n;
//}

//void Swap(int& left, int& right) 
//{
//	int temp = left;
//	left = right;
//	right = temp;
//}
//
//int main()
//{
//	int a = 10;
//	int c = 20;
//	int &b = a;
//	int *p = &a;
//	p = &c;
//
//	return 0;
//}

//void TestFunc(int a = 10)
//{
//	cout << "void TestFunc(int)" << endl;
//}
//void TestFunc(int a)
//{
//	cout << "void TestFunc(int)" << endl;
//}

/*
//不能重载

extern short Add(short left, short right)
{
	return left + right;
}

int Add(short left, short right)
{
	return left + right;
}

int main()
{
	Add(1, 2);
	return 0;
}
*/

/*
int fun(int a = 10, int b = 20)
{
	return a + b;
}

double fun(double a, double b)
{
	return a + b;
}

double fun(int a, double b)
{
	return a + b;
}

int main()
{
	cout << fun() << endl;
	cout << fun(1,2) << endl;

	return 0;
}
*/

/*
int main()
{
	int a;
	cin >> a;
	cout << a << endl;
	cout << "Hello World" << endl;
	return 0;
}
*/

/*
//引用
void swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

int main()
{
	int x = 10;
	int y = 20;
	swap(x, y);
	cout << x << " " << y << endl;

	//引用不是新定义一个变量，只是一个别名
	//引用不能跨类型
	//引用需要初始化，不能出现空引用
	int a = 10;
	int &b = a;
	//对于a来说可以修改值，b不行

	//指针的引用
	int *p = &a;
	int *&q = p;

	//数组的引用
	int ar[5] = { 1, 2, 3, 4, 5 };
	int(&br)[5] = ar;

	//必须是常引用
	const int c = 10;
	const int &d = a;
	//做参数使用
	//做返回值使用


	return 0;
}
*/


//2021.3.30
//class A
//{
//public:
//	void printfA()
//	{
//		printf("%d\n", a);
//	}
//	void show()
//	{
//		printf("abc");
//	}
//private:
//	int a;
//};
//
//int main()
//{
//	A b;
//	A *a = &b;
//	A *p = NULL;
//	b.printfA();
//	b.show();
//	p->printfA();
//	p->show();
//	a->printfA();
//
//	return 0;
//}

//class A
//{
//public:
//	//构造函数  实例化对象会自动调用
//	A()
//	{
//		a = 0;
//	}
//	A(int data)
//	{
//		a = data;
//	}
//	//析构函数
//	~A()
//	{
//
//	}
//
//	A(A &t)
//	{
//		a = t.a;
//	}
//
//private:
//	int a;
//};

//class P
//{
//public:
//	void show()
//	{
//		cout << name << endl;
//	}
//private:
//	char* name;
//};

//class p
//{
//public:
//	void show();
//private:
//	char* name;
//};
//
//#include "person.h"
//
//void p::show()
//{
//	cout << name << endl;
//}

//class Test
//{
//public:
//	void setName(const char* name)
//	{
//		strcpy(this->name,name);
//		//this->name = name;
//	}
//	void setAge(short age)
//	{
//		this->age = age;
//	}
//	char* showName()
//	{
//		return this->name;
//	}
//	short showAge()
//	{
//		return age;
//	}
////protected:
//private:
//	char name[20];
//	short age;
//};
//
//int main()
//{
//	Test t;
//	t.setAge(20);
//	t.setName("lixin");
//	char* arr;
//	arr = t.showName();
//	cout << t.showAge() << endl;
//	cout << arr << endl;
//	return 0;
//}

//4.11

//class Test
//{
//public:
//	operator int()
//	{
//		return m_data;
//	}
//	operator float()
//	{
//		return (float)m_data;
//	}
////protected:
//private:
//	int m_data;
//};
//
//int main()
//{
//	
//	return 0;
//}

//要前项声明
class List;

class ListNode
{
	friend class List;
public:
	ListNode(int d = 0) ,data(d), next(nullptr)
	{}
	~ListNode
	{}
private:
	int data;
	ListNode *next;

};

class List
{
public:
	List() :head(nullptr)
	{}
public:
	void push_back(int val)
	{

	}
private:
	ListNode *head;
	ListNode *tail;
};
