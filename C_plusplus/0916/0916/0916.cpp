#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;

#if 0
//��ʼ���б����ã���ʼ�����еĳ�Ա����������ÿ����Ա����ֻ���ڳ�ʼ���б��г���һ��
class Date
{
public:
	Date(int year, int month, int day)
		: _year(year)
		, _month(month)
		, _day()//��ʼ���б�
		, a(10)
		, b(_year)//����ʹ�ñ�����ʼ������
		//ÿһ����������Ҫ�ڳ�ʼ���б��г��֣����δ�ڳ�ʼ���б��г�ʼ��
		//�����������Ĭ�Ϲ��캯����ʼ�����ֵ
	{
		// ���캯�����У�����ֵ
		_year = year;
		_month = month;
		_day = day;
	}
private:
	int _year;
	int _month;
	int _day;

	const int a;
	int & b;
};
int main()
{
	Date d1(2019, 5, 15);
	const int a = 10;
	return 0;
}
#endif

#if 0
class Time
{
public:
	Time(int hour=0 , int minute =0, int second=0 )
		//ȫȱʡ�����ĳ�ʼ���б�
		: _hour(hour)
		, _minute(minute)
		, _second(second)
	{}
private:
	int _hour;
	int _minute;
	int _second;
};
class Date
{
public:
	Date(int year, int month,int day)
		//��������������͵ı���������Ҫ�����д�����Ĭ�ϵĹ��캯��
		//���û��Ĭ�Ϲ��캯��������Ҫ�ڴ˳�ʼ���б��г�ʼ��
		: _year(year)
		, _month(month)
		, _day(day)
		//, _t(10,43,34)
	{
		cout << this << endl;
	}
private:
	int _year;
	int _month;
	int _day;
	Time _t;
};

int main()
{
	Date d1(2019, 9, 16);
	return 0;
}
#endif


#if 0
//���飺������Ҫʹ�ó�Ա��ʼ����Ա
//		��ʼ���б��г�Ա���ִ���������������������Ĵ��򱣳�һ��
class Date
{
public:
	Date(int year, int day)
		: _year(year)
		//����������˳��
		/*, _month(day)
		, _day(_day)*/
		//������������˳��
		, _day(day)
		, _month(_day)
		//��Ϊ��ʼ���б��ڳ�ʼ��ʱ���Ǹ��ݱ�������˳���ʼ��
		//��������������_dayδ����ʼ��ʱ����������ʼ��_month
	{
		cout << this << endl;
	}

	//�������캯��ʹ�ó�ʼ���б�(���ʣ����캯������)
	Date(const Date& d)
		: _year(d._year)
		, _month(d._month)
		, _day(d._day)
	{}

private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	Date d1(2019, 15);
	return 0;
}

#endif

#if 0
//�������͵Ĺ��캯����������ת�������ã�����ù��캯��������������
//explicit:���ε��ι��캯������˼�ǽ�ֹ���ι��캯������ת��������
class Date
{
public:
	explicit Date(int year)
		:_year(year)
	{
		cout << this << endl;
	}

	Date& operator=(const Date& d)
	{
		cout << this << "=" << &d << endl;
		if (this != &d)
		{
			_year = d._year;
			_month = (d._month);
			_day = (d._day);
		}
		return *this;
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1(2018);
	//d1 = 2019;//�������ͣ���������еĹ��캯����2019����һ���������󣬴Ӷ���ֵ
	return 0;
}
#endif


#if 0

//Date �ܹ������˶��ٸ���Ч����
//���캯��  �������캯��  ��������
//������Ҫ����� ����ĸ���----����---int

int _count = 0;
class Date
{
public:
	Date(int year, int month, int day)
		: _year(year)
		, _month(month)
		, _day(day)
	{
		_count++;
	}

	Date(Date& d)
		: _year(d._year)
		, _month(d._month)
		, _day(d._day)
	{
		_count++;
	}


	~Date()
	{
		_count--;
	}
private:
	int _year;
	int _month;
	int _day;
};

void TestDate()
{
	Date d3(2019, 9, 16);
	Date d4(d3);
	Date d5(2019, 9, 16);
	cout << _count << endl;
}

int main()
{
	//ͳ�ƴ������ٸ����󣬿��Ը��ݵ��ö��ٴι��캯���Ϳ������캯���Լ������������ж�

	Date d1(2019, 9, 16);
	Date d2(d1);
	cout << _count << endl;

	_count = 0;
	TestDate();
	//ʹ��ȫ�ֱ���������������
	//ȫ�ֱ������Ա��޸ģ�����ȫ
	_count = 100;
	cout << _count << endl;
	return 0;
}

#endif


#if 0
class Date
{
public:
	Date(int year, int month, int day)
		: _year(year)
		, _month(month)
		, _day(day)
	{
		_count++;
	}

	Date(Date& d)
		: _year(d._year)
		, _month(d._month)
		, _day(d._day)
	{
		_count++;
	}


