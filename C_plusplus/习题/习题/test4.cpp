//69389-�����ַ���
//��һ�仰�ĵ��ʽ��е��ã���㲻���á����� I like beijing.�����������Ϊ��beijing.like I


#include<iostream>
using namespace std;
#include<string>

int main()
{
	string str;
	while (getline(cin, str))
	{
		for (int i = str.length() - 1; i >= 0; i--)
		{
			if (str[i] == ' ')
			{
				string str_r = str.substr(i + 1);
				cout << str_r << " ";
				str.resize(i);
			}
		}
		cout << str;
	}
	return 0;
}
