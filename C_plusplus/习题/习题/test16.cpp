//36932 - ����С������

////������A��������B ����С��������ָ �ܱ�A��B��������С��������ֵ�����һ���㷨��������A��B����С��������
//
//#include<iostream>
//using namespace std;
//int main()
//{
//	int a, b;
//	while (cin >> a >> b)
//	{
//		int temp = 0;
//		if (a < b)
//		{
//			int temp = a;
//			a = b;
//			b = temp;
//		}
//		if (a%b == 0)
//		{
//			cout << a << endl;
//			return 0;
//		}
//		else
//		{
//			temp = a;
//			while (a%b != 0)
//			{
//				a = a + temp;
//			}
//		}
//		cout << a << endl;
//		return 0;
//	}
//}



#include<iostream>
using namespace std;
int gcd(int a, int b)
{
	int r = 0;
	while (r = a%b)
	{
		a = b;
		b = r;
	}
	return b;
}
int main()
{
	int a, b;
	while (cin >> a >> b)
	{
		cout << a*b / gcd(a, b) << endl;
	}
	return 0;
}