//69390-ɾ�������ַ�
//���������ַ������ӵ�һ�ַ�����ɾ���ڶ����ַ��������е��ַ������磬���롱They are students.���͡�aeiou������ɾ��֮��ĵ�һ���ַ�����
//�ɡ�Thy r stdnts.��

#include<iostream>
using namespace std;
#include<string>

void RemoveStr(string& s1, string& s2)
{
	char str[255] = { 0 };
	for (int i = 0; i < s2.length(); i++)
	{
		str[s2[i]]++;
	}
	for (int i = 0; i < s1.length(); i++)
	{
		if (str[s1[i]]==0)
		{
			cout << s1[i];
		}
	}
	cout << endl;
}

int main()
{
	string str1, str2;
	while (getline(cin, str1) && getline(cin, str2))
	{
		RemoveStr(str1, str2);
	}
	return 0;
}
