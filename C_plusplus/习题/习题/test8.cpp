//����ת��
//����һ��ʮ������M���Լ���Ҫת���Ľ�����N����ʮ������Mת��ΪN������


#include<iostream>
using namespace std;
#include<string>
int main()
{
	string str = "0123456789ABCDEF";
	string s = "";
	int a, n;
	while (cin >> a >> n)
	{
		if (a < 0)
		{
			a = -a;
			cout << '-';
		}
		for (int i = a; i; i /= n)
		{
			s = str[i%n] + s;
		}
		cout << s << endl;
	}
	return 0;
}