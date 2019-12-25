#include<iostream>
using namespace std;

//C/C++

//bool Test1()
//{
//	//�ɹ�����true ��ʧ�ܷ���false
//	return false;
//}
//
//void Test2()
//{
//	// .....
//	//����˴������Ƿ����
//	throw 1;
//}
//
//// �������ԭ��ָ̬��(T*)������Դ�����������Դй©�ķ��վͱȽϴ�
//
//void TestFunc()
//{
//	int *p = new int[10];
//	FILE *pf = fopen("2223.txt", "rb");
//	if (nullptr == pf)
//	{
//		delete[] p;
//		return;
//	}
//
//	// ...
//	if (!Test1())
//	{
//		delete[] p;
//		fclose(pf);
//		return;
//	}
//
//	try
//	{
//		Test2();
//	}
//	catch (...)
//	{
//		delete[] p;
//		fclose(pf);
//		throw;
//	}
//	delete[] p;
//	fclose(pf);
//}


//�ܷ��ó������Ҹ�֪������������ʱ�Զ��ͷ���Դ


// RAII---��Դ��ȡ����ʼ��
// �ڹ��캯���з���Դ
// �������������ͷ���Դ


#if 0
//����ָ��ļ�ģ��ʵ��
template<class T>
class SmartPtr
{
public:
	//RAII: ����--->�û����ÿ���ʲôʱ����ͷ���Դ
	//				���ͷ���Դ�Ĺ�������������
	SmartPtr(T* ptr = nullptr)
	:_ptr(ptr)
	{
		cout << "SmartPtr(T*)" << endl;
	}

	~SmartPtr()
	{
		cout << "~SmartPtr(T*)" << endl;
		if (_ptr)
		{
			delete _ptr;
			_ptr = nullptr;
		}
	}

	//�ø���Ķ���߱�ָ�����Ƶ���Ϊ
	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{
		return _ptr;
	}

private:
	T* _ptr;
};

struct A
{
	int a;
	int b;
	int c;
};

void TestSmartPtr()
{
	SmartPtr<int> spl(new int);
	*spl = 10;

	SmartPtr<A> sp2(new A);
	sp2->a = 1;
	sp2->b = 2;
	sp2->c = 3;
}

int main()
{
	TestSmartPtr();
	return 0;
}

#endif

//ȱ�ݣ�ǳ����
//String--->������ǳ����������--->���
//���ܲ�������ķ�ʽ���н��


#if 0
template<class T>
class SmartPtr
{
public:
	SmartPtr(T* ptr = nullptr)
		:_ptr(ptr)
	{
		cout << "SmartPtr()" << endl;
	}

	~SmartPtr()
	{
		cout << "~SmartPtr()" << endl;
		if (_ptr)
		{
			delete _ptr;
			_ptr = nullptr;
		}
	}

	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{
		return _ptr;
	}

private:
	T* _ptr;
};


void TestSmartPtr()
{
	int a = 10;
	int *pa = &a;
	int *pb(pa);

	SmartPtr<int> sp1(new int);
	SmartPtr<int> sp2(sp1);//ʹ��sp1����sp2
}

//����ָ��ָ��ͬһƬ�ռ䣬�����ͷŵ��³������
int main()
{
	TestSmartPtr();
	return 0;
}
#endif

//���в�ͬ���͵�����ָ�룺
//RAII:��Դ�����Զ��ͷ�
//��������ָ�����Ƶ���Ϊ��operator*()/operator->()
//ǳ�����Ľ����ʽ


//C++98--
//auto_ptr
//���ǳ������ʽ����Դת��--->��ǰ����
//ȱ�ݣ�p1��p2������ͬʱ����ͬһ����Դ
#if 0
namespace my_ptr
{
	template<class T>
	class auto_ptr
	{
	public:
		//RAII
		auto_ptr(T* ptr = nullptr)
			:_ptr(ptr)
		{}
		
		~auto_ptr()
		{
			if (_ptr)
			{
				delete _ptr;
				_ptr = nullptr;
			}
		}
	//����ָ�����Ƶ���Ϊ
		T&operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}
		//���ǳ��������
		auto_ptr(auto_ptr<T>& ap)
			:_ptr(ap._ptr)
		{
			ap._ptr = nullptr;
		}

		//ap3=ap2
		auto_ptr<T>& operator=(auto_ptr<T>& ap)
		{
			if (this != &ap)
			{
				//�����ǰ���������Դ�����ͷ���Դ
				if (_ptr)
				{
					delete _ptr;
				}
				_ptr = ap._ptr;//��Դת��
				ap._ptr = nullptr;//ap����Դ�Ͽ���ϵ
			}
			return *this;
		}

	private:
		T* _ptr;
	};
}
#endif

//����bool_owner:����ͷ� �������ͷŵ�Ȩ��
//�Ľ�֮���auto_ptr��ʵ��ԭ��
//RAII +  operator*()/operator->() + ���ǳ��������Դ����Ȩ��(����Դ�ͷŵ�Ȩ��)ת��
#if 0
namespace my_ptr
{
	template<class T>
	class auto_ptr
	{
	public:
		//RAII
		auto_ptr(T* ptr = nullptr)
			:_ptr(ptr)
			,_owner(false)
		{
			if (_ptr)
			{
				_owner = true;
			}
		}

		~auto_ptr()
		{
			if (_ptr&&_owner)
			{
				delete _ptr;
				_ptr = nullptr;
			}
		}

		T& operator*()
		{
			return *_ptr;
		}

		T*operator->()
		{
			return _ptr;
		}

		auto_ptr(const auto_ptr<T>& ap)
			:_ptr(ap._ptr)
			,_owner(ap._owner)
		{
			ap._owner = false;
		}

		auto_ptr<T>& operator=(const auto_ptr<T>& ap)
		{
			if (this != &ap)
			{
				if (_ptr&&_owner)
				{
					delete _ptr;
				}
				_ptr = ap._ptr;
				_owner = ap._owner;
				ap._owner = false;
			}
			return *this;
		}

	private:
		T *_ptr;
		mutable bool _owner;
	};
}

void TestAutoPtr1()
{
	int a = 10;
	int *pa = &a;
	int *pb = pa;

	*pa = 100;
	*pb = 200;

	my_ptr::auto_ptr<int> ap1(new int);
	my_ptr::auto_ptr<int> ap2(ap1);

	//��Դת�Ƶ�ȱ�ݣ�ap1�Ѻ���Դ�Ͽ����ӣ������ٲ�����Դ
	*ap2 = 200;
	*ap1 = 100;

	my_ptr::auto_ptr<int> ap3(new int);
	ap3 = ap2;
}

//��_owner�汾��auto_ptrȱ�ݣ����ܻ����Ұָ��--���´������
void TestAutoPtr2()
{
	my_ptr::auto_ptr<int> ap1(new int);
	if (true)
	{
		my_ptr::auto_ptr<int> ap2(ap1);
		*ap2 = 20;
	}

	//ap1��Ұָ��
	*ap1 = 10;
}

int main()
{
	//TestAutoPtr1();
	TestAutoPtr2();
	return 0;
}
#endif

