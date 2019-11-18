//45844 --�������򷽷�

//������n���ַ����ַ��������������ַ������ȶ��ǲ�ͬ�ġ��������ѧϰ���������ַ��������򷽷��� 1.�����ַ������ֵ����������磺
//"car" < "carriage" < "cats" < "doggies < "koala"
//2.�����ַ����ĳ����������磺
//"car" < "cats" < "koala" < "doggies" < "carriage"
//������֪���Լ�����Щ�ַ�������˳���Ƿ��������������򷽷�������Ҫæ�ų���Ҷ��������Ҫ������æ��֤��
//�����Щ�ַ����Ǹ����ֵ������ж����Ǹ��ݳ����������"lexicographically",
//
//������ݳ������ж������ֵ����������"lengths",
//
//������ַ�ʽ���������"both"���������"none"
#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include<string.h>
void IsSortString(vector<string>& vs)
{
	int size = vs.size();
	int flag1 = 0,flag2=0;
	for (int i = 0; i < size-1; i++)
	{
		if (strcmp(vs[i].c_str(), vs[i + 1].c_str()) <= 0)
		{
			flag1++;
		}
		if (vs[i].length() <= vs[i + 1].length())
		{
			flag2++;
		}
	}
	if (flag1==size-1&&flag2==size-1)
	{
		cout << "both" << endl;
	}
	else if (flag1==size-1)
	{
		cout << "lexicographically" << endl;
	}
	else if (flag2==size-1)
	{
		cout << "lengths" << endl;
	}
	else
	{
		cout << "none" << endl;
	}
}
int main()
{
	vector<string> vs;
	string temp;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		vs.push_back(temp);
	}
	IsSortString(vs);
	return 0;
}