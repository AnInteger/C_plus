//45842 - ͳ�ƻ���
//�����Ĵ�����һ�������ͷ�����һ�����ַ��������硰level�����ߡ�noon���ȵȾ��ǻ��Ĵ��������ǳ�ϲ������ӵ�жԳ����Ļ��Ĵ������յ�ʱ�����õ���������ֱ����ַ���A���ַ���B���������ǳ�������û�а취���ַ���B�����ַ���Aʹ�������ַ�����һ�����Ĵ�������ܻ��������󣬰�����Ѱ���ж����ֲ���취����ʹ�´���һ�����Ĵ�������ַ���B�����λ�ò�ͬ�Ϳ���Ϊ��һ���İ취��
//���磺
//A = ��aba����B = ��b����������4�ְ�B����A�İ취��
//* ��A�ĵ�һ����ĸ֮ǰ: "baba" ���ǻ���
//* �ڵ�һ����ĸ��a��֮�� : "abba" �ǻ���
//* ����ĸ��b��֮�� : "abba" �ǻ���
//* �ڵڶ�����ĸ'a'֮�� "abab" ���ǻ���
//�������������Ĵ�Ϊ2
#include<iostream>
using namespace std;
#include<string>

bool IsRever(string& s)
{
	for (int i = 0, j = s.length()-1; i<j; i++,j--)
	{
		if (s[i] != s[j])
		{
			return false;
		}
	}
	return true;
}

int main()
{
	string s1, s2;
	int ret = 0;
	while (getline(cin, s1))
	{
		getline(cin, s2);
		for (int i = 0; i<=s1.length(); i++)
		{
			string tmp=s1;
			tmp.insert(i, s2);
			if (IsRever(tmp))
			{
				ret++;
			}
		}
		cout << ret << endl;
	}
}