//45840 - ��Ҫ��

//����С����һ��W*H��������ӣ�������б��Ϊ0~H - 1��������б��Ϊ0~W - 1��ÿ������������Է�һ�鵰�⣬�������鵰���ŷ����þ��벻�ܵ���2��
//����������������(x1, y1), (x2, y2)��ŷ����þ���Ϊ:
//((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) ������ƽ����
//С����֪�������ԷŶ��ٿ鵰������������

#include<iostream>
using namespace std;
#include<vector>
int main()
{
	int W, H;
	while (cin >> W >> H)
	{
		char a[1000][1000] = { 0 };
		int ret = 0;
		for (int i = 0; i < W; i++)
		{
			for (int j = 0; j < H; j++)
			{
				if (a[i][j] == 0)
				{
					ret++;
					if (i + 2 < W)
					{
						a[i + 2][j] = 'N';
					}
					if (j + 2 < H)
					{
						a[i][j + 2] = 'N';
					}
				}
			}
		}
		cout << ret << endl;
	}
	return 0;
}