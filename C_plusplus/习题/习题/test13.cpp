//45846 --Fibonacci����
//ibonacci��������������ģ�
//F[0] = 0
//F[1] = 1
//for each i �� 2: F[i] = F[i - 1] + F[i - 2]
//��ˣ�Fibonacci���о����磺0, 1, 1, 2, 3, 5, 8, 13, ...��
//��Fibonacci�����е������ǳ�ΪFibonacci��������һ��N�����������Ϊһ��Fibonacci����
//ÿһ������԰ѵ�ǰ����X��ΪX - 1����X + 1�����ڸ���һ����N��������Ҫ���ٲ����Ա�ΪFibonacci����


#include<iostream>
using namespace std;
#include<algorithm>
int main()
{
	int N;
	int f, l = 0, r = 0,f1 = 0, f2 = 1;
	while (cin >> N)
	{
		while (1)
		{
			f = f1 + f2;
			f1 = f2;
			f2 = f;
			if (f < N)
				l = N - f;
			else
			{
				r = f - N;
				break;
			}	
		}
		cout << min(l, r) << endl;
	}
	return 0;
}