#include<iostream>
using namespace std;

#if 0
int& TestFunc(int& ra)
{
	return ra;
}

int main()
{
	int a = 10;
	int& rra = TestFunc(a);
	return 0;
}

//��������������ֵ�������ܲ�����ջ�ϵĿռ�
#endif

#if 0
//����Ч�ʱȽϣ���ֵ����(ֵ��Ҫ������������ַ�ʹ�����Ч�ʼ���һ��
#include<time.h>
struct A
{
	int a[10000];
};
void TestFunc1(A a)
{}

void TestFunc2(A* a)
{}

void TestFunc3(A& a)
{}



void  TestRefAndValue()
{
	A a;
	// ��ֵ��Ϊ��������
	size_t begin1 = clock();
	for (size_t i = 0; i < 10000; i++)
	{
		TestFunc1(a);
	}
	size_t end1 = clock();

	//�Ե�ַ��Ϊ��������
	size_t begin2 = clock();
	for (size_t i = 0; i < 10000; i++)
	{
		TestFunc2(&a);
	}
	size_t end2 = clock();

	//��������Ϊ��������
	size_t begin3 = clock();
	for (size_t i = 0; i < 10000; i++)
	{
		TestFunc3(a);
	}
	size_t end3= clock();

	//�ֱ���������������н������ʱ��
	cout << "TestFunc1(int)-time:" << end1 - begin1 << endl;
	cout << "TestFunc2(int*)-time:" << end2 - begin2 << endl;
	cout << "TestFunc3(int&)-time:" << end3 - begin3 << endl;
}

//���ж�Σ����ֵ�������ڴ��η����Ч������
int main()
{
	for (int i = 0; i < 10; i++)
	{
		TestRefAndValue();
	}
	return 0;
}
#endif

#if 0
//���ú�ָ����ʲô����
//�ڵײ���õ�ԭ������һģһ���ģ��ڱ��ĵ������в�������
void Swap(int* pa, int* pb)
{
	int temp = *pa;
	*pa = *pb;
	*pb = temp;
}

void Swap(int& ra, int& rb)
{
	int temp = ra;
	ra = rb;
	rb = temp;
}

int main()
{
	int a = 10;
	int b = 20;

	int* pa = &a;
	*pa = 20;

	int& ra = a;
	ra = 20;

	Swap(&a, &b);
	Swap(a, b);
	return 0;//�������ڵײ��ʵ�ʲ�����Swap(&a,&b)
}
#endif


#if 0
int main()
{
	int* pa;

	int a = 10;
	//int& ra;
	//���ñ����ʼ������ָ������Ҫ
	//û��NULL���ã�����NULLָ��
	int b = 20;

	pa = &a;
	pa = &b;
	//ͬһ��ָ�����ָ��ͬ�����ĵ�ַ
	//һ������ֻ������һ��ʵ��
	
	int& ra = a;
	ra++;
	//�����Լ������õ�ʵ���һ
	//ָ���Լ�����ָ��ƫ����ָ�����͵Ĵ�С

	char c = 'c';
	char* pc = &c;
	char& rc = c;
	cout << sizeof(pc) << endl;
	cout << sizeof(rc) << endl;
	//���ô�СΪ�������͵Ĵ�С
	//ָ���СΪʼ���ǵ�ַ�ռ���ռ�ֽڸ���(32λƽ̨��Ϊ4���ֽڣ�
	
	//ָ����Ҫ��ʽ�����ã��������Ǳ������Լ�����

	int** p;
	//�ж༶ָ�뵫��û�ж༶����

	//��ֵ����
	const int&& r = 10;
	return 0;
}
#endif

#if 0
//�����ܷ�ͨ�����룿�ܷ��������У����ܻ����ǿ����
void Swap(int& ra, int& rb)
{
	int temp = ra;
	ra = rb;
	rb = temp;
}

int main()
{
	int a = 10;
	int* pb = NULL;

	Swap(a, *pb);
	return 0;
}
//�������ͨ�����룬�������������У������ں�����ra=rb��ֵʱ����
//ԭ����Ϊ�����ǿ�ָ������int& rb=*pb���ڵײ�ʵ���У������ǽ�*rb�ĵ�ַ�����˺���
//�ʺ�������û�����⣬�����ڸ�ֵʱ��ָͬ��һ�������ú�ΪNULL���ʸ�ֵ�޷�ʵ��
#endif

