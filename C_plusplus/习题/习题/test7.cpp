//�����ǹ�
//A, B, C�������Ǻ�����, ÿ�������ﶼ��һЩ�ǹ�, ���ǲ�֪������ÿ�������Ͼ����ж��ٸ��ǹ�, ��������֪�����µ���Ϣ��
//A - B, B - C, A + B, B + C.���ĸ���ֵ.ÿ����ĸ����ÿ������ӵ�е��ǹ���.
//������Ҫͨ�����ĸ���ֵ�����ÿ���������ж��ٸ��ǹ�, ��A, B, C��
//���ﱣ֤���ֻ��һ������A, B, C������������������
#include<iostream>
using namespace std;

void HowMuchSweety(int a, int b, int c ,int d)
{
	int A = (a + b) / 2;
	int B1 = (b + d) / 2;
	int B2 = (c - a) / 2;
	int C = (d - b) / 2;
	if (B1 != B2)
	{
		cout << "No" << endl;
	}
	else
	{
		cout << A << " " << B1 << " " << C << endl;
	}
}

int main()
{
	int a, b, c, d;
	while (cin >> a >> b >> c >> d)
	{
		HowMuchSweety(a, b, c, d);
	}
	return 0;
}