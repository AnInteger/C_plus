//36915-��·������

//���дһ�����������������Ӻ�����������n x m�����̸��ӣ�nΪ����ĸ�������mΪ����ĸ�������
//���Ÿ��Ա�Ե�ߴ����Ͻ��ߵ����½ǣ��ܹ��ж������߷���Ҫ�����߻�ͷ·��
//����ֻ�����Һ������ߣ���������������ߡ�

#include<iostream>
using namespace std;
int retSum(int n, int m)
{
	if (n == 1)
	{
		return m + 1;
	}
	else if (m == 1)
	{
		return n + 1;
	}
	else
	{
		return retSum(n, m - 1) + retSum(n, m - 1);
	}
}
int main()
{
	int n = 0, m = 0;
	while (cin >> n >> m)
	{
		cout << retSum(n, m) << endl;
	}
	return 0;
}