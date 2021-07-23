#include <iostream>
#include <stdlib.h>

using namespace std;

//int main()
//{
//	int i = 1;
//	cout << &i << endl;
//	cout << (char*)&i << endl;
//	cout << (*(char*)&i) << endl;
//
//	return 0;
//}

//#include <stdio.h>
//int check_sys()
//{
//	int i = 1;
//	return (*(char *)&i);
//}
//int main()
//{
//	int ret = check_sys();
//	if (ret == 1)
//	{
//		printf("小端\n");
//	}
//	else
//	{
//		printf("大端\n");
//	}
//	return 0;
//}

#include <stdio.h>
//void test(int arr[])//ok?

//void test(int arr[10])//ok?

//void test(int *arr)//ok?
//void test2(int *arr[20])//ok?

//void test2(int **arr)//ok?
//{}

//int main()
//{
//	int *a = (int *)calloc(10, sizeof(int));
//	int *b = (int *)malloc(10);
//	int *c = (int *)realloc(b, 20);
//
//	free(a);
//	free(c);
//}

//void TestFunc(int a = 10)
//{
//	cout << "void TestFunc(int)" << endl;
//}
////void TestFunc(int a)
////{
////	cout << "void TestFunc(int)" << endl;
////}
//
//int main()
//{
//	TestFunc();
//	TestFunc(1);
//
//	return 0;
//}

//void TestConstRef()
//{
//	const int a = 10;
//	//int& ra = a; // 该语句编译时会出错，a为常量
//	const int& ra = a;
//	// int& b = 10; // 该语句编译时会出错，b为常量
//	const int& b = 10;
//	double d = 12.34;
//	//int& rd = d; // 该语句编译时会出错，类型不同
//	const int& rd = d;
//}//
//
//int main()
//{
//	/*int a = 10;
//	int& ar = a;*/
//
//	const int a = 10;
//	const int& ra = a;
//
//	const int b = 10;
//	//int& rb = b;
//
//	int c = 10;
//	const int& rc = c;
//
//}

//class Date
//{
//public:
//	Date* operator&()
//	{
//		return this;
//	}
//
//	const Date* operator&()const
//	{
//		return this;
//	}
//};

//class Date
//{
//public:
//	Date(int year, int month, int day) : _year(year), _month(month), _day(day)
//	{
//
//	}
//
//	void fun1()
//	{
//
//	}
//
//	static int fun()
//	{
//		fun();
//	}
//	
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date a(1,2,3);
//	a.fun1();
//
//	return 0;
//}

//class Date
//{
//	friend ostream& operator<<(ostream& _cout, const Date& d);
//	friend istream& operator>>(istream& _cin, Date& d);
//public:
//	Date() : _year(0)
//	{}
//	Date(int year) : _year(year)
//	{}
//
//private:
//	int _year;
//};
//
//ostream& operator<<(ostream& _cout,const Date& d)
//{
//	_cout << d._year;
//	return _cout;
//}
//
//istream& operator>>(istream& _cin, Date& d)
//{
//	_cin >> d._year;
//	return _cin;
//}
//
//int main()
//{
//	Date d;
//	cin >> d;
//	cout << d << endl;
//
//	return 0;
//}

//class Date
//{
//	friend ostream& operator<<(ostream& _cout, Date& d);
//	friend istream& operator>>(istream& _cin, Date& d);
//public:
//	Date(int year, int month, int day) : _year(year = 10), _month(month), _day(day)
//	{}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//ostream& operator<<(ostream& _cout, Date& d)
//{
//	_cout << d._year << "-" << d._month << "-" << d._day;
//	return _cout;
//}
//
//istream& operator>>(istream& _cin, Date& d)
//{
//	_cin >> d._year >> d._month >> d._day;
//	return _cin;
//}
//
//int main()
//{
//	Date d(2000, 7, 17);
//	cout << d << endl;
//	cin >> d;
//	cout << d << endl;
//
//	return 0;
//}

//class Date;
//class Time
//{
//	friend Date;
//public:
//	Time(int hour = 0) : _hour(hour)
//	{}
//private:
//	int _hour;
//};
//
//class Date
//{
//public:
//	Date(int year = 2000) : _year(year)
//	{}
//	void set()
//	{
//		cout << _year << "-" << t._hour << endl;
//	}
//private:
//	int _year;
//	Time t;
//};
//
//int main()
//{
//	Date d;
//	d.set();
//	return 0;
//}