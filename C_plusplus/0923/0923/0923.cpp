#include<iostream>
using namespace std;

#include<string>

void TestString1()
{
	string s1;
	string s2("hello");//��strΪ��ֵ (��������),
	string s3(10, '$');//��lengthΪ���ȵ�ch�Ŀ�������length��ch��
	string s4(s3);//��һ�����󿽱���ֵ����һ������
	
	cin >> s1;
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
}

int main()
{
	return 0;
}