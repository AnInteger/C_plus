#include<iostream>
using namespace std;



#if 0
//���캯��ֻ�ڶ�������������г���һ��
//��Ϊ����ֻ��һ�γ�ʼ��
class Date
{
public:
	Date()
	{
		_year = 1900;
		_month = 1;
		_day = 1;
	}
	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
		cout << "Date(int,int,int):" << this << endl;
	}

	void SetDate(int year, int month, int day)//��ʼ����ֵ����
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void PrintDate()//�������
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};


int main()
{
	
	int a;
	a = 10;

	int b = 10;
	int c = (10);


	Date d3;
	d3.PrintDate();
	//�û������ж����޲εĹ��캯������Ĭ�ϸ�ֵ
	//���������û�г�ʼ��ʱ����ʱ��������û��Զ�����޲ι��캯��

	Date d2(2019, 9, 14);
	d2.PrintDate();
	//�û������ж����˹��캯���������в��ٳ���Ĭ�ϵ��޲ι��캯��
	//�����ڶ������ʱ�������Զ��幹�캯��

	// �������û����ʽ(�û��Ƿ�ֱ�Ӷ���)�κι��캯����
	// ��������������һ��Ĭ�ϵĹ��캯��---�޲ι��캯��

	//Date d1;
	//�ȶ�����ʼ��������Ĭ���޲ι��캯��
	//�����ж������в����Ĺ��캯���������ֳ�ʼ�����������ã�
	//��Ϊ���޲����вεĹ��캯��������ͻ

	/*d1.SetDate(2019, 9, 14);
	d1.PrintDate();*/


	return 0;
}

#endif

#if 0
class Time
{
public:
	//ȫȱʡ���캯��
	Time(int hour = 0, int minute = 0, int second = 0)
	{
		cout << "Time(int,int,int):" << endl;
		_hour = hour;
		_minute = minute;
		_second = second;
	}
private:
	int _hour;
	int _minute;
	int _second;
};

class Date
{
public:
	void SetData(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void PrintDate()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;
	Time _t;
};

int main()
{
	Date d1;
	//��Date�����������͵ĳ�Ա����_t,��Ȼ�ڴ�������d1ʱ��
	//Date����û���û��Զ���Ĺ��캯������Date������ϵͳ���ɵ�Ĭ�Ϲ��캯��
	//����_year,_month,_day���������ʼ�����������ͳ�Ա����_t,��Time������
	//�û��Զ���Ĺ��캯��������_t�ڵ��ù��캯��ʱ�������û��Զ���Ĺ��캯��

	return 0;
}
#endif


#if  0
#include<assert.h>
#include<malloc.h>


typedef int DataType;

class SeqList
{
public:
	SeqList(size_t capacity = 10)
	{
		cout << "SeqLIist(size_t)" << endl;

		_array = (DataType*)malloc(sizeof(DataType)*capacity);
		if (nullptr == _array)
		{
			assert(0);
			return;
		}
		capacity = 0;
		_size = 0;
	}
	/*~SeqList()
	{
		cout << "~SeqList()" << endl;
	}*/
	~SeqList()
	{
		cout << "~SeqList()" << endl;
		if (_array)
		{
			free(_array);
			_array = nullptr;
			_capacity = 0;
			_size = 0;
		}
	}
private:
	DataType* _array;
	size_t _size;
	size_t _capacity;
};

void TestSeqList()
{
	SeqList s;
}

int main()
{
	TestSeqList();
	//����������ʱ������������������һЩ�����Դ������
	_CrtDumpMemoryLeaks();//����Ƿ����ڴ�й©
	//����һ�����öѣ���������Դ��Ҫ�ֶ��ͷ�ʱ��Ĭ�����������޷�ʵ��
	//��ʱ��Ҫ�û��Զ�����������
	return 0;
}
#endif

//���ڱ��������ɵ�Ĭ�ϵ���������


#if 0
class String
{
public:
	String(char* str = "")
	{
		cout << "String(char*)" << endl;
		if (nullptr == str)
		{
			str = "";
		}
		_str = (char*)malloc(strlen(str) + 1);
		strcpy(_str, str);
	}

	~String()
	{
		cout << "~String():" << endl;
		if (_str)
		{
			free(_str);
		}
	}
private:
	char* _str;
};

class Person
{
private:
	String _name;
	String _gender;
	int _age;
};

void TestPerson()
{
	Person p;
}

int main()
{
	TestPerson();
	return 0;
}
#endif

#if 0
//�������캯�����û�û����ʾ�ṩ��������������һ��Ĭ�ϵĿ������캯��
class String
{
public:
	String(const char* str = "")
	{
		if (nullptr == str)
		{
			str = "";
		}
		_str = (char*)malloc(strlen(str) + 1);
		strcpy(_str, str);
	}
	~String()
	{
		if (_str)
		{
			free(_str);
		}
	}
	String(const String& d)
	{
		_str = d._str;
		_str = (char*)malloc(strlen(_str) + 1);
		strcpy(_str, d._str);
		*_str = *(d._str);
	}
private:
	char* _str;
};

class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
		cout << "Date(int,int,int):" << this << endl;
	}

	void SetDate(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void PrintDate()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

void TestDate()
{
	Date d1(2019, 9, 14);
	Date d2(d1);
}

void TestString()
{
	String s1("hello");
	String s2(s1);
}

int main()
{
	TestString();
	//��ʹ��Ĭ�Ͽ�������ʱ����ǳ����
	//���������ͬһ���ڴ�ռ䣬������ʱ��һ�ݿռ䱻�ͷŶ�Σ������³������
	//������й�����Դ������Ŀ������캯���������û���ʽ�ṩ

	TestDate();
	//δʹ�öѵ���Դ����ǣ��
	return 0;
}
#endif


#if 0
//�û��Զ��忽������
class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;;
		cout << "Date(int,int,int):" << this << endl;
	}

	Date(const Date& d)//�Զ��忽�����캯��
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	void SetDate(int year, int month, int day)
	{
			_year = year;
			_month = month;
			_day = day;
		}

	void PrintDate()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1(2019, 9, 14);
	Date d2(d1);
	return 0;
}
#endif


class Date
{
public:
	Date(int year = 1900, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	void SetDate(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void PrintDate()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
	bool operator>(const Date& d)
	{
		if (_year > d._year || _year == d._year&&_month > d._month || _year == d._year&&_month == d._month&&_day > d._day)
		{
			return true;
		}
		return false;
	}


private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	int a = 10;
	int b = 20;
	if (a > b)
		cout << "a" << endl;
	else
		cout << "b" << endl;

	Date d1(2019, 9, 14);
	Date d2(2019, 9, 15);
	Date d3(2020, 9, 14);

	if (d1 > d2)
	{
		d1.PrintDate();
	}
	else
	{
		d2.PrintDate();
	}
	return 0;
}