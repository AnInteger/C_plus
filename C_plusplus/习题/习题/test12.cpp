//��һ���ַ���ת����һ��������Ҫ����ʹ���ַ���ת�������Ŀ⺯���� 
//��ֵΪ0�����ַ�������һ���Ϸ�����ֵ�򷵻�0
#include<string>
#include<iostream>
#include<math.h>
using namespace std;
class Solution {
public:
	int StrToInt(string& str)
	{
		long ret = 0;
		int flag = 1;
		int i = 0;
		if (str[0] == '0')
			return 0;
		if (str[0] == '-')
		{
			flag = -1;
			i = 1;
		}
		if (str[0] == '+')
		{
			i = 1;
		}
		for (i; i < str.length(); i++)
		{
			if (str[i] >= '0'&&str[i] <= '9')
			{
				ret = ret * 10 + (str[i] - '0');
			}
			else
			{
				return 0;
			}
		}
		ret = ret*flag;
		if (ret >= pow(-2, 31) && ret < pow(2, 31))
		{
			return ret;
		}
		return 0;
	}
};
