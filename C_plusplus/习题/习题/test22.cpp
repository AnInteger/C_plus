//36910 - ���������bit��
//����: ��һ��byte���ֶ�Ӧ�Ķ�����������1�����������������3�Ķ�����Ϊ00000011���������2��1
//
//���� : һ��byte�͵�����
//
// ��� : ��
//
//���� : ��Ӧ�Ķ�����������1�����������


#include<iostream>
using namespace std;
int main()
{
	int a;
	
	while (cin >> a)
	{
		int sum = 0;
		int count = 0;
		for (int i = a; i; i /= 2)
		{
			if (i % 2 == 1)
			{
				sum++;
			}
			else
			{
				sum = 0;
			}
			if (sum > count)
			{
				count = sum;
			}
		}
		cout << count << endl;

	}
	return 0;
}