	~Date()
	{
		_count--;
	}
private:
	int _year;
	int _month;
	int _day;

public:
	static int _count;
};
//����̬���εĳ�Ա����ֻ����������г�ʼ��
//�������̬���εĳ�Ա����Ȩ��Ϊ˽�У��������޷����ʣ���ʹ�ýӿڷ���

int Date::_count = 0;
void TestDate()
{
	Date d3(2019, 9, 16);
	Date d4(d3);
	Date d5(2019, 9, 16);
	cout << Date::_count << endl;
}

int main()
{
	Date d1(2019, 9, 16);
	Date d2(d1);

	//��̬��Ա�����������������ĳ�Ա����
	//�ھ�̬�洢����
	//������ĳ������Ķ���
	cout << &d1._count << "  " << &d2._count << endl;
	cout << sizeof(Date) << endl;

	cout << Date::_count << endl;
	TestDate();
	return 0;
}
#endif

#if 0
class Date
{
public:
	Date(int year, int month, int day)
		: _year(year)
		, _month(month)
		, _day(day)
	{
		_count++;
	}

	Date(Date& d)
		: _year(d._year)
		, _month(d._month)
		, _day(d._day)
	{
		_count++;
	}

	~Date()
	{
		_count--;
	}

	void TestFunc()
	{
		//��ͨ��Ա�����ȿ��Է�����ͨ��ԱҲ���Է��ʾ�̬��Ա
		_day++;
		cout << _count << endl;
		GetCount();
	}

	static int GetCount()
	{
		//��̬��Ա����û��thisָ�룬�����޷����ʷǾ�̬��Ա
		/*cout << this << endl;
		TestFunc();
		_day++;*/
		return _count;
	}

private:
	int _year;
	int _month;
	int _day;
	static int _count;
};

int Date::_count = 0;

void TestDate()
{
	Date d3(2019, 9, 16);
	Date d4(d3);
	Date d5(2019, 9, 16);
	cout << Date::GetCount() << endl;
}

int main()
{
	cout << Date::GetCount() << endl;
	Date d1(2019, 9, 16);
	Date d2(d1);

	cout << Date::GetCount() << endl;
	TestDate();
	cout << Date::GetCount() << endl;
	return 0;
}
#endif

#if 0
class Date
{
public:
	Date(int year,int month,int day)
		: _year(year)
		, _month(month)
		, _day(day)
	{
		_count++;
	}

	Date(Date& d)
		: _year(d._year)
		, _month(d._month)
		, _day(d._day)
	{
		_count++;
	}

	~Date()
	{
		_count--;
	}

	static int GetCount()
	{
		return _count;
	}

private:
	int _year;
	int _month;
	int _day;
	static int _count;
};

int Date::_count = 0;

int main()
{
	int sum = 0;
	Date d1(2019, 9, 16);
	sum += Date::GetCount();

	Date d2(d1);
	sum += Date::GetCount();

	Date d3(d1);
	sum += Date::GetCount();

	return 0;
}
#endif


#if 0
//��Ԫ���������Ὣ�����������У����Ǹ���һ�ֿ��Ե������г�Ա������Ȩ��
class Time
{
	friend class Date;
public:
	Time(int hour = 0, int minute = 0, int second = 0)
		: _hour(hour)
		, _minute(minute)
		, _second(second)
	{}

private:
	int _hour;
	int _minute;
	int _second;
	
	friend void Print();
};


class Date
{
private:
	friend ostream& operator <<(ostream& _cout, const Date& d);
public:
	Date(int year, int month, int day)
		: _year(year)
		, _month(month)
		, _day(day)
	{}

	void PrintDate()const
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
	// ��<<�����������س���ĳ�Ա���������һ������Ϊthis
	// ��˵��÷�ʽ�볣��Ĵ�ӡ��ʽ����
	/*void operator<<(ostream& _cout)
	{
		_cout << _year << "-" << _month << "-" << _day;
	}*/

	void TestFunc()
	{
		_t._hour = 1;
		_t._minute = 1;
		_t._second = 1;
	}
private:
	int _year;
	int _month;
	int _day;
	Time _t;
	friend void Print();
};

//˵�����������س�Ϊȫ�ֺ���
//		��һ������������ostream&���ڶ�������ΪҪ���������(�Զ������͵Ķ���const)
//		����Ҫ�з���ֵ-----�������
//		������Ҫ�ڸú�������һЩ��ʽ����----���绻��
//		�����������������ó������Ԫ����

ostream& operator <<(ostream& _cout, const Date& d)
{
	_cout << d._year << "-" << d._month << "-" << d._day;
	return _cout;
}

void Print()
{
	Date d(2019, 9, 18);
	cout << d._year<< endl;


	Time t;
	cout << t._hour << endl;


}

int main()
{
	Date d(2019, 9, 18);
	//void operator<<(const Date this*,ostream &count)
	//��������<<,������Ϊ���ں�������������б��һ��������thisָ��
	//�������غ�<<ָ���෴
	/*d.operator<<(cout);
	d << cout;*/

	cout << d << endl;
	return 0;
}

#endif

#if 0
class A
{
public:
	A(int a)
		:_a(a)
	{}

	class B
	{
	public:
		B(int b)
			: _b(b)
		{}

		void TestFunc()
		{
			A a(1);
			a._a = 10;
			A::_c = 10;
		}

	private:
		int _b;
	};

private:
	int _a;
	static int _c;
};

int A::_c = 0;


int main()
{
	A::B b(10);
	//ע�⣺�ڲ�����һ���������࣬û�а������ⲿ����
	//ֻ���ڴ�����Ӧ�Ķ���ʱ����Ҫ�����������޶���
	cout << sizeof(A) << endl;
	return 0;
}
#endif