#if 0
//C++�У���const���εı���----->����
//���к��滻������---->�ڱ���׶ν����滻--->��������ͼ��
int main()
{
	const int a = 10;
	
	int* pa = (int*)&a;
	*pa = 100;

	printf("%d",/*a*/10);
	printf("%d", *pa);
	return 0;
}
#endif


#if 0
//�꺯��ȱ�ݣ�������  ��Ԥ����׶��滻������������ͼ��   �����Ե���
#define MAX(a,b) ((a)>(b)?(a):(b))

int main()
{
	int a = 10;
	int b = 20;

	cout << MAX(++b, a);//((a)>(++b)?(a):(++b))
	return 0;
}
#endif

#if 0
inline int Add(int left, int right)//inline ���������Ĺؼ���
{
	return left + right;
}

int main()
{
	int a = 10;
	int b = 20;
	int c = Add(a, b);
	//�����������Ż��������õĹ���ʹ�������еĺ�������������ȫ�滻
	cout << c << endl;
	return 0;
}
#endif


#if 0
//#include"a.h"
//�������������������Ͷ�����룬����ᵼ�����Ӵ���
inline int Add(int left, int right)
{
	return left + right;
}

int main()
{
	Add(1, 2);
	return 0;
}

#endif

#if 0
//�������ڱ���׶Σ������ṩ�ĳ�ʼ�����ʽʵ�����ͣ���ȷ������������
int main()
{
	auto a = 10;
	auto b = 12.34;
	//auto c��
	//auto �����ʼ�������������ݳ�ԭ�����ͣ�������ͻ
	cout << typeid(a).name() << endl;
	cout << typeid(b).name() << endl;
	//typeid().name(),�����ڲ鿴������
	return 0;
}
#endif


#if 0
//auto���������
#include<map>
#include<string>

int main()
{
	std::map<std::string, std::string> m{ { "apple", "ƻ��" }, { "peach", "����" } };
	
	//C++98�﷨
	//std::map<std::string, std::string>::iterator it = m.begin();

	auto it = m.begin();
	while (it != m.end())
	{
		cout << it->first << "-->" << it->second << endl;
		it++;
	}
	cout << endl;
	return 0;
}
#endif

#if 0
int main()
{
	int a = 10;
	auto pa1 = &a;
	auto* pa2 = &a;
	//��ʱ���嶼��ָ������pa1��autoΪint*��pa2��autoΪint

	cout << typeid(pa1).name() << endl;
	cout << typeid(pa2).name() << endl;
	
	auto ra = a;
	ra = 20;
	//��������ʹ����auto&

	auto& rra = a;
	rra = 30;

	return 0;
}
#endif

#if 0
int main()
{
	//auto a = 1, b = 2.0, c = 3;
	//����һ�ж�����������ͱ�����ͬ
	//���������б��У���auto������ʼ���Ƶ�Ϊͬһ����
	return 0;
}
#endif


#if 0

//void TestFunc(auto a)
//{}
//auto ������Ϊ�����Ĳ�������

int main()
{
	int arr1[10] = { 1, 2, 3 };
	//auto arr2[] = { 1, 2, 3 };
	//�����Ԫ�����Ͳ����ǰ�����auto��������
	return 0;
}
#endif


#if 0
int main()
{
	//[array, array + sizeof(array) / sizeof(array[0])]
	//ԭѭ��
	/*int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;*/

	//��Χforѭ��
	//auto ������ѭ��������
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	for (auto& e : array)
		e *= 2;
	//��auto& �൱�����������е�ÿ��Ԫ�شӶ�ʵ�ָ�����ֵ
	for (auto e : array)
		cout << e << " ";
	cout << endl;

	return 0;
}
#endif

#if 0
//void TestFunc(int* array)
//{
//	for (auto e : array)
//		cout << e << " ";
//}
//auto�޷��ں����ڲ��������飬��Ϊ���鴫��ֻ���׵�ַ
int main()
{
	int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
	TestFunc(array);
	return 0;
}

#endif