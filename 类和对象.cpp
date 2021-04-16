#include <iostream>
using namespace std;

class Date
{
	friend ostream& operator<<(ostream& _cout, const Date& d);
	friend istream& operator>>(istream& _cin, Date& d);
public:
	Date(int year, int month, int day)
		: _year(year)
		, _month(month)
		, _day(day)
	{}

private:
	int _year;
	int _month;
	int _day;
};

ostream& operator<<(ostream& _cout, const Date& d)
{
	_cout << d._year << "-" << d._month << "-" << d._day;
	return _cout;
}

istream& operator>>(istream& _cin, Date& d)
{
	_cin >> d._year;
	_cin >> d._month;
	_cin >> d._day;

	return _cin;
}

int main()
{
	Date d(2017, 12, 24);
	d << cout;

	return 0;
}

//class B
//{
//public:
//	B(int b = 0)
//		:_b(b)
//	{}
//	int _b
//};

//class Date
//{
//public:
//	Date(int year)
//		:_year(year)
//	{}
//
//	//有了就编不过了
//	/*explicit Date(int year)
//		:_year(year)
//	{}*/
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//void TestDate()
//{
//	Date d1(2018);
//	d1 = 2019;
//}

//class Date
//{
//public:
//	Date(int year, int month, int day)
//		: _year(year)
//		, _month(month)
//		, _day(day)
//	{}
//	/*Date(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}*/
//private:
//	int _year;
//	int _month;
//	int _day;
//};

//class Test
//{
//public:
//	Test(int data = 0) : m_data(data)
//	{}
//
//	Test(const Test &t)
//	{
//		m_data = t.m_data;
//	}
//
//	Test& operator=(const Test &t)
//	{
//		if (this != &t)
//		{
//			m_data = t.m_data;
//		}
//		return *this;
//	}
//
//	Test& operator++()
//	{
//		m_data++;
//		return *this;
//	}
//	Test operator++(int)
//	{
//		Test tmp(*this);
//		m_data++;
//		return tmp;
//	}
//
//private:
//	int m_data;
//};
//
//class A
//{
//public:
//	A(int a)
//		:_a(a)
//	{}
//private:
//	int _a;
//};
//
//class B
//{
//public:
//	B(int a, int ref)
//		:_aobj(a)
//		, _ref(ref)
//		, _n(10)
//	{}
//private:
//	A _aobj;
//	int& _ref;
//	const int _n;
//};

//int main()
//{
//	//TestDate();
//
//	return 0;
//}