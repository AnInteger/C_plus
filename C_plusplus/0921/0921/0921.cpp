#include<iostream>
using namespace std;

#if 0
//C������malloc�Ŀ��ٷ�ʽ
int main()
{
	int* p = (int*)malloc(sizeof(int)* 10);
	free(p);
	return 0;
}
#endif


#if 0
//new/delete   new[]/delete[]
//malloc/free
//ע�⣺һ��Ҫƥ��ʹ��
//1��new��delete���Ǻ�������C++�ṩ���µĲ�����
//2��new/new[]ֻ���������ռ����ͣ�����Ҫ�����ֽ���
//3��new����ľ��ǿռ����ͣ���˲���Ҫǿת
//4��new/new[]���Խ��г�ʼ��
//5��new�Ľ������Ҫ�п�
//6��new���뵥������Ԫ�صĿռ�----Ĭ�������new���Ŀռ��ڶ���
int main()
{
	int* p1 = new int;
	int* p2 = new int(10);
	int* p3 = new int[10];
	int* p4 = new int[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 0};

	delete p1;
	delete p2;
	delete[] p3;
	delete[] p4;
	return 0;
}
#endif



#if 0
//���û��ƥ��ʹ�ã�����ʲô�����
//�����������������͵Ŀռ䣬��������κκ����
void Test1()
{
	int* p1=(int*)malloc(sizeof(int));
	int* p2 = (int*)malloc(sizeof(int));
	delete p1;
	delete[] p2;

	int* p3 = new int;
	int* p4 = new int;
	free(p3);
	delete[] p4;

	int* p5 = new int[10];
	int* p6 = new int[10];
	free(p5);
	delete p6;
}


//�Զ�������

class Test
{
public:
	Test()
	{
		_data = 10;
		_p = new int;
		cout << "Test():" << this << endl;
	}
	~Test()
	{
		delete _p;
		cout << "~Test():" << this << endl;
	}
private:
	int _data;
	int* _p;
};

// �����Զ������ͣ�ֻҪ�漰��[ ]����Ȼ�����
// new����ù��캯��
// free ���������������-----�����е���Դ���ᱻ����


void Test2()
{
	//Test* p3 = new Test;
	//Test* p4 = new Test;
	//free(p3);
	//delete[] p4;

	Test* p1 = (Test*)malloc(sizeof(Test));
	//Test* p2 = (Test*)malloc(sizeof(Test));
	delete p1;
	//delete[] p2;

	//malloc ����ռ�ʱ������ù��캯��---�������������С��ͬ��һ���ڴ�ռ�
	//				���ܽ��ÿ��ڴ濴����һ������

	//Test* p5 = new Test[10];
	//Test* p6 = new Test[10];
	//free(p5);
	//delete p6;
}

int main()
{
	//Test1();
	Test2();
	_CrtDumpMemoryLeaks();
	return 0;
}
#endif 


#if 0
//�Զ���������ʹ��new��deleteʱ������ƥ��ʹ��[ ]
class Test
{
public:
	Test()
	{
		_data = 10;
		cout << "Test():" << this << endl;
	}
	~Test()
	{
		cout << "~Test():" << this << endl;
	}

private:
	int _data;
};

int main()
{
	Test* pt = new Test[10];
	delete[] pt;
	return 0;
}
#endif

#if 0
void* operator new(size_t size,const char* filename,const char* funName,size_t lineNo)
{
	cout << filename << "-" << funName << "-" << lineNo << size << endl;
	return malloc(size);
}

void operator delete(void* p, const char* filename, const char* funName, size_t lineNo)
{
	cout << filename << "-" << funName << "-" << lineNo << endl;
	free(p);
}

#define new new(__FILE__,__FUNCDNAME__,__LINE__)

int main()
{
	int* p = new int;
	delete p;
	return 0;
}
#endif


#if 0
//1��new------>�ܹ�������ռ����Ϣ��ӡ
//2��delete--->�ܹ����ͷſռ����Ϣ��ӡ
void* operator new(size_t size, const char* filename, const char* funName, size_t lineNo)
{
	cout << filename << "-" << funName << "-" << lineNo << "-" << size << endl;
	return malloc(size);
}

void operator delete(void* p, const char* filename, const char* funName, size_t lineNo)
{
	cout << filename << "-" << funName << "-" << lineNo << endl;
	free(p);
}

#define new new(__FILE__, __FUNCDNAME__, __LINE__)

int main()
{
	int* p = new int;
	delete p;
	return 0;
}
#endif


#if 0
class Test
{
public:
	Test(int data)
	{
		_data = 10;
		cout << "Test():" << this << endl;
	}

	~Test()
	{
		cout << "~Test():" << this << endl;
	}
private:
	int _data;
};
// placement-new
// ��λnew���ʽ�����Ѿ����ڵĿռ���ִ�й��캯��
// �﷨�� new(��ַ) Test(����)

