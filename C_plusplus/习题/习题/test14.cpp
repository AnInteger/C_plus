//36939 - �Ϸ����������ж�

//����һ���ַ����������һ���㷨���ж����Ƿ�Ϊһ���Ϸ������Ŵ���
//
//����һ���ַ���A�����ĳ���n���뷵��һ��boolֵ�������Ƿ�Ϊһ���Ϸ������Ŵ���
#include<iostream>
using namespace std;
#include<string>
#include<stack>
class Parenthesis {
public:
	bool chkParenthesis(string A, int n) {
		stack<char> sc;
		for (auto ele : A)
		{
			switch (ele)
			{
			case '(':
				sc.push(ele);
				break;
			case ')':
			{
				if (sc.empty() || sc.top() != '(')
				{
					return false;
				}

				else
				{
					sc.pop();
				}
			}
				break;
			default:
				return false;
			}
		}
		return true;
	}
};