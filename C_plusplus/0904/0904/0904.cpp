#include<stdio.h>

#if 0
//���������ռ�Ķ��巽ʽ

//һ�������ռ���൱����һ��������

int a = 0;//����ȫ�ֱ���

namespace N1
{
	int a = 10;
	int b = 20;

	int Add(int left, int right)
	{
		return left + right;
	}
}

//�����ռ����Ƕ��
namespace N2
{
	int a = 10;
	int b = 20;

	int Sub(int left, int right)
	{
		return left - right;
	}

	namespace N3
	{
		int a = 10;
		int b = 20;

		int Mul(int left, int right)
		{
			return left*right;
		}
	}
}

//�����ռ��г�Ա�ķ��ʷ�ʽ
//1.����ǰ���������޶����Լ������ռ������
//2.using N1::Add;  Add�ͳ�Ϊ��ǰ�ļ��е�һ��ȫ�ֱ���
//ʹ��usingʱ��Ӧ���⵱ǰ�ı������뱾�����ж����ȫ�ֱ������ظ�

using N1::Add;

int main()
{
	int a = 30;
	printf("%d\n", a);
	//�������Ϊmain�����е�a��ֵ������ͽ�ԭ��
	printf("%d\n", ::a);
	//�������Ϊ0904.cpp�ж����ȫ�ֱ���
	printf("%d\n", N1::a);
	//�������Ϊ�����ռ�N1�е�a��ֵ
	printf("%d\n", N1::Add(10, 20));
	//�������Ϊ�����ռ�N1�е�Add����
	printf("%d\n",Add(10, 20));
	//����ʹ��using֮��Add�Լ�Ϊȫ�ֱ�����ֱ�ӵ���


	return 0;
}

#endif


#if 0
//���һ�������а��������ͬ���Ƶ������ռ䣬����Ὣ��ϲ���Ϊһ��
namespace N1
{
	int a = 10;
	int b = 20;

	int Add(int left, int right)
	{
		return left + right;
	}
}

namespace N1
{
	int c = 30;
	int d = 40;
}
//������ͬ���������ռ䶨��ʱ�����ڲ������������ʼ��ֵ�����������ռ��б����ظ�

//��������ռ��еĳ�Ա�ڵ�ǰ�ļ���ʹ�ý϶�
using namespace N1;
//ʹ�����ַ�ʽ��ʹ�����ռ��е����б�������Ϊ���ļ��е�ȫ�ֱ���
int main()
{
	int a = 30;
	printf("%d\n", N1::a);
	printf("%d\n", N1::b);
	printf("%d\n", N1::Add(10,20));
	//���Խ����ͬ
	printf("%d\n", a);
	printf("%d\n", ::a);
	//�����ļ��У����main���������еı�����ʹ��using֮��������ռ��еı����ظ�������Ϊ��ȫ�ֱ�����Ե����::a�������
	printf("%d\n", b);

	return 0;
}

#endif



//#include<iostream.h>  ����c++��ͷ�ļ���û��.h��׺

#include<iostream>
using namespace std;//c++�н����ֹؼ��ִ���������ռ�std�У�����Ҫʹ�������ռ�std���ſ���ʹiostream��Ч

#if 0
int main()
{
	int a;
	double d;
	cin >> a;//��������ͨ������̨���뽫������a
	cin >> d;

	cout << a << " " << d << endl;
	//�������ͨ����������ֵ���������̨
	cin >> a >> d;
	cout << a << " " << d << endl;

	cout << 10 << "\n";
	//"\n"=="endl",c++�мȿ���ʹ��endlҲ��ʹ��"\n",��ȫ֧��c�﷨
	cout << 12.34 << endl;
	cout << 10 << " " << 12.34 << endl;
	cout << "hello world" << endl;
	//cout �����Զ��ж��û�����ı���������
	return 0;
}
#endif


#if 0
//ȱʡ����
void TestFunc(int a = 10)
{
	cout << a << endl;
}

int main()
{
	TestFunc();//10
	TestFunc(20);//20
	//c++֧��ȱʡ������ֻ��Ҫ�������������ʱ����ʼĬ��ֵ
	return 0;
}

#endif

#if 0
//ȱʡ��������
//ȫȱʡ����---���в���������Ĭ��ֵ
void TestFunc(int a = 1, int b = 2, int c = 3)
{
	cout << a << " " << b << " " << c << " " << endl;
}

int main()
{
	TestFunc();
	TestFunc(10);
	TestFunc(10, 20);
	TestFunc(10, 20, 30);
	//�������������θ��������Ĳ����б�
	return 0;
}

#endif


#if 0
//��ȱʡ������ֻ�в��ֲ�������Ĭ��ֵ������ֻ�ܴ����������θ���
//void TestFunc(int a=1, int b = 2, int c )����
void TestFunc(int a, int b = 2, int c = 3)
{
	cout << a << " " << b << " " << c << endl;
}

int main()
{
	TestFunc(10);
	TestFunc(10, 20);
	TestFunc(10, 20, 30);
	return 0;
}
#endif

#if 0
int g_a = 10;
void TestFunc(int a = g_a);
void TestFunc(int a)
{
	cout << a << endl;
}
//����������Ĭ�ϲ���ʱ�����������������ã�Ҳ�����ڶ���������
//ע�⣺�����Ͷ��岻��ͬʱ����Ĭ�ϲ���
int main()
{
	TestFunc();
	return 0;
}

#endif