/*
��������ռ��new������-----C++�ṩ�Ĺؼ���----ר����������ռ�
	1������void* operator new��size_t size)
	{
		//����mallocѭ������ + �ռ䲻���Ӧ�Դ�ʩ
	}

	2�����ù��캯��
	void* operator new(size_t size)��һ��������һ������²���Ҫ�Լ�����
	������Ҫ�������⹦��

	��λnew���ʽ��
	new(p)  T
	1��void* operator new(size_t size,void* where)
	{
		return where;
	}
	2��ִ�й��캯��
*/


int main()
{
	Test* pt = (Test*)malloc(sizeof(Test));
	//ֻҪ����ptָ��Ŀռ���ִ�й��캯��
	new(pt) Test(10);

	/*
	��λnew���ʽ������operator new
	void* operator new(size_t size,void* where)
	{
		return where;
	}
	*/

	//��Ϊ�ռ�����malloc���ٵģ���������ƥ��
	//delete pt;
	pt->~Test();
	free(pt);
	// ��Ҫ��ptָ��Ŀռ䵱�ɶ�����ʹ��
	return 0;
}
#endif

#if 0
class Test
{
public:
	~Test()
	{
		Test* p = new Test;
		delete p;
	}
};

int main()
{
	Test* pt = new Test;
	delete pt;
	return 0;
}
#endif

#if 0
class Object
{
public:
	static Object* GetObject(int data)
	{
		return new Object(data);
	}
	~Object()
	{

	}
	//C++11
	//1���ͷ�new�Ŀռ�
	//2����Ĭ�ϳ�Ա���������=delete��ɾ��Ĭ�ϵĿ������캯��
	Object(const Object& o) = delete;
private:
	//C++98
	//����Ĭ�Ͽ������캯��
	//Object(const Object& o);
	Object(int data)
	{}
};

int main()
{
	Object* p = Object::GetObject(10);
	delete p;


	Object o(*p);
	return 0;
}
#endif


#if 0
//64λϵͳ & ������64λ�ķ�ʽ����----ָ�����8���ֽ�

int main()
{
	cout << sizeof(int*) << endl;
	//����4G�Ŀռ�ֻ����64λϵͳ�¿���
	void* p = new char[0xfffffffful];
	cout << "new:" << p<< endl;
	return 0;
}
#endif

#if 0
//дһ��ͨ�ú����ļӷ�������--�������Ͷ����Դ���
//��������
int Add(int left, int right)
{
	return left + right;
}

double Add(double left, double right)
{
	return left + right;
}

char Add(char left, char right)
{
	return left + right;
}

int main()
{
	Add(1, 2);
	Add(1.0, 2.0);
	return 0;
}
#endif


#if 0
// �������޹�
//Add ����ģ��

template<typename T> //ģ������б�
T Add(T left, T right)
{
	cout << typeid(T).name() << endl;
	return left + right;
}

template<typename T1,typename T2> //ģ������б�
T1 Add(T1 left, T2 right)
{
	cout << typeid(T1).name() << endl;
	cout << typeid(T2).name() << endl;

	return left + right;
}

int main()
{
	// �Ժ���ģ�����ʵ����
	// �ڱ���׶Σ������������⵽��ĳ������ģ�������ʵ����
	// �ڶ�ʵ�ε����ͽ������ݣ��������ݵĽ����ȷ��ģ������б���T��ʵ������
	// ��Ϻ���ģ�����ɴ���������͵ĺ���
	// ��ʽʵ����
	Add(1, 2);  // int ,int----T==>int  ����int Add����--->Add<int>
	Add(1.0, 2.0); //double, double----T == >double  ����double Add����--->Add<double>
	Add('1', '2'); //char, char----T == >char  ����char Add����--->Add<char>
	
	Add(1, (int)2.0);//���ʵ�ε����Ͳ�ͬ����������ǿת��һ������

	//���߽�����ʾʵ����
	//��ʽʵ����---ֱ��ָ������T��ʵ������
	//�����������ܻ������ʽ����ת��
	Add<int>(1, 2.0);


	//���߶�������ģ�����
	Add(1, 2.0);

	return 0;
}
#endif

#if 0
int Add(int left, int right)
{
	return left + right;
}

template<typename T>
T Add(T left, T right)
{
	return left + right;
}

int main()
{
	Add(1, 2);
	
	//ͬ�������뺯��ģ��ͬʱ���ڣ�����ʹͬ������
	//�Ժ���ģ�������ʾʵ����

	Add<>(1, 2);

	Add<int>(1, 2);
	return 0;
}
#endif


#if 0
int Add(int left, int right)
{
	return left + right;
}

template<typename T1,typename T2>
T1 Add(T1 left, T2 right)
{
	return left + right;
}

int main()
{
	//ͬ�������뺯��ģ��ͬʱ����
	//���ģ����Բ���һ�����и���ƥ��ĺ����� ��ô��ѡ��ģ��
	Add(1, 2);
	Add(1.0, 2);
}
#endif


