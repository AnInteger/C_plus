//�����������С�ţţ��������������Ϊһ��������һ��������������, ��������������Ƿǵ������߷ǵݼ�����ġ�ţţ��һ������Ϊn����������A, ��������һ����
//���ǰ�����A��Ϊ���ɶ�����������, ţţ��֪�������ٿ��԰���������Ϊ��������������.
//��������ʾ, ţţ���԰�����A����Ϊ[1, 2, 3]��[2, 2, 1]��������������, ������Ҫ����Ϊ2������������, �������2

#include<iostream>
using namespace std;

bool IfChangNow(int pre, int cur, int next)
{
	if ((cur > pre&&cur > next) || (cur < pre&&cur < next))
	{
		return true;
	}
	return false;
}

int main()
{
	int n, arr[100000];
	while (cin >> n)
	{
		int num = 1;
		int pre = 0;
		if (n < 3)
		{
			cout << num << endl;
		}
		for (int i = 0; i<n; i++)
		{
			cin >> arr[i];
		}
		for (int i = 1; i < n - 1; i++)
		{
			if (arr[i] == arr[i + 1])
			{
				continue;
			}
			else
			{
				if (IfChangNow(arr[pre], arr[i], arr[i + 1]))
				{
					num++;
					pre = ++i;
				}
			}
		}
		cout << num << endl;
	}
	return 0;
}