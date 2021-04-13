#include <iostream>

using namespace std;

class Date
{
	friend ostream& operator<<(ostream &out, const Date &d);
public:
	bool IsLeap(int year)
	{
		return ((year % 4 && year % 100 != 0) || (year % 400 == 0));
	}
	//获取某年某月的天数
	int GetMonthDay(int year, int month)
	{
		static int days[13] = { 29, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

		if (month == 2 && IsLeap(year))
			month = 0;
		return days[month];
	}
	
	//全缺省的构造函数
	Date(int year = 1900, int month = 1, int day = 1) : _year(year), _month(month), _day(day)
	{
		
	}

	//拷贝构造函数
	//d2(d1)
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_year = d._year;
	}

	//赋值运算符重载
	//d2 = d3 -> d2.operator=(&d2, d3)
	Date& operator=(const Date& d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_year = d._year;
		}
		return *this;
	}

	//析构函数
	~Date()
	{

	}

	//日期+=天数
	Date& operator+=(int day)
	{
		int days = GetMonthDay(_year, _month);
		while (_day + day > days)
		{
			_month++;
			if (_month > 12)
			{
				_year++;
				_month = 1;
			}
			day -= days;
			days = GetMonthDay(_year, _month);
		}
		_day += day;
		return *this;
	}

	//日期+天数
	Date operator+(int day)
	{
		Date tmp(*this);
		tmp += day;
		return tmp;
	}

	//日期-天数
	Date operator-(int day)
	{
		Date tmp(*this);
		tmp -= day;
		return tmp;
	}

	//日期-=天数
	Date& operator-=(int day)
	{
		int days = GetMonthDay(_year, _month);
		while (_day <= day)
		{
			--_month;
			if (_month == 0)
			{
				--_year;
				_month = 12;
			}
			days = GetMonthDay(_year, _month);
			day -= days;
		}
		_day -= day;
		return *this;
	}

	//前置++
	Date& operator++()
	{
		++_day;
		int days = GetMonthDay(_year, _month);
		if (_day > days)
		{
			++_month;
			if (_month > 12)
			{
				_year++;
				_month = 1;
			}
			_day = 1;
		}
		return *this;
	}

	//后置++
	Date operator++(int)
	{
		Date tmp(*this);
		++*this;
		return tmp;
	}

	//后置--
	Date operator--(int)
	{
		Date tmp(*this);

	}

	//前置--
	Date operator--()
	{
		if (_day == 1)
		{
			if (_month == 1)
			{
				_year--;
				_month = 12;
			}
			else
			{
				_month--;
			}
			_day = GetMonthDay(_year - 1, _month);
		}
		else
		{
			_day--;
		}
		return *this;
	}

	// >运算符重载
	bool operator>(const Date& d)
	{
		if (_year > d._year
			|| _year == d._year && _month > d._month
			|| _year == d._year && _month == d._month && _day > d._day)
			return true;
		return false;
	}
	// ==运算符重载
	bool operator==(const Date& d)
	{
		return (_year == d._year
			&& _month == d._month
			&& _day == d._day);
	}
	// >=运算符重载
	inline bool operator >= (const Date& d)
	{
		return !(*this < d);
	}

	// <运算符重载
	bool operator < (const Date& d)
	{
		if (_year < d._year
			|| _year == d._year && _month < d._month
			|| _year == d._year && _month == d._month && _day < d._day)
			return true;
		return false;
	}
	// <=运算符重载
	bool operator <= (const Date& d)
	{
		return !(*this == d);
	}
	// !=运算符重载
	bool operator != (const Date& d);
	// 日期-日期 返回天数
	int operator-(const Date& d);

private:
	int _year;
	int _month;
	int _day;
};

ostream& operator<<(ostream &out, const Date &d)
{
	out << d._year << "-" << d._month << "-" << d._day << endl;
	return out;
}

int main()
{
	Date dt(2020, 7, 10); 
	Date dt1(2021, 4, 30);
	cout << "dt = " << dt << endl;

	if (dt == dt1)
	{
		cout << "ok" << endl;
	}

	//dt++;
	cout << "dt = " << dt << endl;
	dt -= 100;
	cout << "dt = " << dt << endl;

	return 0;
} 