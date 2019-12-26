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

#if 0
//���飺ʲô����¶���Ҫʹ��auto_ptr

#include<memory>

int main()
{
	auto_ptr<int> ap1(new int);
	auto_ptr<int> ap2(ap1);
	return 0;
}
#endif

//C++11:auto_ptr---->��������Դת��ʵ��
//�ṩ�����׵�����ָ��

//����ָ��ԭ��RAII(�Զ��ͷ���Դ) + operator*()/operator->()(����ָ�����Ƶ���Ϊ) + �ṩ���ǳ������ʽ

//ǳ���������ԭ��Ĭ�Ͽ������캯�� �� Ĭ�ϵĸ�ֵ���������

// unique_ptr
//��Դ��������Դ��ռ

#if 0
#include<memory>

int main()
{
	unique_ptr<int> up1(new int);
	//unique_ptr<int> up2(up1);
	
	unique_ptr<int> up3(new int);
	//up3 = up1;
	return 0;
}
#endif


#if 0
//���ǳ�����ķ�ʽ����Դ��ռ(ֻ��һ������ʹ�ã����ܹ���)-->ʵ�֣���ֹ���ù��쿽���͸�ֵ���������
namespace my_ptr
{
	template<class T>
	class unique_ptr
	{
	public:
		//RAII
		unique_ptr(T* ptr=nullptr)
			:_ptr(ptr)
		{}

		~unique_ptr()
		{
			if (_ptr)
			{
				delete _ptr;//�ͷ���Դ�ķ�ʽ�̶��ˣ�ֻ�ܹ���new����Դ�����ܴ����������͵���Դ
				_ptr = nullptr;
			}
		}

		//����ָ�����Ƶ���Ϊ
		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}
		//���ǳ��������ֹ���ÿ������캯���͸�ֵ���������
		
		//C++98
		/*
	private://���������Ȩ��һ�����ó�Ϊprivate��ԭ��Ϊ�˷�ֹ�û��Լ������ⶨ��
		unique_ptr(const unique_ptr<T>& up);
		unique_ptr<T>& operator=(const unique_ptr<T>&);
		*/

		//C++11 ��ֹ���ÿ�������͸�ֵ���������
		unique_ptr(const unique_ptr<T>&) = delete;
		unique_ptr<T>& operator=(const unique_ptr<T>&) = delete;
		//1���ͷ�new�Ŀռ�
		//2��Ĭ�ϳ�Ա����=delete�����߱�������ɾ����Ĭ�ϳ�Ա����

	private:
		T* _ptr;
	};
	//�û����ⲿʵ��
	/*template<class T>
	unique_ptr<T>::unique_ptr(const unique_ptr<T>& up)
	{}*/
}


void TestUniquePtr()
{
	my_ptr::unique_ptr<int> up1(new int);
	//my_ptr::unique_ptr<int> up2(up1);

	my_ptr::unique_ptr<int>up3(new int);
	//up3 = up1;
}

#endif

#if 0
#include<memory>
#include<malloc.h>

int main()
{
	unique_ptr<int> up1(new int);
	unique_ptr<int> up2((int*)malloc(sizeof(int)));
	return 0;
}

#endif


#if 0
template<class T>
class DFDef
{
public:
	void operator()(T*& p)
	{
		if (p)
		{
			delete p;
			p = nullptr;
		}
	}
};

template<class T>
class Free
{
public:
	void operator()(T*& p)
	{
		if (p)
		{
			free(p);
			p = nullptr;
		}
	}
};


class FClose
{
public:
	void operator()(FILE*& p)
	{
		if (p)
		{
			fclose(p);
			p = nullptr;
		}
	}
};

namespace my_ptr
{
	template<class T,class DF=DFDef<T>>
	class unique_ptr
	{
	public:
		unique_ptr(T* ptr=nullptr)
			:_ptr(ptr)
		{}

		~unique_ptr()
		{
			if (_ptr)
			{
				DF df;
				df(_ptr);
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

		unique_ptr(const unique_ptr<T>&) = delete;
		unique_ptr<T>& operator=(const unique_ptr<T>&) = delete;

	private:
		T* _ptr;
	};
}


void TestUniquePtr()
{
	my_ptr::unique_ptr<int> up1(new int);
	my_ptr::unique_ptr<int, Free<int>> up2((int*)malloc(sizeof(int)));
	my_ptr::unique_ptr<FILE, FClose> up3(fopen("1.txt", "w"));
}

int main()
{
	TestUniquePtr();
	return 0;
}

#endif

namespace my_ptr
{
	template<class T>
	class shared_ptr
	{
	public:
		shared_ptr(T* ptr=nullptr)
			:_ptr(ptr)
			,_pCount(nullptr)
		{
			if (_ptr)
			{
				_pCount = new int(1);
			}
		}

		~shared_ptr()
		{
			if (_ptr && 0 == --*_pCount)
			{
				delete _ptr;
				delete _pCount;
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

		shared_ptr(const shared_ptr<T>& sp)
			:_ptr(sp._ptr)
			,_pCount(sp._pCount)
		{
			if (_ptr)
			{
				++*_pCount;
			}
		}

		shared_ptr<T>& operator=(const shared_ptr<T>& sp)
		{
			if (this != &sp)
			{
				//1�������Դ�Ͽ���ϵ
				//this���ڲ������Լ�����Դ��Ҫ��sp��������Դ
				if (_ptr && 0 == --*_pCount)
				{
					//��ǰ���������һ��ʹ����Դ�Ķ���
					delete _ptr;
					delete _pCount;
				}
				//2����sp������Դ������
				_ptr = sp._ptr;
				_pCount = sp._pCount;
				if (_ptr)
				{
					++*_pCount;
				}
			}
			return *this;
		}

		int use_count()
		{
			return *_pCount;
		}

	private:
		T* _ptr;
		int* _pCount;
	};
}

void TestShardPtr()
{
	my_ptr::shared_ptr<int> sp1(new int);
	cout << sp1.use_count() << endl;

	my_ptr::shared_ptr<int>sp2(sp1);
	cout << sp1.use_count() << endl;
	cout << sp2.use_count() << endl;

	my_ptr::shared_ptr<int> sp3(new int);
	cout << sp3.use_count() << endl;

	my_ptr::shared_ptr<int> sp4(sp3);
	cout << sp3.use_count() << endl;
	cout << sp4.use_count() << endl;

	sp3 = sp2;
	cout << sp2.use_count() << endl;
	cout << sp3.use_count() << endl;

	sp4 = sp2;
	cout << sp2.use_count() << endl;
	cout << sp4.use_count() << endl;
}

int main()
{
	TestShardPtr();
	return 0;
}