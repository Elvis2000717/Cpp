#include <iostream>
#include <string >
#include <vector>
using namespace std;

//class Person
//{
//public:
//	Person(const char* name = "peter") : _name(name)
//	{
//		cout << "person()" << endl;
//	}
//
//	Person(const Person& p) : _name(p._name)
//	{
//		cout << "Person(const Person& p" << endl;
//	}
//
//	Person& operator=(const Person& p)
//	{
//		cout << "Person operator=(const Person& p)" << endl;
//		if (this != &p)
//		{
//			_name = p._name;
//		}
//		return *this;
//	}
//
//	~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//private:
//	string _name;
//};

//class Person
//{
//public:
//	string _name = "0";
//};
//
//class Student : virtual public Person
//{
//protected:
//	int _num;
//};
//
//class Teacher :virtual public Person
//{
//protected:
//	int _id;
//};
//
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse;
//};

//class Person
//{
//public:
//	string _name;
//};
//
//class Student :  public Person
//{
//protected:
//	int _num;
//};
//
//class Teacher : public Person
//{
//protected:
//	int _id;
//};
//
//class Assistant : public Student, public Teacher
//{
//protected:
//	string _majorCourse;
//};+		Person	{_name="0" }	Person


//int main()
//{
//	Assistant a;
//
//	return 0;
//}

//class Person
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << "全价" << endl;
//	}
//};
//
//class Student : public Person
//{
//public:
//	virtual void BuyTicket()
//	{
//		cout << "半价" << endl;
//	}
//};

//class A{};
//class B : public A {};
//
//class Person 
//{
//public:
//	virtual A* f()
//	{
//		return new A;
//	}
//};
//
//class Student : public Person
//{
//public:
//	virtual B* f()
//	{
//		return new B;
//	}
//};

//class Person
//{
//public:
//	virtual ~Person()
//	{
//		cout << "~Person()" << endl;
//	}
//};
//
//class Student : public Person
//{
//public:
//	virtual ~Student()
//	{
//		cout << "~Student()" << endl;
//	}
//};

//class Car
//{
//public:
//	virtual void Drive() final{}
//};
//
//class Benz : public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "benz" << endl;
//	}
//};

//class Car
//{
//public:
//	virtual void Drive() = 0;
//};
//
//class Benz : public Car
//{
//public:
//	virtual void Drive()
//	{
//		cout << "Bens" << endl;
//	}
//};

//class Base
//{
//public:
//	virtual void fun()
//	{
//		cout << "fun()" << endl;
//	}
//private:
//	int _b = 1;
//};
//
//int main()
//{
//	cout << sizeof(Base) << endl;
//	return 0;
//}

//class Base
//{
//public:
//	virtual void func1()
//	{
//		cout << "base::fun1" << endl;
//	}
//	virtual void func2()
//	{
//		cout << "base::fun2" << endl;
//	}
//private:
//	int a;
//};
//
//class Derive : public Base
//{
//public:
//	virtual void func1()
//	{
//		cout << "Derive::fun1" << endl;
//	}
//	virtual void func3()
//	{
//		cout << "Derive::fun3" << endl;
//	}
//	virtual void func4()
//	{
//		cout << "Derive::fun4" << endl;
//	}
//private:
//	int b;
//};
//
//typedef void(*pFun)();
//
//int main()
//{
//	Derive d;
//	//cout << &d << endl;//对象的地址
//	//cout << *(int*)&d << endl;//表的地址
//	//((pFun)(*(int*)(*(int*)&d) + 0))();
//
//
//
//	/*((pFun)(*((int*)(*(int*)&d) + 0)))();
//	((pFun)(*((int*)(*(int*)&d) + 1)))();
//	((pFun)(*((int*)(*(int*)&d) + 2)))();*/
//
//
//	((pFun)(*(((int*)(*(int*)(&d))) + 0)))();
//	((pFun)(*(((int*)(*(int*)(&d))) + 1)))();
//	((pFun)(*(((int*)(*(int*)(&d))) + 2)))();
//	return 0;
//}

class A
{
public:
	void fun()
	{
		cout << 1 << endl;
	}
	void fun(int n)
	{
		cout << n << endl;
	}
};

class B : public A
{
public:
	//void fun(string n)
	//{
	//	cout << "123" << endl;
	//}
};

int main()
{
	B b;
	/*string n = "acb";
	b.fun(n);*/
	b.fun(1);
	return 0;
}