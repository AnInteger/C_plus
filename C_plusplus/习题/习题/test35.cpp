//36861 - ͳ��ÿ�������ӵ�����

//��һֻ���ӣ��ӳ������3������ÿ���¶���һֻ���ӣ�С���ӳ����������º�ÿ��������һֻ���ӣ�
//�������Ӷ���������ÿ���µ���������Ϊ���٣�


#include<iostream>
using namespace std;
int main()
{
	int month = 0;

	while (cin >> month)
	{
		int first = 1;
		int second = 1;
		int result = 1;
		for (int i = 3; i <= month; i++)
		{
			result = first + second;
			first = second;
			second = result;
		}
		cout << result << endl;
	}
	return 0;
}