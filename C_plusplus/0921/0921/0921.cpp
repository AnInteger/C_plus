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