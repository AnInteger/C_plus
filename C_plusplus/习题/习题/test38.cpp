//36889 - ���������ַ���a, b�е�������Ӵ�
//���������ַ���a, b�е�������Ӵ������ж��������ڽ϶̴������ȳ��ֵ��Ǹ���

#include<iostream>
using namespace std;

#include<string>
int main()
{
	string a, b;
	while (cin >> a >> b)
	{
		if (a.size()>b.size())
			swap(a, b);
		string str;
		for (int i = 0; i<a.size(); i++)
		{
			for (int j = i; j<a.size(); j++)
			{
				string tmp = a.substr(i, j - i + 1);
				if (int(b.find(tmp))<0)
				{
					break;
				}
				else if (str.size()<tmp.size())
				{
					str = tmp;
				}
			}
		}
		cout << str << endl;
	}
	return 0;
}