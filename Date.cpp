#include <iostream>
#include <assert.h>

using namespace std;

class Date
{
public:
	//1.无参构造函数
	Date()
	{}
	//2.带参数构造函数
	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void SetDate(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void Display()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

typedef int DataType;
class SeqList
{
public:
	SeqList(int capacity = 10)
	{
		_pData = (DataType*)malloc(capacity * sizeof(DataType));
		assert(_pData);

		_size = 0;
		_capacity = capacity;
	}
	~SeqList()
	{
		if (_pData)
		{
			free(_pData);
			_pData = NULL;
			_capacity = 0;
			_size = 0;
		}
	}
private:
	int* _pData;
	size_t _size;
	size_t _capacity;
};

class String
{
public:
	String(const char* str = "jack")
	{
		_str = (char*)malloc(strlen(str) + 1);
		strcpy(_str, str);
	}

	~String()
	{
		cout << "~String()" << endl;
		free(_str);
	}
private:
	char* _str;
};

class Person
{
private:
	String _name;
	int _age;
};

int main()
{
	Date d1, d2;
	d1.SetDate(2021, 4, 6);
	d1.Display();

	d2.SetDate(2021, 4, 6);
	d2.Display();

	Date d3;
	Date d4();

	Person p;

	return 0;
}