
//36884 - �������һ��ż����ӽ�����������
//����һ��ż��������2����������2��������ɣ����ż����2�������кܶ��������
//����ĿҪ��������ָ��ż��������������ֵ��С��������


#include<iostream>
using namespace std;
#include<algorithm>
bool IsPir(int n)
{
	int tmp = sqrt(n);
	for (int i = 2; i <= tmp; i++)
	{
		if (n%i == 0)
		{
			return false;
		}
	}
	return true;
}
int main()
{
	int n;
	while (cin >> n)
	{
		int k1 = n / 2;
		int i = 0;
		for (i = k1; i>0; i--)
		{
			if (IsPir(i) && IsPir(n - i))
			{
				break;
			}
		}
		cout << i << endl << n - i << endl;
	}
	return 0;
}